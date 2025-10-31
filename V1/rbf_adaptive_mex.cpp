#include "mex.h"
#include <cmath>
#include <vector>
#include <random>

// ---------- persistent 全局变量 ----------
static bool initialized = false;
static int HidLayNum;
static double b_i;
static double gamma_W;
static double k_s;
static double phi;
static double c_s;
static std::vector<std::vector<double>> c_i;     // [xdim x HidLayNum]
static std::vector<std::vector<double>> hat_W;   // [HidLayNum x nq]
static int nq_global;

// ---------- 工具函数 ----------
inline double sat(double v) {
    if (v > 1.0) return 1.0;
    if (v < -1.0) return -1.0;
    return v;
}

// ---------- 主函数 ----------
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 10)
        mexErrMsgTxt("Usage: [tau, hat_fx] = rbf_adaptive_mex(qr,dqr,e,de,M,C,G,F,Kp,Kd,nq)");

    // 输入
    double *qr  = mxGetPr(prhs[0]);
    double *dqr = mxGetPr(prhs[1]);
    double *e   = mxGetPr(prhs[2]);
    double *de  = mxGetPr(prhs[3]);
    double *M   = mxGetPr(prhs[4]);  // nq×nq
    double *C   = mxGetPr(prhs[5]);
    double *G   = mxGetPr(prhs[6]);
    double *F   = mxGetPr(prhs[7]);
    double *Kp  = mxGetPr(prhs[8]);
    double *Kd  = mxGetPr(prhs[9]);

    mwSize nq = mxGetM(prhs[0]);   // 行数
    int nq_int = static_cast<int>(nq);
    int xdim = 2 * nq_int;

    // 初始化 persistent 变量
    if (!initialized)
    {
        HidLayNum = 60;
        b_i = 1.0;
        gamma_W = 50.0;
        k_s = 20.0;
        phi = 0.01;
        c_s = 5.0;
        nq_global = nq_int;

        std::mt19937 gen(0);
        std::uniform_real_distribution<double> dist(-1.0, 1.0);

        // 初始化中心
        c_i.resize(xdim, std::vector<double>(HidLayNum));
        for (int i = 0; i < xdim; i++)
            for (int j = 0; j < HidLayNum; j++)
                c_i[i][j] = dist(gen);

        // 初始化权重
        hat_W.resize(HidLayNum, std::vector<double>(nq_int, 0.01));

        initialized = true;
    }

    // ---------- 计算输入向量 ----------
    std::vector<double> x_in(xdim);
    for (int i = 0; i < nq_int; i++) {
        x_in[i] = qr[i];
        x_in[i + nq_int] = dqr[i];
    }

    // ---------- 计算 RBF 激活 ----------
    std::vector<double> h(HidLayNum, 0.0);
    for (int j = 0; j < HidLayNum; j++) {
        double norm2 = 0.0;
        for (int i = 0; i < xdim; i++) {
            double diff = x_in[i] - c_i[i][j];
            norm2 += diff * diff;
        }
        h[j] = std::exp(-norm2 / (2 * b_i * b_i));
    }

    // ---------- 计算网络输出 hat_fx = hat_W' * h ----------
    std::vector<double> hat_fx(nq_int, 0.0);
    for (int k = 0; k < nq_int; k++) {
        double sum = 0.0;
        for (int j = 0; j < HidLayNum; j++)
            sum += hat_W[j][k] * h[j];
        hat_fx[k] = sum;
    }

    // ---------- 滑模变量 s = c_s*e + de ----------
    std::vector<double> s(nq_int);
    for (int i = 0; i < nq_int; i++)
        s[i] = c_s * e[i] + de[i];

    // ---------- 权值更新 (离散欧拉) ----------
    double dt = 0.001; // 假定采样时间
    for (int j = 0; j < HidLayNum; j++)
        for (int k = 0; k < nq_int; k++)
            hat_W[j][k] += gamma_W * h[j] * s[k] * dt;

    // ---------- ddqd = -Kp*e - Kd*de ----------
    std::vector<double> ddqd(nq_int, 0.0);
    for (int i = 0; i < nq_int; i++)
        ddqd[i] = -Kp[i] * e[i] - Kd[i] * de[i];

    // ---------- tau_nom = M*ddqd + C + G + F ----------
    std::vector<double> tau_nom(nq_int, 0.0);
    for (int i = 0; i < nq_int; i++) {
        double sum = 0.0;
        for (int j = 0; j < nq_int; j++)
            sum += M[i + j * nq_int] * ddqd[j]; // MATLAB 列主序
        tau_nom[i] = sum + C[i] + G[i] + F[i];
    }

    // ---------- tau = tau_nom - M*(hat_fx + k_s*sat(s/phi)) ----------
    std::vector<double> sat_s(nq_int);
    for (int i = 0; i < nq_int; i++)
        sat_s[i] = sat(s[i] / phi);

    std::vector<double> tmp(nq_int);
    for (int i = 0; i < nq_int; i++)
        tmp[i] = hat_fx[i] + k_s * sat_s[i];

    std::vector<double> tau(nq_int);
    for (int i = 0; i < nq_int; i++) {
        double sum = 0.0;
        for (int j = 0; j < nq_int; j++)
            sum += M[i + j * nq_int] * tmp[j];
        tau[i] = tau_nom[i] - sum;
    }

    // ---------- 输出 ----------
    plhs[0] = mxCreateDoubleMatrix(nq_int, 1, mxREAL);
    double *tau_out = mxGetPr(plhs[0]);
    for (int i = 0; i < nq_int; i++)
        tau_out[i] = tau[i];

    if (nlhs > 1) {
        plhs[1] = mxCreateDoubleMatrix(nq_int, 1, mxREAL);
        double *hf = mxGetPr(plhs[1]);
        for (int i = 0; i < nq_int; i++)
            hf[i] = hat_fx[i];
    }
}
