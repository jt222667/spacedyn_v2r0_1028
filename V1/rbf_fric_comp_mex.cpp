// rbf_fric_comp_mex.cpp
// MEX: [tau, hat_F] = rbf_fric_comp_mex(qr,dqr,e,de,M,C,G,F,Kp,Kd)
#include "mex.h"
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

// persistent-like globals
static bool initialized = false;
static int HidLayNum = 50;
static double b_i = 0.5;        // Gaussian width (in normalized input space)
static double gamma_W = 100.0;  // learning rate
static double S_out = 50.0;     // output scale to map network output to N*m
static double k_s = 5.0;        // small robustness torque (N*m)
static double phi = 0.01;       // boundary layer for sat
static double vmax = 5.0;       // max velocity for normalization (rad/s)
static double dt = 0.001;       // sampling time (s)
static double W_max = 200.0;    // weight clip limit

static std::vector<std::vector<double>> c_i;    // centers [inDim x HidLayNum]
static std::vector<std::vector<double>> hat_W;  // weights [HidLayNum x nq]
static int inDim_global = 0;
static int nq_global = 0;

inline double sat(double v) {
    if (v > 1.0) return 1.0;
    if (v < -1.0) return -1.0;
    return v;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 10) mexErrMsgTxt("Usage: [tau, hat_F] = rbf_fric_comp_mex(qr,dqr,e,de,M,C,G,F,Kp,Kd)");

    // parse inputs
    double *qr  = mxGetPr(prhs[0]);
    double *dqr = mxGetPr(prhs[1]);
    double *e   = mxGetPr(prhs[2]);
    double *de  = mxGetPr(prhs[3]);
    double *M   = mxGetPr(prhs[4]); // nq x nq (column-major)
    double *C   = mxGetPr(prhs[5]);
    double *G   = mxGetPr(prhs[6]);
    double *F   = mxGetPr(prhs[7]);
    double *Kp  = mxGetPr(prhs[8]);
    double *Kd  = mxGetPr(prhs[9]);

    mwSize nq = mxGetM(prhs[0]);
    int nq_i = (int)nq;
    int inDim = nq_i; // only using velocity as input

    // init persistent data on first call
    if (!initialized) {
        inDim_global = inDim;
        nq_global = nq_i;
        // parameters (you can change)
        HidLayNum = 50;
        b_i = 0.3;
        gamma_W = 80.0;
        S_out = 50.0;
        k_s = 2.0;
        phi = 0.01;
        vmax = 5.0;
        dt = 0.001;
        W_max = 500.0;

        // init centers uniformly in [-1,1] for normalized velocity space
        std::mt19937 gen(0);
        std::uniform_real_distribution<double> dist(-1.0,1.0);
        c_i.assign(inDim_global, std::vector<double>(HidLayNum));
        for (int i=0;i<inDim_global;i++)
            for (int j=0;j<HidLayNum;j++)
                c_i[i][j] = dist(gen);

        // init weights small
        hat_W.assign(HidLayNum, std::vector<double>(nq_global, 0.01));
        initialized = true;
    }

    // build normalized input x_in (inDim x 1)
    std::vector<double> x_in(inDim_global);
    for (int i=0;i<inDim_global;i++) {
        double val = dqr[i] / vmax;
        if (val > 1.0) val = 1.0;
        if (val < -1.0) val = -1.0;
        x_in[i] = val;
    }

    // compute RBF activations h (HidLayNum x 1)
    std::vector<double> h(HidLayNum, 0.0);
    for (int j=0;j<HidLayNum;j++) {
        double norm2 = 0.0;
        for (int i=0;i<inDim_global;i++) {
            double diff = x_in[i] - c_i[i][j];
            norm2 += diff*diff;
        }
        h[j] = exp(-norm2 / (2.0 * b_i * b_i));
    }

    // network output y = hat_W' * h  => nq x 1
    std::vector<double> y(nq_global, 0.0);
    for (int k=0;k<nq_global;k++) {
        double ssum = 0.0;
        for (int j=0;j<HidLayNum;j++) ssum += hat_W[j][k] * h[j];
        y[k] = ssum;
    }

    // hat_F = S_out * y  (nq x 1)
    std::vector<double> hat_F(nq_global);
    for (int i=0;i<nq_global;i++) hat_F[i] = S_out * y[i];

    // s = c_s*e + de  (choose c_s)
    double c_s = 5.0;
    std::vector<double> svec(nq_global);
    for (int i=0;i<nq_global;i++) svec[i] = c_s * e[i] + de[i];

    // weight update: hat_W += gamma * h * s' * dt
    for (int j=0;j<HidLayNum;j++) {
        for (int k=0;k<nq_global;k++) {
            double delta = gamma_W * h[j] * svec[k] * dt;
            hat_W[j][k] += delta;
            // clip
            if (hat_W[j][k] > W_max) hat_W[j][k] = W_max;
            if (hat_W[j][k] < -W_max) hat_W[j][k] = -W_max;
        }
    }

    // ddqd = -Kp*e - Kd*de
    std::vector<double> ddqd(nq_global,0.0);
    for (int i=0;i<nq_global;i++) ddqd[i] = -Kp[i]*e[i] - Kd[i]*de[i];

    // tau_nom = M*ddqd + C + G + F
    std::vector<double> tau_nom(nq_global,0.0);
    for (int i=0;i<nq_global;i++){
        double ssum=0.0;
        for (int j=0;j<nq_global;j++){
            // M is column-major
            ssum += M[i + j*nq_global] * ddqd[j];
        }
        tau_nom[i] = ssum + C[i] + G[i] + F[i];
    }

    // tau = tau_nom - hat_F - k_s * sat(s/phi) (element-wise)
    std::vector<double> tau(nq_global,0.0);
    for (int i=0;i<nq_global;i++){
        double satv = sat(svec[i]/phi);
        tau[i] = tau_nom[i] - hat_F[i] - k_s * satv;
    }

    // outputs
    plhs[0] = mxCreateDoubleMatrix(nq_global,1,mxREAL);
    double *tau_out = mxGetPr(plhs[0]);
    for (int i=0;i<nq_global;i++) tau_out[i] = tau[i];

    if (nlhs>1){
        plhs[1] = mxCreateDoubleMatrix(nq_global,1,mxREAL);
        double *hf = mxGetPr(plhs[1]);
        for (int i=0;i<nq_global;i++) hf[i] = hat_F[i];
    }
}
