/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * single_init_2.c
 *
 * Code generation for function 'single_init_2'
 *
 */

/* Include files */
#include "single_init_2.h"
#include "rt_nonfinite.h"
#include "single_init_2_data.h"
#include "single_init_2_types.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = {
    1,               /* iFirst */
    7,               /* iLast */
    21,              /* lineNo */
    18,              /* colNo */
    "I",             /* aName */
    "single_init_2", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\single_init_2.m", /* pName */
    0                        /* checkKind */
};

/* Function Definitions */
void single_init_2(const emlrtStack *sp, struct0_T *LP)
{
  static const real_T P[21] = {0.0,   -0.225, 0.0,   0.0, -0.24, 0.0,    0.0,
                               0.24,  0.0,    0.56,  0.0, 0.2,   0.5,    0.0,
                               0.195, 0.0,    -0.18, 0.0, 0.0,   0.4216, 0.0};
  static const real_T Pc[21] = {0.003, -0.0621, -0.052, 0.001,  0.06,  -0.058,
                                0.226, 0.005,   -0.025, 0.238,  0.001, -0.001,
                                0.008, -0.028,  -0.031, -0.025, 0.023, 0.003,
                                0.003, -0.01,   -0.199};
  static const real_T dv[21] = {6.34, 6.32, 21.93, 5.621, 2.84, 2.211, 12.08,
                                6.34, 6.32, 21.93, 5.621, 2.84, 2.211, 12.08,
                                6.34, 6.32, 21.93, 5.621, 2.84, 2.211, 12.08};
  static const real_T dv1[9] = {0.098, -0.005, -0.003, -0.005, 0.045,
                                0.022, -0.003, 0.022,  0.0212};
  static const real_T dv2[9] = {0.0821, -0.005, -0.002, -0.005, 0.021,
                                -0.022, -0.002, -0.022, 0.069};
  static const real_T dv3[9] = {0.0219, -0.002, -0.12,  -0.002, 0.5211,
                                -0.089, -0.12,  -0.089, 0.53};
  static const real_T dv4[9] = {0.032,  -0.001, -0.052, -0.001, 0.325,
                                -0.092, -0.052, -0.092, 0.313};
  static const real_T dv5[9] = {0.014, -0.011, -0.001, -0.011, 0.01,
                                0.002, -0.001, 0.002,  0.011};
  static const real_T dv6[9] = {0.013,  -0.002, -0.001, -0.002, 0.009,
                                -0.001, -0.001, -0.001, 0.011};
  static const real_T dv7[9] = {0.151,  -0.002, -0.003, -0.002, 0.195,
                                -0.008, -0.003, -0.008, 0.096};
  static const int8_T iv1[441] = {
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      -1};
  static const int8_T iv[21] = {0,  1,  2,  3, 4,  5,  6,  0,  8,  9, 10,
                                11, 12, 13, 0, 15, 16, 17, 18, 19, 20};
  static const int8_T iv2[21] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv3[21] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0, 1};
  real_T b_I[63];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  int32_T k;
  /*  ===================== system_init_single.m ===================== */
  LP->num_q = 21.0;
  LP->m0 = 5.0;
  /*  漂浮基座无质量（固定基） */
  memcpy(&LP->m[0], &dv[0], 21U * sizeof(real_T));
  LP->mass = 177.026;
  for (j = 0; j < 9; j++) {
    b_I[j] = dv1[j];
    b_I[j + 9] = dv2[j];
    b_I[j + 18] = dv3[j];
    b_I[j + 27] = dv4[j];
    b_I[j + 36] = dv5[j];
    b_I[j + 45] = dv6[j];
    b_I[j + 54] = dv7[j];
  }
  memset(&LP->inertia[0], 0, 189U * sizeof(real_T));
  for (k = 0; k < 21; k++) {
    if (k == 0) {
      j = 0;
      i = 0;
    } else {
      j = (int32_T)muDoubleScalarRem(((real_T)k + 1.0) - 1.0, 7.0);
      i = (int32_T)muDoubleScalarRem(((real_T)k + 1.0) - 1.0, 7.0);
    }
    if ((real_T)i + 1.0 > 7.0) {
      emlrtDynamicBoundsCheckR2012b(8, 1, 7, &emlrtBCI, (emlrtConstCTX)sp);
    }
    i = 3 * (k + 1) - 3;
    for (i1 = 0; i1 < 3; i1++) {
      i2 = 3 * (i1 + i);
      LP->inertia[i2] = b_I[3 * i1 + 9 * j];
      LP->inertia[i2 + 1] = b_I[(3 * i1 + 9 * j) + 1];
      LP->inertia[i2 + 2] = b_I[(3 * i1 + 9 * j) + 2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  memset(&LP->inertia0[0], 0, 9U * sizeof(real_T));
  /*  基座惯性 */
  /*  旋转关节 */
  for (i = 0; i < 21; i++) {
    LP->J_type[i] = 'R';
    LP->BB[i] = iv[i];
    LP->S0[i] = iv2[i];
    LP->SE[i] = iv3[i];
  }
  for (i = 0; i < 441; i++) {
    LP->SS[i] = iv1[i];
  }
  /*  ---------- 质量与惯性 ---------- */
  /*  ---------- 向量定义 ---------- */
  /*  连杆连接向量（从i到i+1的矢量） */
  /*  质心坐标（在各自连杆坐标系中） */
  memset(&LP->Qi[0], 0, 63U * sizeof(real_T));
  memset(&LP->Qe[0], 0, 63U * sizeof(real_T));
  /*  末端位置相对最后一节 */
  /*  ---------- SpaceDyn 坐标结构 ---------- */
  memset(&LP->cc[0], 0, 1323U * sizeof(real_T));
  /*  质心位置 */
  /*  基座至每节起点 */
  memset(&LP->c0[0], 0, 63U * sizeof(real_T));
  memset(&LP->ce[0], 0, 63U * sizeof(real_T));
  /*  连杆末端相对位置 */
  LP->c0[0] = 0.0;
  LP->c0[21] = -0.21650635094610968;
  LP->c0[42] = 0.21650635094610962;
  LP->c0[1] = 0.0;
  LP->c0[22] = 0.0;
  LP->c0[43] = 0.0;
  LP->c0[2] = 0.25;
  LP->c0[23] = -0.12499999999999994;
  LP->c0[44] = -0.12500000000000011;
  for (j = 0; j < 7; j++) {
    LP->cc[66 * j] = Pc[3 * j];
    i = 66 * j;
    i1 = 3 * j + 1;
    LP->cc[i + 1] = Pc[i1];
    i2 = 3 * j + 2;
    LP->cc[i + 2] = Pc[i2];
    if (j + 1 < 7) {
      i = 3 * j + 63 * (j + 1);
      LP->cc[i] = P[3 * j];
      LP->cc[i + 1] = P[i1];
      LP->cc[i + 2] = P[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  ---------- 姿态初始角 ---------- */
  for (i = 0; i < 7; i++) {
    for (i1 = 0; i1 < 7; i1++) {
      i2 = 3 * i1 + 63 * i;
      j = 3 * (i1 + 7) + 63 * (i + 7);
      LP->cc[j] = LP->cc[i2];
      LP->cc[j + 1] = LP->cc[i2 + 1];
      LP->cc[j + 2] = LP->cc[i2 + 2];
    }
  }
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      i2 = 3 * i1 + 63 * (i + 1);
      j = 3 * (i1 + 7) + 63 * (i + 8);
      LP->cc[j] = LP->cc[i2];
      LP->cc[j + 1] = LP->cc[i2 + 1];
      LP->cc[j + 2] = LP->cc[i2 + 2];
    }
  }
  for (i = 0; i < 7; i++) {
    for (i1 = 0; i1 < 7; i1++) {
      i2 = 3 * i1 + 63 * i;
      j = 3 * (i1 + 14) + 63 * (i + 14);
      LP->cc[j] = LP->cc[i2];
      LP->cc[j + 1] = LP->cc[i2 + 1];
      LP->cc[j + 2] = LP->cc[i2 + 2];
    }
  }
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      i2 = 3 * i1 + 63 * (i + 1);
      j = 3 * (i1 + 14) + 63 * (i + 15);
      LP->cc[j] = LP->cc[i2];
      LP->cc[j + 1] = LP->cc[i2 + 1];
      LP->cc[j + 2] = LP->cc[i2 + 2];
    }
  }
  LP->ce[18] = -0.003;
  LP->ce[39] = -0.003;
  LP->ce[60] = -0.003;
  LP->ce[19] = 0.5816;
  LP->ce[40] = 0.5816;
  LP->ce[61] = 0.5816;
  LP->ce[20] = 0.199;
  LP->ce[41] = 0.199;
  LP->ce[62] = 0.199;
}

/* End of code generation (single_init_2.c) */
