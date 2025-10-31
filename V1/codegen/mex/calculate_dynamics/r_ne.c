/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * r_ne.c
 *
 * Code generation for function 'r_ne'
 *
 */

/* Include files */
#include "r_ne.h"
#include "calculate_dynamics_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = {
    34,     /* lineNo */
    "r_ne", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\r_ne.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    39,     /* lineNo */
    "r_ne", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\r_ne.m" /* pathName */
};

static emlrtBCInfo b_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    96,      /* lineNo */
    55,      /* colNo */
    "LP.cc", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\r_ne.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    72,         /* lineNo */
    59,         /* colNo */
    "LP.cc",    /* aName */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_vel.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    86,      /* lineNo */
    30,      /* colNo */
    "LP.SS", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\r_ne.m", /* pName */
    0                             /* checkKind */
};

/* Function Definitions */
void r_ne(const emlrtStack *sp, const real_T SV_A0[9], const real_T SV_AA[189],
          const real_T SV_w0[3], const real_T SV_vd0[3], const real_T SV_wd0[3],
          const real_T SV_q[21], const real_T SV_qd[21],
          const real_T SV_qdd[21], real_T SV_ww[63], real_T SV_vd[63],
          real_T SV_wd[63], const real_T SV_Fe[63], const real_T SV_Te[63],
          real_T Force[27])
{
  static const real_T b_dv1[189] = {
      0.0012, 0.0, 0.0,     0.0, 0.0012, 0.0, 0.0,     0.0, 0.0013,
      0.0018, 0.0, -0.0002, 0.0, 0.0018, 0.0, -0.0002, 0.0, 0.0016,
      0.0007, 0.0, 0.0,     0.0, 0.0007, 0.0, 0.0,     0.0, 0.0008,
      0.0007, 0.0, -0.0002, 0.0, 0.0007, 0.0, -0.0002, 0.0, 0.0005,
      0.0018, 0.0, -0.0002, 0.0, 0.0016, 0.0, -0.0002, 0.0, 0.0018,
      0.0012, 0.0, 0.0,     0.0, 0.0013, 0.0, 0.0,     0.0, 0.0012,
      0.0004, 0.0, 0.0,     0.0, 0.0004, 0.0, 0.0,     0.0, 0.0007,
      0.0012, 0.0, 0.0,     0.0, 0.0012, 0.0, 0.0,     0.0, 0.0013,
      0.0018, 0.0, -0.0002, 0.0, 0.0018, 0.0, -0.0002, 0.0, 0.0016,
      0.0007, 0.0, 0.0,     0.0, 0.0007, 0.0, 0.0,     0.0, 0.0008,
      0.0007, 0.0, -0.0002, 0.0, 0.0007, 0.0, -0.0002, 0.0, 0.0005,
      0.0018, 0.0, -0.0002, 0.0, 0.0016, 0.0, -0.0002, 0.0, 0.0018,
      0.0012, 0.0, 0.0,     0.0, 0.0013, 0.0, 0.0,     0.0, 0.0012,
      0.0004, 0.0, 0.0,     0.0, 0.0004, 0.0, 0.0,     0.0, 0.0007,
      0.0012, 0.0, 0.0,     0.0, 0.0012, 0.0, 0.0,     0.0, 0.0013,
      0.0018, 0.0, -0.0002, 0.0, 0.0018, 0.0, -0.0002, 0.0, 0.0016,
      0.0007, 0.0, 0.0,     0.0, 0.0007, 0.0, 0.0,     0.0, 0.0008,
      0.0007, 0.0, -0.0002, 0.0, 0.0007, 0.0, -0.0002, 0.0, 0.0005,
      0.0018, 0.0, -0.0002, 0.0, 0.0016, 0.0, -0.0002, 0.0, 0.0018,
      0.0012, 0.0, 0.0,     0.0, 0.0013, 0.0, 0.0,     0.0, 0.0012,
      0.0004, 0.0, 0.0,     0.0, 0.0004, 0.0, 0.0,     0.0, 0.0007};
  static const real_T dv2[63] = {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.18719999999999998,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.35719999999999996,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.35719999999999996};
  static const real_T b_dv[21] = {
      0.6926, 1.1285, 0.4417, 0.4549, 1.1285, 0.6926, 0.4863,
      0.6926, 1.1285, 0.4417, 0.4549, 1.1285, 0.6926, 0.4863,
      0.6926, 1.1285, 0.4417, 0.4549, 1.1285, 0.6926, 0.4863};
  static const real_T b[9] = {0.0347, 0.0, 0.0, 0.0,   0.0519,
                              0.0,    0.0, 0.0, 0.0347};
  static const int8_T iv2[441] = {
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
  static const int8_T b_iv[21] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                  0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv1[21] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0, 1};
  emlrtStack st;
  real_T FF[63];
  real_T Fj[63];
  real_T TT[63];
  real_T Tj[63];
  real_T SV_tau[21];
  real_T A_I_BB[9];
  real_T A_I_i[9];
  real_T b_SV_AA[9];
  real_T F[3];
  real_T T[3];
  real_T b_n[3];
  real_T c_SV_AA[3];
  real_T n[3];
  real_T y[3];
  real_T F_tmp;
  real_T b_F_tmp;
  real_T b_SV_AA_tmp;
  real_T b_n_tmp;
  real_T c_F_tmp;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d_n_tmp;
  real_T e_n_tmp;
  int32_T A_I_i_tmp;
  int32_T SV_AA_tmp;
  int32_T b_i;
  int32_T c_i;
  int32_T c_n_tmp;
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T n_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
  /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
  /*  Tohoku University, Japan. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*    version 1 // Oct 4, 1999, Last modification by K.Yoshida */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  R_NE		Inverse Dynamic computation by the Recursive Newton-Euler
   * method */
  /*  */
  /* 		R_NE returns a generalized force, which consists of */
  /* 		the reaction forces FF0, TT0 on the link 0, and torque tau */
  /* 		of each joint. */
  /*  */
  /*  R_NE        通过递归牛顿-欧拉法进行反向动力学计算 */
  /*  */
  /*         R_NE 返回一个广义力，包含 */
  /*         连杆0上的反作用力FF0、TT0，以及 */
  /*         各关节的转矩τ。 */
  /*  初始化 Gravity */
  /*  初始化 Ez */
  /*  Calculation of coordinate transfromation matrices */
  /*  Calculation of velocity vectors vv,ww */
  /*  NOTE:	vv,ww are in the Inertial frame */
  st.site = &k_emlrtRSI;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
  /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
  /*  Tohoku University, Japan. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* 	February 4, 1999, Last modification by K.Yoshida */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  CALC_VEL	Calculate the velocity of each link */
  /*  */
  /*    CALC_VEL returns the link velocity in the inertial frame */
  /*             for link 1 to n. */
  /*  */
  /*  CALC_VEL    递推计算各连杆的速度（质心速度和角速度） */
  /*  */
  /*    CALC_VEL 返回第 1 至第 n 连杆在惯性坐标系中的速度。 */
  /* global BB J_type */
  /* global c0 cc */
  /* global num_q Ez */
  /*  初始化 Ez */
  /*  If a Single body, */
  /*  Calculation of velocity vectors vv,ww */
  for (i = 0; i < 21; i++) {
    /*  Check the link connection: Is the lower one of this link, 0 ? */
    if (iv[i] == 0) {
      /*  Current (i-th) link connects to the 0-th link */
      /*  Rotational joint */
      b_i = (i + 1) * 3 - 3;
      for (c_i = 0; c_i < 3; c_i++) {
        SV_AA_tmp = 3 * (c_i + b_i);
        b_SV_AA[3 * c_i] = SV_AA[SV_AA_tmp];
        b_SV_AA[3 * c_i + 1] = SV_AA[SV_AA_tmp + 1];
        b_SV_AA[3 * c_i + 2] = SV_AA[SV_AA_tmp + 2];
      }
      for (c_i = 0; c_i < 3; c_i++) {
        SV_ww[c_i + 3 * i] =
            SV_w0[c_i] +
            ((b_SV_AA[c_i] * 0.0 + b_SV_AA[c_i + 3] * 0.0) + b_SV_AA[c_i + 6]) *
                SV_qd[i];
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      /*  Prismatic joint */
      /*  Current (i-th) link doesn't connect to the 0-th link */
    } else {
      /*  Rotational joint */
      b_i = (i + 1) * 3 - 3;
      for (c_i = 0; c_i < 3; c_i++) {
        SV_AA_tmp = 3 * (c_i + b_i);
        b_SV_AA[3 * c_i] = SV_AA[SV_AA_tmp];
        b_SV_AA[3 * c_i + 1] = SV_AA[SV_AA_tmp + 1];
        b_SV_AA[3 * c_i + 2] = SV_AA[SV_AA_tmp + 2];
      }
      for (c_i = 0; c_i < 3; c_i++) {
        c_SV_AA[c_i] =
            SV_ww[c_i + 3 * (iv[i] - 1)] +
            ((b_SV_AA[c_i] * 0.0 + b_SV_AA[c_i + 3] * 0.0) + b_SV_AA[c_i + 6]) *
                SV_qd[i];
      }
      SV_ww[3 * i] = c_SV_AA[0];
      SV_ww[3 * i + 1] = c_SV_AA[1];
      SV_ww[3 * i + 2] = c_SV_AA[2];
      if (iv[i] < 1) {
        emlrtDynamicBoundsCheckR2012b(0, 1, 21, &c_emlrtBCI, &st);
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      /*  Prismatic joint */
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /* %%EOF */
  /*  Calculation of acceletion vectors vd,wd */
  /*  NOTE:	vd,wd are in the Inertial frame */
  st.site = &l_emlrtRSI;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
  /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
  /*  Tohoku University, Japan. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*    version 1 // Oct 4, 1999, Last modification by K.Yoshida */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  CALC_ACC 	Calculate the accelation of links */
  /*  */
  /*    CALC_ACC returns the accelation in the Inertia frame */
  /*    for link 1 to n. */
  /*  */
  /*  CALC_ACC     递推计算各连杆的速度（质心速度和角速度） */
  /*  */
  /*    CALC_ACC 返回第 1 至 n 号连杆在惯性坐标系中的加速度 */
  /*  初始化 Ez */
  /*  If Single body */
  /*  Calcuration of coordinate transfromation matrices */
  /*  Calculation of acceletion vectors vd,wd */
  for (i = 0; i < 21; i++) {
    int8_T i1;
    /*  Check the link connection: Is the lower one of this link, 0 ? */
    i1 = iv[i];
    if (i1 == 0) {
      /*  If the i-th link connects with 0-th link */
      b_i = (i + 1) * 3 - 3;
      for (c_i = 0; c_i < 3; c_i++) {
        A_I_i_tmp = 3 * (c_i + b_i);
        A_I_i[3 * c_i] = SV_AA[A_I_i_tmp];
        A_I_i[3 * c_i + 1] = SV_AA[A_I_i_tmp + 1];
        A_I_i[3 * c_i + 2] = SV_AA[A_I_i_tmp + 2];
      }
      /*  Rotational joint */
      for (b_i = 0; b_i < 3; b_i++) {
        d = (A_I_i[b_i] * 0.0 + A_I_i[b_i + 3] * 0.0) + A_I_i[b_i + 6];
        F[b_i] = d;
        y[b_i] = d * SV_qd[i];
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      n_tmp = 3 * i + 2;
      b_n_tmp = SV_ww[n_tmp];
      c_n_tmp = 3 * i + 1;
      d_n_tmp = SV_ww[c_n_tmp];
      b_n[0] = d_n_tmp * y[2] - y[1] * b_n_tmp;
      e_n_tmp = SV_ww[3 * i];
      b_n[1] = y[0] * b_n_tmp - e_n_tmp * y[2];
      b_n[2] = e_n_tmp * y[1] - y[0] * d_n_tmp;
      d = dv[3 * i];
      d1 = dv[c_n_tmp];
      d2 = dv[n_tmp];
      F_tmp = dv1[66 * i];
      c_i = 66 * i;
      for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
        SV_wd[SV_AA_tmp + 3 * i] =
            (SV_wd0[SV_AA_tmp] + b_n[SV_AA_tmp]) + F[SV_AA_tmp] * SV_qdd[i];
        b_SV_AA_tmp =
            (A_I_i[SV_AA_tmp] * F_tmp + A_I_i[SV_AA_tmp + 3] * dv1[c_i + 1]) +
            A_I_i[SV_AA_tmp + 6] * dv1[c_i + 2];
        c_SV_AA[SV_AA_tmp] = b_SV_AA_tmp;
        F[SV_AA_tmp] = b_SV_AA_tmp;
        c_F_tmp = (SV_A0[SV_AA_tmp] * d + SV_A0[SV_AA_tmp + 3] * d1) +
                  SV_A0[SV_AA_tmp + 6] * d2;
        T[SV_AA_tmp] = c_F_tmp;
        y[SV_AA_tmp] = c_F_tmp;
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      b_n[0] = SV_wd0[1] * y[2] - y[1] * SV_wd0[2];
      b_n[1] = y[0] * SV_wd0[2] - SV_wd0[0] * y[2];
      b_n[2] = SV_wd0[0] * y[1] - y[0] * SV_wd0[1];
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      n[0] = SV_w0[1] * T[2] - T[1] * SV_w0[2];
      n[1] = T[0] * SV_w0[2] - SV_w0[0] * T[2];
      n[2] = SV_w0[0] * T[1] - T[0] * SV_w0[1];
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      y[0] = SV_w0[1] * n[2] - n[1] * SV_w0[2];
      y[1] = n[0] * SV_w0[2] - SV_w0[0] * n[2];
      y[2] = SV_w0[0] * n[1] - n[0] * SV_w0[1];
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      c_F_tmp = SV_wd[n_tmp];
      b_F_tmp = SV_wd[c_n_tmp];
      n[0] = b_F_tmp * F[2] - F[1] * c_F_tmp;
      F_tmp = SV_wd[3 * i];
      n[1] = F[0] * c_F_tmp - F_tmp * F[2];
      n[2] = F_tmp * F[1] - F[0] * b_F_tmp;
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      T[0] = d_n_tmp * c_SV_AA[2] - c_SV_AA[1] * b_n_tmp;
      T[1] = c_SV_AA[0] * b_n_tmp - e_n_tmp * c_SV_AA[2];
      T[2] = e_n_tmp * c_SV_AA[1] - c_SV_AA[0] * d_n_tmp;
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      SV_vd[3 * i] = (((SV_vd0[0] + b_n[0]) + y[0]) - n[0]) -
                     (d_n_tmp * T[2] - T[1] * b_n_tmp);
      SV_vd[c_n_tmp] = (((SV_vd0[1] + b_n[1]) + y[1]) - n[1]) -
                       (T[0] * b_n_tmp - e_n_tmp * T[2]);
      SV_vd[n_tmp] = (((SV_vd0[2] + b_n[2]) + y[2]) - n[2]) -
                     (e_n_tmp * T[1] - T[0] * d_n_tmp);
      /*  Prismatic joint */
      /*  Current (i-th) link doesn't have connection with the 0-th link */
    } else {
      c_i = i1 * 3;
      for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
        b_i = 3 * ((SV_AA_tmp + c_i) - 3);
        A_I_BB[3 * SV_AA_tmp] = SV_AA[b_i];
        A_I_BB[3 * SV_AA_tmp + 1] = SV_AA[b_i + 1];
        A_I_BB[3 * SV_AA_tmp + 2] = SV_AA[b_i + 2];
      }
      b_i = (i + 1) * 3 - 3;
      for (c_i = 0; c_i < 3; c_i++) {
        A_I_i_tmp = 3 * (c_i + b_i);
        A_I_i[3 * c_i] = SV_AA[A_I_i_tmp];
        A_I_i[3 * c_i + 1] = SV_AA[A_I_i_tmp + 1];
        A_I_i[3 * c_i + 2] = SV_AA[A_I_i_tmp + 2];
      }
      /*  Rotational joint */
      for (b_i = 0; b_i < 3; b_i++) {
        d = (A_I_i[b_i] * 0.0 + A_I_i[b_i + 3] * 0.0) + A_I_i[b_i + 6];
        F[b_i] = d;
        y[b_i] = d * SV_qd[i];
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      n_tmp = 3 * i + 2;
      b_n_tmp = SV_ww[n_tmp];
      c_n_tmp = 3 * i + 1;
      d_n_tmp = SV_ww[c_n_tmp];
      e_n_tmp = SV_ww[3 * i];
      A_I_i_tmp = 3 * (i1 - 1);
      d = SV_qdd[i];
      b_n[1] =
          (SV_wd[A_I_i_tmp + 1] + (y[0] * b_n_tmp - e_n_tmp * y[2])) + F[1] * d;
      b_n[2] =
          (SV_wd[A_I_i_tmp + 2] + (e_n_tmp * y[1] - y[0] * d_n_tmp)) + F[2] * d;
      SV_wd[3 * i] =
          (SV_wd[A_I_i_tmp] + (d_n_tmp * y[2] - y[1] * b_n_tmp)) + F[0] * d;
      SV_wd[c_n_tmp] = b_n[1];
      SV_wd[n_tmp] = b_n[2];
      b_i = A_I_i_tmp + 63 * i;
      c_F_tmp = dv1[b_i];
      b_F_tmp = dv1[b_i + 1];
      F_tmp = dv1[b_i + 2];
      for (c_i = 0; c_i < 3; c_i++) {
        y[c_i] = (A_I_BB[c_i] * c_F_tmp + A_I_BB[c_i + 3] * b_F_tmp) +
                 A_I_BB[c_i + 6] * F_tmp;
      }
      d = dv1[66 * i];
      d1 = dv1[66 * i + 1];
      d2 = dv1[66 * i + 2];
      for (c_i = 0; c_i < 3; c_i++) {
        T[c_i] = (A_I_BB[c_i] * c_F_tmp + A_I_BB[c_i + 3] * b_F_tmp) +
                 A_I_BB[c_i + 6] * F_tmp;
        b_SV_AA_tmp =
            (A_I_i[c_i] * d + A_I_i[c_i + 3] * d1) + A_I_i[c_i + 6] * d2;
        c_SV_AA[c_i] = b_SV_AA_tmp;
        F[c_i] = b_SV_AA_tmp;
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      b_i = 3 * (i1 - 1) + 2;
      c_F_tmp = SV_wd[b_i];
      SV_AA_tmp = 3 * (i1 - 1) + 1;
      b_F_tmp = SV_wd[SV_AA_tmp];
      b_n[0] = b_F_tmp * y[2] - y[1] * c_F_tmp;
      F_tmp = SV_wd[A_I_i_tmp];
      b_n[1] = y[0] * c_F_tmp - F_tmp * y[2];
      b_n[2] = F_tmp * y[1] - y[0] * b_F_tmp;
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      c_F_tmp = SV_ww[b_i];
      b_F_tmp = SV_ww[SV_AA_tmp];
      n[0] = b_F_tmp * T[2] - T[1] * c_F_tmp;
      F_tmp = SV_ww[A_I_i_tmp];
      n[1] = T[0] * c_F_tmp - F_tmp * T[2];
      n[2] = F_tmp * T[1] - T[0] * b_F_tmp;
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      y[0] = b_F_tmp * n[2] - n[1] * c_F_tmp;
      y[1] = n[0] * c_F_tmp - F_tmp * n[2];
      y[2] = F_tmp * n[1] - n[0] * b_F_tmp;
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      c_F_tmp = SV_wd[n_tmp];
      b_F_tmp = SV_wd[c_n_tmp];
      n[0] = b_F_tmp * F[2] - F[1] * c_F_tmp;
      F_tmp = SV_wd[3 * i];
      n[1] = F[0] * c_F_tmp - F_tmp * F[2];
      n[2] = F_tmp * F[1] - F[0] * b_F_tmp;
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      T[0] = d_n_tmp * c_SV_AA[2] - c_SV_AA[1] * b_n_tmp;
      T[1] = c_SV_AA[0] * b_n_tmp - e_n_tmp * c_SV_AA[2];
      T[2] = e_n_tmp * c_SV_AA[1] - c_SV_AA[0] * d_n_tmp;
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      b_n[0] = (((SV_vd[A_I_i_tmp] + b_n[0]) + y[0]) - n[0]) -
               (d_n_tmp * T[2] - T[1] * b_n_tmp);
      b_n[1] = (((SV_vd[A_I_i_tmp + 1] + b_n[1]) + y[1]) - n[1]) -
               (T[0] * b_n_tmp - e_n_tmp * T[2]);
      b_n[2] = (((SV_vd[A_I_i_tmp + 2] + b_n[2]) + y[2]) - n[2]) -
               (e_n_tmp * T[1] - T[0] * d_n_tmp);
      SV_vd[3 * i] = b_n[0];
      SV_vd[c_n_tmp] = b_n[1];
      SV_vd[n_tmp] = b_n[2];
      /*  Prismatic joint */
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /* %%EOF */
  /*  Calculation of inertia force & torque of link 0 */
  /*  NOTE:	FF,TT(FF0,TT0) are in the Inertial frame. */
  for (c_i = 0; c_i < 3; c_i++) {
    d = SV_A0[c_i];
    d1 = SV_A0[c_i + 3];
    d2 = SV_A0[c_i + 6];
    for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
      b_SV_AA[c_i + 3 * SV_AA_tmp] =
          (d * b[3 * SV_AA_tmp] + d1 * b[3 * SV_AA_tmp + 1]) +
          d2 * b[3 * SV_AA_tmp + 2];
    }
    d = b_SV_AA[c_i];
    d1 = b_SV_AA[c_i + 3];
    d2 = b_SV_AA[c_i + 6];
    F_tmp = 0.0;
    for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
      b_F_tmp = (d * SV_A0[SV_AA_tmp] + d1 * SV_A0[SV_AA_tmp + 3]) +
                d2 * SV_A0[SV_AA_tmp + 6];
      A_I_BB[c_i + 3 * SV_AA_tmp] = b_F_tmp;
      F_tmp += b_F_tmp * SV_w0[SV_AA_tmp];
    }
    y[c_i] = F_tmp;
  }
  /* CROSS	Vector cross product */
  /*  */
  /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
  /*  */
  /* 	Copyright (C) Peter Corke 1990 */
  /*  */
  b_n[0] = SV_w0[1] * y[2] - y[1] * SV_w0[2];
  b_n[1] = y[0] * SV_w0[2] - SV_w0[0] * y[2];
  b_n[2] = SV_w0[0] * y[1] - y[0] * SV_w0[1];
  /*  Calculation of inertia force & torque of link i */
  /*  from link 1 to n */
  /*  Single or multi body ? */
  /*  If a Multi body system, */
  for (i = 0; i < 21; i++) {
    real_T b_A_I_i[9];
    SV_AA_tmp = (i + 1) * 3 - 3;
    for (c_i = 0; c_i < 3; c_i++) {
      b_i = c_i + 3 * i;
      FF[b_i] = b_dv[i] * SV_vd[b_i];
      b_i = 3 * (c_i + SV_AA_tmp);
      A_I_i[3 * c_i] = SV_AA[b_i];
      b_SV_AA[3 * c_i] = b_dv1[b_i];
      A_I_i_tmp = 3 * c_i + 1;
      A_I_i[A_I_i_tmp] = SV_AA[b_i + 1];
      b_SV_AA[A_I_i_tmp] = b_dv1[b_i + 1];
      A_I_i_tmp = 3 * c_i + 2;
      A_I_i[A_I_i_tmp] = SV_AA[b_i + 2];
      b_SV_AA[A_I_i_tmp] = b_dv1[b_i + 2];
    }
    for (c_i = 0; c_i < 3; c_i++) {
      d = A_I_i[c_i];
      d1 = A_I_i[c_i + 3];
      d2 = A_I_i[c_i + 6];
      for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
        b_A_I_i[c_i + 3 * SV_AA_tmp] =
            (d * b_SV_AA[3 * SV_AA_tmp] + d1 * b_SV_AA[3 * SV_AA_tmp + 1]) +
            d2 * b_SV_AA[3 * SV_AA_tmp + 2];
      }
    }
    for (c_i = 0; c_i < 3; c_i++) {
      d = b_A_I_i[c_i];
      d1 = b_A_I_i[c_i + 3];
      d2 = b_A_I_i[c_i + 6];
      F_tmp = 0.0;
      for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
        b_F_tmp = (d * A_I_i[SV_AA_tmp] + d1 * A_I_i[SV_AA_tmp + 3]) +
                  d2 * A_I_i[SV_AA_tmp + 6];
        b_SV_AA[c_i + 3 * SV_AA_tmp] = b_F_tmp;
        F_tmp += b_F_tmp * SV_ww[SV_AA_tmp + 3 * i];
      }
      y[c_i] = F_tmp;
    }
    /* CROSS	Vector cross product */
    /*  */
    /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
    /*  */
    /* 	Copyright (C) Peter Corke 1990 */
    /*  */
    c_i = 3 * i + 1;
    d = SV_ww[c_i];
    SV_AA_tmp = 3 * i + 2;
    d1 = SV_ww[SV_AA_tmp];
    n[0] = d * y[2] - y[1] * d1;
    d2 = SV_ww[3 * i];
    n[1] = y[0] * d1 - d2 * y[2];
    n[2] = d2 * y[1] - y[0] * d;
    d = SV_wd[3 * i];
    d1 = SV_wd[c_i];
    d2 = SV_wd[SV_AA_tmp];
    for (c_i = 0; c_i < 3; c_i++) {
      TT[c_i + 3 * i] =
          ((b_SV_AA[c_i] * d + b_SV_AA[c_i + 3] * d1) + b_SV_AA[c_i + 6] * d2) +
          n[c_i];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  Equilibrium of forces & torques on each link */
  /*  On the i-th link */
  memset(&Fj[0], 0, 63U * sizeof(real_T));
  memset(&Tj[0], 0, 63U * sizeof(real_T));
  /*  Multi body system */
  /*  from link n to 1 */
  for (i = 0; i < 21; i++) {
    real_T c_Fj_tmp;
    real_T d_Fj_tmp;
    real_T e_Fj_tmp;
    int32_T Fj_tmp;
    int32_T b_Fj_tmp;
    F[0] = 0.0;
    T[0] = 0.0;
    F[1] = 0.0;
    T[1] = 0.0;
    F[2] = 0.0;
    T[2] = 0.0;
    for (j = 0; j < i; j++) {
      A_I_i_tmp = (j - i) + 21;
      if (A_I_i_tmp + 1 > 21) {
        emlrtDynamicBoundsCheckR2012b(A_I_i_tmp + 1, 1, 21, &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_i = iv2[20 - (i - 21 * A_I_i_tmp)];
      F[0] += (real_T)b_i * Fj[3 * A_I_i_tmp];
      F[1] += (real_T)b_i * Fj[3 * A_I_i_tmp + 1];
      F[2] += (real_T)b_i * Fj[3 * A_I_i_tmp + 2];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    Fj_tmp = 3 * (20 - i);
    b_Fj_tmp = iv1[20 - i];
    c_F_tmp = FF[Fj_tmp];
    c_Fj_tmp = SV_Fe[Fj_tmp];
    Fj[Fj_tmp] = (c_F_tmp + F[0]) + (real_T)b_Fj_tmp * c_Fj_tmp;
    b_F_tmp = FF[Fj_tmp + 1];
    d_Fj_tmp = SV_Fe[Fj_tmp + 1];
    Fj[Fj_tmp + 1] = (b_F_tmp + F[1]) + (real_T)b_Fj_tmp * d_Fj_tmp;
    F_tmp = FF[Fj_tmp + 2];
    e_Fj_tmp = SV_Fe[Fj_tmp + 2];
    Fj[Fj_tmp + 2] = (F_tmp + F[2]) + (real_T)b_Fj_tmp * e_Fj_tmp;
    if (i - 1 >= 0) {
      i2 = (21 - i) * 3 - 3;
    }
    for (j = 0; j < i; j++) {
      A_I_i_tmp = (j - i) + 21;
      if (A_I_i_tmp + 1 > 21) {
        emlrtDynamicBoundsCheckR2012b(A_I_i_tmp + 1, 1, 21, &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (c_i = 0; c_i < 3; c_i++) {
        SV_AA_tmp = 3 * (c_i + i2);
        b_SV_AA[3 * c_i] = SV_AA[SV_AA_tmp];
        b_SV_AA[3 * c_i + 1] = SV_AA[SV_AA_tmp + 1];
        b_SV_AA[3 * c_i + 2] = SV_AA[SV_AA_tmp + 2];
        SV_AA_tmp = c_i + Fj_tmp;
        c_SV_AA[c_i] =
            (dv1[SV_AA_tmp + 63 * A_I_i_tmp] - dv1[SV_AA_tmp + 63 * (20 - i)]) +
            0.0 * SV_q[20 - i];
      }
      d = c_SV_AA[0];
      d1 = c_SV_AA[1];
      d2 = c_SV_AA[2];
      for (c_i = 0; c_i < 3; c_i++) {
        y[c_i] =
            (b_SV_AA[c_i] * d + b_SV_AA[c_i + 3] * d1) + b_SV_AA[c_i + 6] * d2;
      }
      b_i = iv2[(21 * A_I_i_tmp - i) + 20];
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      n_tmp = 3 * A_I_i_tmp + 2;
      b_n_tmp = Fj[n_tmp];
      c_n_tmp = 3 * A_I_i_tmp + 1;
      d_n_tmp = Fj[c_n_tmp];
      e_n_tmp = Fj[3 * A_I_i_tmp];
      T[0] +=
          (real_T)b_i * ((y[1] * b_n_tmp - d_n_tmp * y[2]) + Tj[3 * A_I_i_tmp]);
      T[1] += (real_T)b_i * ((e_n_tmp * y[2] - y[0] * b_n_tmp) + Tj[c_n_tmp]);
      T[2] += (real_T)b_i * ((y[0] * d_n_tmp - e_n_tmp * y[1]) + Tj[n_tmp]);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    c_i = (21 - i) * 3 - 3;
    for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
      A_I_i_tmp = 3 * (SV_AA_tmp + c_i);
      A_I_i[3 * SV_AA_tmp] = SV_AA[A_I_i_tmp];
      A_I_i[3 * SV_AA_tmp + 1] = SV_AA[A_I_i_tmp + 1];
      A_I_i[3 * SV_AA_tmp + 2] = SV_AA[A_I_i_tmp + 2];
    }
    /*  Rotational joint */
    c_i = Fj_tmp + 63 * (20 - i);
    for (SV_AA_tmp = 0; SV_AA_tmp < 3; SV_AA_tmp++) {
      y[SV_AA_tmp] =
          (A_I_i[SV_AA_tmp] * dv1[c_i] + A_I_i[SV_AA_tmp + 3] * dv1[c_i + 1]) +
          A_I_i[SV_AA_tmp + 6] * dv1[c_i + 2];
    }
    /* CROSS	Vector cross product */
    /*  */
    /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
    /*  */
    /* 	Copyright (C) Peter Corke 1990 */
    /*  */
    d = (TT[Fj_tmp] + T[0]) - (y[1] * F_tmp - b_F_tmp * y[2]);
    b_SV_AA_tmp = 0.0 * SV_q[20 - i];
    d1 = (TT[Fj_tmp + 1] + T[1]) - (c_F_tmp * y[2] - y[0] * F_tmp);
    d2 = (TT[Fj_tmp + 2] + T[2]) - (y[0] * b_F_tmp - c_F_tmp * y[1]);
    F_tmp = (dv2[Fj_tmp] - dv1[3 * (20 - i) + 63 * (20 - i)]) + b_SV_AA_tmp;
    b_F_tmp = (dv2[Fj_tmp + 1] - dv1[(3 * (20 - i) + 63 * (20 - i)) + 1]) +
              b_SV_AA_tmp;
    c_F_tmp = (dv2[Fj_tmp + 2] - dv1[(3 * (20 - i) + 63 * (20 - i)) + 2]) +
              b_SV_AA_tmp;
    for (c_i = 0; c_i < 3; c_i++) {
      y[c_i] = (A_I_i[c_i] * F_tmp + A_I_i[c_i + 3] * b_F_tmp) +
               A_I_i[c_i + 6] * c_F_tmp;
    }
    /* CROSS	Vector cross product */
    /*  */
    /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
    /*  */
    /* 	Copyright (C) Peter Corke 1990 */
    /*  */
    d += (real_T)b_Fj_tmp *
         ((y[1] * e_Fj_tmp - d_Fj_tmp * y[2]) + SV_Te[Fj_tmp]);
    Tj[Fj_tmp] = d;
    d1 += (real_T)b_Fj_tmp *
          ((c_Fj_tmp * y[2] - y[0] * e_Fj_tmp) + SV_Te[Fj_tmp + 1]);
    Tj[Fj_tmp + 1] = d1;
    d2 += (real_T)b_Fj_tmp *
          ((y[0] * d_Fj_tmp - c_Fj_tmp * y[1]) + SV_Te[Fj_tmp + 2]);
    Tj[Fj_tmp + 2] = d2;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  Equilibrium on the link 0 */
  F[0] = 0.0;
  T[0] = 0.0;
  F[1] = 0.0;
  T[1] = 0.0;
  F[2] = 0.0;
  T[2] = 0.0;
  for (i = 0; i < 21; i++) {
    if (b_iv[i] != 0) {
      F[0] += Fj[3 * i];
      F[1] += Fj[3 * i + 1];
      F[2] += Fj[3 * i + 2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  for (i = 0; i < 21; i++) {
    if (b_iv[i] != 0) {
      d = dv[3 * i];
      c_i = 3 * i + 1;
      d1 = dv[c_i];
      SV_AA_tmp = 3 * i + 2;
      d2 = dv[SV_AA_tmp];
      for (i2 = 0; i2 < 3; i2++) {
        y[i2] = (SV_A0[i2] * d + SV_A0[i2 + 3] * d1) + SV_A0[i2 + 6] * d2;
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      d = Fj[SV_AA_tmp];
      d1 = Fj[c_i];
      d2 = Fj[3 * i];
      T[0] += (y[1] * d - d1 * y[2]) + Tj[3 * i];
      T[1] += (d2 * y[2] - y[0] * d) + Tj[c_i];
      T[2] += (y[0] * d1 - d2 * y[1]) + Tj[SV_AA_tmp];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  Calculation of torques of each joint */
  /*  Single body */
  /*  Multi body system */
  for (i = 0; i < 21; i++) {
    /*  Rotational joint */
    b_i = (i + 1) * 3 - 3;
    for (c_i = 0; c_i < 3; c_i++) {
      SV_AA_tmp = 3 * (c_i + b_i);
      b_SV_AA[3 * c_i] = SV_AA[SV_AA_tmp];
      b_SV_AA[3 * c_i + 1] = SV_AA[SV_AA_tmp + 1];
      b_SV_AA[3 * c_i + 2] = SV_AA[SV_AA_tmp + 2];
    }
    c_F_tmp = 0.0;
    for (c_i = 0; c_i < 3; c_i++) {
      c_F_tmp +=
          Tj[c_i + 3 * i] *
          ((b_SV_AA[c_i] * 0.0 + b_SV_AA[c_i + 3] * 0.0) + b_SV_AA[c_i + 6]);
    }
    SV_tau[i] = c_F_tmp;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  Compose a generalized force */
  /*  Single or multi body ? */
  /*  Multi body system, */
  d = SV_wd0[0];
  d1 = SV_wd0[1];
  d2 = SV_wd0[2];
  for (c_i = 0; c_i < 3; c_i++) {
    Force[c_i] = 5.7514 * SV_vd0[c_i] + F[c_i];
    Force[c_i + 3] =
        (((A_I_BB[c_i] * d + A_I_BB[c_i + 3] * d1) + A_I_BB[c_i + 6] * d2) +
         b_n[c_i]) +
        T[c_i];
  }
  memcpy(&Force[6], &SV_tau[0], 21U * sizeof(real_T));
  /* %%EOF */
}

/* End of code generation (r_ne.c) */
