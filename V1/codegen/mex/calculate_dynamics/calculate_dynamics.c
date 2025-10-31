/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_dynamics.c
 *
 * Code generation for function 'calculate_dynamics'
 *
 */

/* Include files */
#include "calculate_dynamics.h"
#include "calc_aa.h"
#include "calc_pos.h"
#include "calculate_dynamics_data.h"
#include "calculate_dynamics_internal_types.h"
#include "r_ne.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,                    /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    10,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    11,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    12,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    23,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    24,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    25,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    34,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    35,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    36,                   /* lineNo */
    "calculate_dynamics", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\calculate_dynamics.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    1,              /* iFirst */
    7,              /* iLast */
    36,             /* lineNo */
    20,             /* colNo */
    "In2",          /* aName */
    "init_LP_1028", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\init_LP_1028.m", /* pName */
    0                           /* checkKind */
};

/* Function Definitions */
void calculate_dynamics(const emlrtStack *sp, const real_T q[21],
                        const real_T dq[21], real_T M[441], real_T C[21],
                        real_T G[21], real_T F[21])
{
  static const real_T fb[21] = {
      7.1649,  13.3287, 6.7645,  7.8656, 4.993,  5.5236, 6.3949,
      16.2233, 10.8006, 6.8534,  9.1136, 6.4825, 6.8079, 6.8188,
      14.559,  9.8068,  10.2333, 7.5364, 6.6155, 8.2332, 5.6067};
  static const real_T fc[21] = {
      0.0013,  -3.2393, 7.0109,   1.8455,  5.2311,  -2.9146, 1.9626,
      -0.3519, 13.0231, -16.2296, -9.2256, -2.4148, 6.3453,  -1.7018,
      0.5225,  -9.2769, 9.009,    8.1262,  -2.7479, -4.0121, 0.0297};
  static const real_T fv[21] = {
      27.7543, 37.342,  9.5503,  42.2625, 21.8571, 28.3255, 28.0928,
      9.1074,  7.0165,  46.6431, 9.6458,  23.9635, 30.4596, 16.3822,
      51.6363, 32.9703, 31.1092, 30.8627, 28.514,  25.6389, 20.0904};
  static const int8_T b_iv[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  emlrtStack st;
  struct_T SV;
  real_T b_SV[63];
  real_T c_SV[63];
  real_T d_SV[63];
  real_T Force[27];
  real_T Force_k[27];
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  /*  */
  /*  矩阵的条件数唯一决定线性方程解受观测值噪声的影响程度 */
  /*  条件数越大影响越严重，表现为解与观测值的变化率偏离越大，包括变化率过大或过小
   */
  /*  且其对稳定性的衡量不受整体尺度放缩影响，因噪声影响程度由变化率而非绝对大小决定
   */
  /*  计算方式：cond(A) = 最大奇异值 / 最小奇异值 */
  /*  In2 = 100 * In2; */
  for (k = 0; k < 21; k++) {
    if (k == 0) {
      i = 0;
    } else {
      i = (int32_T)muDoubleScalarRem(((real_T)k + 1.0) - 1.0, 7.0);
    }
    if ((real_T)i + 1.0 > 7.0) {
      emlrtDynamicBoundsCheckR2012b(8, 1, 7, &emlrtBCI, &st);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  */
  /*  姿态常量 */
  /*  结构尺寸与质量参数 */
  for (k = 0; k < 7; k++) {
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  SV.R0[0] = 0.0;
  SV.Q0[0] = 0.0;
  SV.R0[1] = 0.0;
  SV.Q0[1] = 0.0;
  SV.R0[2] = 0.0;
  SV.Q0[2] = 0.0;
  for (i = 0; i < 9; i++) {
    SV.A0[i] = b_iv[i];
  }
  memset(&SV.AA[0], 0, 189U * sizeof(real_T));
  SV.v0[0] = 0.0;
  SV.w0[0] = 0.0;
  SV.vd0[0] = 0.0;
  SV.wd0[0] = 0.0;
  SV.v0[1] = 0.0;
  SV.w0[1] = 0.0;
  SV.vd0[1] = 0.0;
  SV.wd0[1] = 0.0;
  SV.v0[2] = 0.0;
  SV.w0[2] = 0.0;
  SV.vd0[2] = 0.0;
  SV.wd0[2] = 0.0;
  SV.F0[0] = 0.0;
  SV.T0[0] = 0.0;
  SV.F0[1] = 0.0;
  SV.T0[1] = 0.0;
  SV.F0[2] = 0.0;
  SV.T0[2] = 0.0;
  memset(&SV.RR[0], 0, 63U * sizeof(real_T));
  memset(&SV.vv[0], 0, 63U * sizeof(real_T));
  memset(&SV.ww[0], 0, 63U * sizeof(real_T));
  memset(&SV.vd[0], 0, 63U * sizeof(real_T));
  memset(&SV.wd[0], 0, 63U * sizeof(real_T));
  memset(&SV.Fe[0], 0, 63U * sizeof(real_T));
  memset(&SV.Te[0], 0, 63U * sizeof(real_T));
  /*  ---------- 计算 G ---------- */
  for (i = 0; i < 21; i++) {
    SV.tau[i] = 0.0;
    SV.q[i] = q[i];
    SV.qd[i] = 0.0;
    SV.qdd[i] = 0.0;
  }
  st.site = &b_emlrtRSI;
  calc_aa(&st, &SV);
  st.site = &c_emlrtRSI;
  calc_pos(&st, &SV);
  memcpy(&b_SV[0], &SV.ww[0], 63U * sizeof(real_T));
  memcpy(&c_SV[0], &SV.vd[0], 63U * sizeof(real_T));
  memcpy(&d_SV[0], &SV.wd[0], 63U * sizeof(real_T));
  st.site = &d_emlrtRSI;
  r_ne(&st, SV.A0, SV.AA, SV.w0, SV.vd0, SV.wd0, SV.q, SV.qd, SV.qdd, b_SV,
       c_SV, d_SV, SV.Fe, SV.Te, Force);
  memcpy(&G[0], &Force[6], 21U * sizeof(real_T));
  /*  ---------- 计算 M ---------- */
  for (k = 0; k < 21; k++) {
    for (i = 0; i < 21; i++) {
      SV.q[i] = q[i];
      SV.qd[i] = 0.0;
      SV.qdd[i] = 0.0;
    }
    SV.qdd[k] = 1.0;
    st.site = &e_emlrtRSI;
    calc_aa(&st, &SV);
    st.site = &f_emlrtRSI;
    calc_pos(&st, &SV);
    memcpy(&b_SV[0], &SV.ww[0], 63U * sizeof(real_T));
    memcpy(&c_SV[0], &SV.vd[0], 63U * sizeof(real_T));
    memcpy(&d_SV[0], &SV.wd[0], 63U * sizeof(real_T));
    st.site = &g_emlrtRSI;
    r_ne(&st, SV.A0, SV.AA, SV.w0, SV.vd0, SV.wd0, SV.q, SV.qd, SV.qdd, b_SV,
         c_SV, d_SV, SV.Fe, SV.Te, Force_k);
    for (i = 0; i < 21; i++) {
      M[i + 21 * k] = Force_k[i + 6] - Force[i + 6];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  ---------- 计算 C ---------- */
  for (i = 0; i < 21; i++) {
    SV.q[i] = q[i];
    SV.qd[i] = dq[i];
    SV.qdd[i] = 0.0;
  }
  st.site = &h_emlrtRSI;
  calc_aa(&st, &SV);
  st.site = &i_emlrtRSI;
  calc_pos(&st, &SV);
  memcpy(&b_SV[0], &SV.ww[0], 63U * sizeof(real_T));
  memcpy(&c_SV[0], &SV.vd[0], 63U * sizeof(real_T));
  memcpy(&d_SV[0], &SV.wd[0], 63U * sizeof(real_T));
  st.site = &j_emlrtRSI;
  r_ne(&st, SV.A0, SV.AA, SV.w0, SV.vd0, SV.wd0, SV.q, SV.qd, SV.qdd, b_SV,
       c_SV, d_SV, SV.Fe, SV.Te, Force_k);
  for (i = 0; i < 21; i++) {
    C[i] = Force_k[i + 6] - Force[i + 6];
  }
  /*  ---------- 计算 F ---------- */
  /*  提取各参数列 */
  /*  库伦摩擦系数 */
  /*  粘滞摩擦系数 */
  /*  偏置摩擦系数 */
  for (i = 0; i < 21; i++) {
    real_T d;
    d = q[i];
    F[i] = (fc[i] * muDoubleScalarSign(d) + fv[i] * d) + fb[i];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (calculate_dynamics.c) */
