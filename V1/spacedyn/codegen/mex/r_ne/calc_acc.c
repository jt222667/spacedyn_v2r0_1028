/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_acc.c
 *
 * Code generation for function 'calc_acc'
 *
 */

/* Include files */
#include "calc_acc.h"
#include "r_ne_data.h"
#include "r_ne_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo j_emlrtRTEI = {
    38,         /* lineNo */
    12,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    74,         /* lineNo */
    27,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m" /* pName */
};

static emlrtDCInfo n_emlrtDCI = {
    79,         /* lineNo */
    34,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    79,         /* lineNo */
    34,         /* colNo */
    "SV.wd",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    81,         /* lineNo */
    34,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    81,         /* lineNo */
    34,         /* colNo */
    "SV.vd",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = {
    82,         /* lineNo */
    33,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    82,         /* lineNo */
    33,         /* colNo */
    "SV.wd",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    82,         /* lineNo */
    59,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    82,         /* lineNo */
    59,         /* colNo */
    "LP.cc",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = {
    83,         /* lineNo */
    33,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    83,         /* lineNo */
    33,         /* colNo */
    "SV.ww",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = {
    83,         /* lineNo */
    57,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    83,         /* lineNo */
    57,         /* colNo */
    "SV.ww",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = {
    83,         /* lineNo */
    83,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    83,         /* lineNo */
    83,         /* colNo */
    "LP.cc",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    89,         /* lineNo */
    34,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    89,         /* lineNo */
    34,         /* colNo */
    "SV.wd",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = {
    90,         /* lineNo */
    34,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = {
    91,         /* lineNo */
    33,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = {
    91,         /* lineNo */
    59,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = {
    92,         /* lineNo */
    33,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = {
    92,         /* lineNo */
    57,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    41,         /* lineNo */
    16,         /* colNo */
    "LP.BB",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    1,          /* iFirst */
    63,         /* iLast */
    74,         /* lineNo */
    27,         /* colNo */
    "SV.AA",    /* aName */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = {
    74,         /* lineNo */
    27,         /* colNo */
    "calc_acc", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\Copy_of_spacedyn_"
    "v2r0\\spacedyn\\calc_acc.m", /* pName */
    1                             /* checkKind */
};

/* Function Definitions */
void calc_acc(const emlrtStack *sp, real_T LP_num_q, const char_T LP_J_type[21],
              const real_T LP_BB[21], const real_T LP_cc[1386],
              const real_T LP_c0[63], struct1_T *SV)
{
  real_T b[3];
  real_T n[3];
  int32_T b_i;
  int32_T c_i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
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
  if (LP_num_q == 0.0) {
    memset(&SV->vd[0], 0, 63U * sizeof(real_T));
    memset(&SV->wd[0], 0, 63U * sizeof(real_T));
    /*  If Multi body system */
  } else {
    int32_T i;
    /*  Calcuration of coordinate transfromation matrices */
    /*  Calculation of acceletion vectors vd,wd */
    i = (int32_T)LP_num_q;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP_num_q, mxDOUBLE_CLASS,
                                  (int32_T)LP_num_q, &j_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (b_i = 0; b_i < i; b_i++) {
      real_T b_idx_1;
      /*  Check the link connection: Is the lower one of this link, 0 ? */
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > 21)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                      &xb_emlrtBCI, (emlrtConstCTX)sp);
      }
      b_idx_1 = LP_BB[b_i];
      if (b_idx_1 == 0.0) {
        real_T A_I_i[9];
        int32_T A_I_BB_tmp;
        /*  If the i-th link connects with 0-th link */
        c_i = (b_i + 1) * 3 - 3;
        for (i1 = 0; i1 < 3; i1++) {
          A_I_BB_tmp = 3 * (i1 + c_i);
          A_I_i[3 * i1] = SV->AA[A_I_BB_tmp];
          A_I_i[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
          A_I_i[3 * i1 + 2] = SV->AA[A_I_BB_tmp + 2];
        }
        /*  Rotational joint */
        if (LP_J_type[b_i] == 'R') {
          real_T b_A_I_i[3];
          real_T b_SV[3];
          real_T c_A_I_i[3];
          real_T d_A_I_i[3];
          real_T y[3];
          real_T SV_tmp_tmp;
          real_T b_SV_tmp_tmp;
          real_T b_n_tmp;
          real_T b_tmp;
          real_T c_n_tmp;
          real_T d;
          real_T d1;
          real_T d2;
          int32_T n_tmp;
          for (c_i = 0; c_i < 3; c_i++) {
            b_idx_1 =
                (A_I_i[c_i] * 0.0 + A_I_i[c_i + 3] * 0.0) + A_I_i[c_i + 6];
            b_SV[c_i] = b_idx_1;
            b_A_I_i[c_i] = b_idx_1 * SV->qd[b_i];
          }
          real_T c_SV;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          n_tmp = 3 * b_i + 2;
          b_n_tmp = SV->ww[n_tmp];
          c_i = 3 * b_i + 1;
          c_n_tmp = SV->ww[c_i];
          SV_tmp_tmp = SV->ww[3 * b_i];
          c_SV = SV->qdd[b_i];
          SV->wd[3 * b_i] =
              (SV->wd0[0] + (c_n_tmp * b_A_I_i[2] - b_A_I_i[1] * b_n_tmp)) +
              b_SV[0] * c_SV;
          SV->wd[c_i] =
              (SV->wd0[1] + (b_A_I_i[0] * b_n_tmp - SV_tmp_tmp * b_A_I_i[2])) +
              b_SV[1] * c_SV;
          SV->wd[n_tmp] =
              (SV->wd0[2] + (SV_tmp_tmp * b_A_I_i[1] - b_A_I_i[0] * c_n_tmp)) +
              b_SV[2] * c_SV;
          b_idx_1 = LP_c0[3 * b_i];
          d = LP_c0[c_i];
          d1 = LP_c0[n_tmp];
          d2 = LP_cc[66 * b_i];
          b_SV_tmp_tmp = LP_cc[66 * b_i + 1];
          b_tmp = LP_cc[66 * b_i + 2];
          for (i1 = 0; i1 < 3; i1++) {
            real_T y_tmp;
            y_tmp = (A_I_i[i1] * d2 + A_I_i[i1 + 3] * b_SV_tmp_tmp) +
                    A_I_i[i1 + 6] * b_tmp;
            y[i1] = y_tmp;
            c_A_I_i[i1] = y_tmp;
            SV_tmp_tmp = (SV->A0[i1] * b_idx_1 + SV->A0[i1 + 3] * d) +
                         SV->A0[i1 + 6] * d1;
            d_A_I_i[i1] = SV_tmp_tmp;
            b_A_I_i[i1] = SV_tmp_tmp;
          }
          real_T b_n[3];
          real_T c_n[3];
          real_T d_n[3];
          real_T d_n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d2 = SV->wd0[1] * b_A_I_i[2] - b_A_I_i[1] * SV->wd0[2];
          d = b_A_I_i[0] * SV->wd0[2] - SV->wd0[0] * b_A_I_i[2];
          d1 = SV->wd0[0] * b_A_I_i[1] - b_A_I_i[0] * SV->wd0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n[0] = SV->w0[1] * d_A_I_i[2] - d_A_I_i[1] * SV->w0[2];
          b_n[1] = d_A_I_i[0] * SV->w0[2] - SV->w0[0] * d_A_I_i[2];
          b_n[2] = SV->w0[0] * d_A_I_i[1] - d_A_I_i[0] * SV->w0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          c_n[0] = SV->w0[1] * b_n[2] - b_n[1] * SV->w0[2];
          c_n[1] = b_n[0] * SV->w0[2] - SV->w0[0] * b_n[2];
          c_n[2] = SV->w0[0] * b_n[1] - b_n[0] * SV->w0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n_tmp = SV->wd[n_tmp];
          c_n_tmp = SV->wd[c_i];
          d_n_tmp = SV->wd[3 * b_i];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d_n[0] = SV->ww[c_i] * y[2] - y[1] * SV->ww[n_tmp];
          d_n[1] = y[0] * SV->ww[n_tmp] - SV->ww[3 * b_i] * y[2];
          d_n[2] = SV->ww[3 * b_i] * y[1] - y[0] * SV->ww[c_i];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_idx_1 = SV->ww[n_tmp];
          b_SV_tmp_tmp = SV->ww[3 * b_i];
          b_tmp = SV->ww[3 * b_i];
          SV_tmp_tmp = SV->ww[c_i];
          SV->vd[3 * b_i] = (((SV->vd0[0] + d2) + c_n[0]) -
                             (c_n_tmp * c_A_I_i[2] - c_A_I_i[1] * b_n_tmp)) -
                            (SV->ww[c_i] * d_n[2] - d_n[1] * SV->ww[n_tmp]);
          SV->vd[c_i] = (((SV->vd0[1] + d) + c_n[1]) -
                         (c_A_I_i[0] * b_n_tmp - d_n_tmp * c_A_I_i[2])) -
                        (d_n[0] * b_idx_1 - b_SV_tmp_tmp * d_n[2]);
          SV->vd[n_tmp] = (((SV->vd0[2] + d1) + c_n[2]) -
                           (d_n_tmp * c_A_I_i[1] - c_A_I_i[0] * c_n_tmp)) -
                          (b_tmp * d_n[1] - d_n[0] * SV_tmp_tmp);
          /*  Prismatic joint */
        } else {
          real_T b_A_I_i[3];
          real_T b_SV[3];
          real_T c_A_I_i[3];
          real_T d_A_I_i[3];
          real_T y[3];
          real_T SV_tmp_tmp;
          real_T b_SV_tmp_tmp;
          real_T b_tmp;
          real_T d;
          real_T d1;
          real_T d2;
          int32_T n_tmp;
          b_idx_1 = LP_cc[66 * b_i];
          d = LP_c0[3 * b_i];
          A_I_BB_tmp = 3 * b_i + 1;
          d1 = LP_c0[A_I_BB_tmp];
          n_tmp = 3 * b_i + 2;
          d2 = LP_c0[n_tmp];
          i1 = 66 * b_i;
          for (c_i = 0; c_i < 3; c_i++) {
            SV->wd[c_i + 3 * b_i] = SV->wd0[c_i];
            b_SV_tmp_tmp = A_I_i[c_i];
            b_tmp = b_SV_tmp_tmp * 0.0;
            SV_tmp_tmp = b_SV_tmp_tmp * b_idx_1;
            b_SV_tmp_tmp = A_I_i[c_i + 3];
            b_tmp += b_SV_tmp_tmp * 0.0;
            SV_tmp_tmp += b_SV_tmp_tmp * LP_cc[i1 + 1];
            b_SV_tmp_tmp = A_I_i[c_i + 6];
            b_tmp += b_SV_tmp_tmp;
            SV_tmp_tmp += b_SV_tmp_tmp * LP_cc[i1 + 2];
            c_A_I_i[c_i] = SV_tmp_tmp;
            y[c_i] = b_tmp;
            b_SV[c_i] =
                (SV->A0[c_i] * d + SV->A0[c_i + 3] * d1) + SV->A0[c_i + 6] * d2;
            d_A_I_i[c_i] = b_tmp * SV->q[b_i];
            b_A_I_i[c_i] = b_tmp * SV->qd[b_i];
          }
          real_T b_n[3];
          real_T c_n[3];
          real_T d_n[3];
          real_T b_idx_2;
          real_T b_n_tmp;
          real_T c_SV;
          real_T c_n_tmp;
          real_T d_n_tmp;
          real_T y_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          SV_tmp_tmp = SV->ww[n_tmp];
          b_SV_tmp_tmp = SV->ww[A_I_BB_tmp];
          b_tmp = b_SV_tmp_tmp * b_A_I_i[2] - b_A_I_i[1] * SV_tmp_tmp;
          y_tmp = SV->ww[3 * b_i];
          b_idx_1 = b_A_I_i[0] * SV_tmp_tmp - y_tmp * b_A_I_i[2];
          b_idx_2 = y_tmp * b_A_I_i[1] - b_A_I_i[0] * b_SV_tmp_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d2 = SV->wd0[1] * b_SV[2] - b_SV[1] * SV->wd0[2];
          d = b_SV[0] * SV->wd0[2] - SV->wd0[0] * b_SV[2];
          d1 = SV->wd0[0] * b_SV[1] - b_SV[0] * SV->wd0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n[0] = SV->w0[1] * b_SV[2] - b_SV[1] * SV->w0[2];
          b_n[1] = b_SV[0] * SV->w0[2] - SV->w0[0] * b_SV[2];
          b_n[2] = SV->w0[0] * b_SV[1] - b_SV[0] * SV->w0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          c_n[0] = SV->w0[1] * b_n[2] - b_n[1] * SV->w0[2];
          c_n[1] = b_n[0] * SV->w0[2] - SV->w0[0] * b_n[2];
          c_n[2] = SV->w0[0] * b_n[1] - b_n[0] * SV->w0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n_tmp = SV->wd[n_tmp];
          c_n_tmp = SV->wd[A_I_BB_tmp];
          b_n[0] = c_n_tmp * d_A_I_i[2] - d_A_I_i[1] * b_n_tmp;
          d_n_tmp = SV->wd[3 * b_i];
          b_n[1] = d_A_I_i[0] * b_n_tmp - d_n_tmp * d_A_I_i[2];
          b_n[2] = d_n_tmp * d_A_I_i[1] - d_A_I_i[0] * c_n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d_n[0] = b_SV_tmp_tmp * d_A_I_i[2] - d_A_I_i[1] * SV_tmp_tmp;
          d_n[1] = d_A_I_i[0] * SV_tmp_tmp - y_tmp * d_A_I_i[2];
          d_n[2] = y_tmp * d_A_I_i[1] - d_A_I_i[0] * b_SV_tmp_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_A_I_i[0] = b_SV_tmp_tmp * d_n[2] - d_n[1] * SV_tmp_tmp;
          b_A_I_i[1] = d_n[0] * SV_tmp_tmp - y_tmp * d_n[2];
          b_A_I_i[2] = y_tmp * d_n[1] - d_n[0] * b_SV_tmp_tmp;
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
          b_SV[0] = b_SV_tmp_tmp * c_A_I_i[2] - c_A_I_i[1] * SV_tmp_tmp;
          b_SV[1] = c_A_I_i[0] * SV_tmp_tmp - y_tmp * c_A_I_i[2];
          b_SV[2] = y_tmp * c_A_I_i[1] - c_A_I_i[0] * b_SV_tmp_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          c_SV = SV->qdd[b_i];
          SV->vd[3 * b_i] =
              (((((((SV->vd0[0] + d2) + c_n[0]) + b_n[0]) + b_A_I_i[0]) +
                 2.0 * b_tmp) +
                y[0] * c_SV) -
               (c_n_tmp * c_A_I_i[2] - c_A_I_i[1] * b_n_tmp)) -
              (b_SV_tmp_tmp * b_SV[2] - b_SV[1] * SV_tmp_tmp);
          SV->vd[A_I_BB_tmp] =
              (((((((SV->vd0[1] + d) + c_n[1]) + b_n[1]) + b_A_I_i[1]) +
                 2.0 * b_idx_1) +
                y[1] * c_SV) -
               (c_A_I_i[0] * b_n_tmp - d_n_tmp * c_A_I_i[2])) -
              (b_SV[0] * SV_tmp_tmp - y_tmp * b_SV[2]);
          SV->vd[n_tmp] =
              (((((((SV->vd0[2] + d1) + c_n[2]) + b_n[2]) + b_A_I_i[2]) +
                 2.0 * b_idx_2) +
                y[2] * c_SV) -
               (d_n_tmp * c_A_I_i[1] - c_A_I_i[0] * c_n_tmp)) -
              (y_tmp * b_SV[1] - b_SV[0] * b_SV_tmp_tmp);
        }
        /*  Current (i-th) link doesn't have connection with the 0-th link */
      } else {
        real_T A_I_BB[9];
        real_T A_I_i[9];
        real_T d;
        real_T d1;
        real_T d2;
        int32_T A_I_BB_tmp;
        d = b_idx_1 * 3.0;
        if (!(d == b_idx_1 * 3.0)) {
          emlrtErrorWithMessageIdR2018a(
              sp, &k_emlrtRTEI,
              "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
              "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
              0);
        }
        for (i1 = 0; i1 < 3; i1++) {
          d1 = d + ((real_T)i1 - 2.0);
          d2 = (int32_T)muDoubleScalarFloor(d1);
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &bb_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 63, &yb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          A_I_BB_tmp = 3 * ((int32_T)d1 - 1);
          A_I_BB[3 * i1] = SV->AA[A_I_BB_tmp];
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &bb_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 63, &yb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          A_I_BB[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
          if (d1 != d2) {
            emlrtIntegerCheckR2012b(d1, &bb_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 63, &yb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          A_I_BB[3 * i1 + 2] = SV->AA[A_I_BB_tmp + 2];
        }
        c_i = (b_i + 1) * 3 - 3;
        for (i1 = 0; i1 < 3; i1++) {
          A_I_BB_tmp = 3 * (i1 + c_i);
          A_I_i[3 * i1] = SV->AA[A_I_BB_tmp];
          A_I_i[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
          A_I_i[3 * i1 + 2] = SV->AA[A_I_BB_tmp + 2];
        }
        /*  Rotational joint */
        if (LP_J_type[b_i] == 'R') {
          real_T b_A_I_i[3];
          real_T b_n[3];
          real_T c_A_I_i[3];
          real_T c_n[3];
          real_T d_A_I_i[3];
          real_T d_n[3];
          real_T y[3];
          real_T b_n_tmp;
          real_T c_SV;
          real_T c_n_tmp;
          real_T d_n_tmp;
          int32_T e_n_tmp;
          int32_T f_n_tmp;
          int32_T g_n_tmp;
          int32_T n_tmp;
          for (c_i = 0; c_i < 3; c_i++) {
            d = (A_I_i[c_i] * 0.0 + A_I_i[c_i + 3] * 0.0) + A_I_i[c_i + 6];
            d_A_I_i[c_i] = d;
            b_A_I_i[c_i] = d * SV->qd[b_i];
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          n_tmp = 3 * b_i + 2;
          b_n_tmp = SV->ww[n_tmp];
          c_i = 3 * b_i + 1;
          c_n_tmp = SV->ww[c_i];
          d_n_tmp = SV->ww[3 * b_i];
          i1 = (int32_T)muDoubleScalarFloor(b_idx_1);
          if (b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &n_emlrtDCI, (emlrtConstCTX)sp);
          }
          if ((b_idx_1 < 1.0) || (b_idx_1 > 21.0)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)b_idx_1, 1, 21, &pb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          c_SV = SV->qdd[b_i];
          e_n_tmp = 3 * ((int32_T)b_idx_1 - 1);
          f_n_tmp = 3 * ((int32_T)b_idx_1 - 1) + 1;
          d = (SV->wd[f_n_tmp] +
               (b_A_I_i[0] * b_n_tmp - d_n_tmp * b_A_I_i[2])) +
              d_A_I_i[1] * c_SV;
          g_n_tmp = 3 * ((int32_T)b_idx_1 - 1) + 2;
          d1 = (SV->wd[g_n_tmp] +
                (d_n_tmp * b_A_I_i[1] - b_A_I_i[0] * c_n_tmp)) +
               d_A_I_i[2] * c_SV;
          SV->wd[3 * b_i] = (SV->wd[e_n_tmp] +
                             (c_n_tmp * b_A_I_i[2] - b_A_I_i[1] * b_n_tmp)) +
                            d_A_I_i[0] * c_SV;
          SV->wd[c_i] = d;
          SV->wd[n_tmp] = d1;
          if ((int32_T)b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &q_emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, 21, &sb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          i2 = 3 * (i2 - 1) + 63 * b_i;
          for (i3 = 0; i3 < 3; i3++) {
            b_A_I_i[i3] =
                (A_I_BB[i3] * LP_cc[i2] + A_I_BB[i3 + 3] * LP_cc[i2 + 1]) +
                A_I_BB[i3 + 6] * LP_cc[i2 + 2];
          }
          if ((int32_T)b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &t_emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, 21, &vb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          A_I_BB_tmp = 3 * (i2 - 1) + 63 * b_i;
          for (i2 = 0; i2 < 3; i2++) {
            real_T y_tmp;
            y_tmp = (A_I_i[i2] * LP_cc[66 * b_i] +
                     A_I_i[i2 + 3] * LP_cc[66 * b_i + 1]) +
                    A_I_i[i2 + 6] * LP_cc[66 * b_i + 2];
            y[i2] = y_tmp;
            c_A_I_i[i2] = y_tmp;
            d_A_I_i[i2] = (A_I_BB[i2] * LP_cc[A_I_BB_tmp] +
                           A_I_BB[i2 + 3] * LP_cc[A_I_BB_tmp + 1]) +
                          A_I_BB[i2 + 6] * LP_cc[A_I_BB_tmp + 2];
          }
          if ((int32_T)b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &p_emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, 21, &rb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d2 = SV->wd[f_n_tmp] * b_A_I_i[2] - b_A_I_i[1] * SV->wd[g_n_tmp];
          d = b_A_I_i[0] * SV->wd[g_n_tmp] - SV->wd[e_n_tmp] * b_A_I_i[2];
          d1 = SV->wd[e_n_tmp] * b_A_I_i[1] - b_A_I_i[0] * SV->wd[f_n_tmp];
          if ((int32_T)b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &s_emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, 21, &ub_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n_tmp = SV->ww[g_n_tmp];
          c_n_tmp = SV->ww[f_n_tmp];
          b_n[0] = c_n_tmp * d_A_I_i[2] - d_A_I_i[1] * b_n_tmp;
          d_n_tmp = SV->ww[e_n_tmp];
          b_n[1] = d_A_I_i[0] * b_n_tmp - d_n_tmp * d_A_I_i[2];
          b_n[2] = d_n_tmp * d_A_I_i[1] - d_A_I_i[0] * c_n_tmp;
          if ((int32_T)b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &r_emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, 21, &tb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          c_n[0] = c_n_tmp * b_n[2] - b_n[1] * b_n_tmp;
          c_n[1] = b_n[0] * b_n_tmp - d_n_tmp * b_n[2];
          c_n[2] = d_n_tmp * b_n[1] - b_n[0] * c_n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n_tmp = SV->wd[n_tmp];
          c_n_tmp = SV->wd[c_i];
          d_n_tmp = SV->wd[3 * b_i];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d_n[0] = SV->ww[c_i] * y[2] - y[1] * SV->ww[n_tmp];
          d_n[1] = y[0] * SV->ww[n_tmp] - SV->ww[3 * b_i] * y[2];
          d_n[2] = SV->ww[3 * b_i] * y[1] - y[0] * SV->ww[c_i];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          if ((int32_T)b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &o_emlrtDCI, (emlrtConstCTX)sp);
          }
          if ((b_idx_1 < 1.0) || (b_idx_1 > 21.0)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)b_idx_1, 1, 21, &qb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          d2 = (((SV->vd[e_n_tmp] + d2) + c_n[0]) -
                (c_n_tmp * c_A_I_i[2] - c_A_I_i[1] * b_n_tmp)) -
               (SV->ww[c_i] * d_n[2] - d_n[1] * SV->ww[n_tmp]);
          d = (((SV->vd[f_n_tmp] + d) + c_n[1]) -
               (c_A_I_i[0] * b_n_tmp - d_n_tmp * c_A_I_i[2])) -
              (d_n[0] * SV->ww[n_tmp] - SV->ww[3 * b_i] * d_n[2]);
          d1 = (((SV->vd[g_n_tmp] + d1) + c_n[2]) -
                (d_n_tmp * c_A_I_i[1] - c_A_I_i[0] * c_n_tmp)) -
               (SV->ww[3 * b_i] * d_n[1] - d_n[0] * SV->ww[c_i]);
          SV->vd[3 * b_i] = d2;
          SV->vd[c_i] = d;
          SV->vd[n_tmp] = d1;
          /*  Prismatic joint */
        } else {
          real_T b_A_I_i[3];
          real_T b_SV[3];
          real_T b_n[3];
          real_T c_A_I_i[3];
          real_T c_n[3];
          real_T d_A_I_i[3];
          real_T d_n[3];
          real_T y[3];
          real_T SV_tmp_tmp;
          real_T b_SV_tmp_tmp;
          real_T b_n_tmp;
          real_T b_tmp;
          real_T c_SV;
          real_T c_n_tmp;
          real_T d_n_tmp;
          int32_T n_tmp;
          i1 = (int32_T)muDoubleScalarFloor(b_idx_1);
          if (b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &u_emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)b_idx_1;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)b_idx_1, 1, 21, &wb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          A_I_BB_tmp = 3 * (i2 - 1);
          SV_tmp_tmp = SV->wd[A_I_BB_tmp + 1];
          b_SV_tmp_tmp = SV->wd[A_I_BB_tmp + 2];
          SV->wd[3 * b_i] = SV->wd[A_I_BB_tmp];
          i3 = 3 * b_i + 1;
          SV->wd[i3] = SV_tmp_tmp;
          n_tmp = 3 * b_i + 2;
          SV->wd[n_tmp] = b_SV_tmp_tmp;
          if (i2 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &x_emlrtDCI, (emlrtConstCTX)sp);
          }
          c_SV = SV->q[b_i];
          SV_tmp_tmp = SV->q[b_i];
          b_SV_tmp_tmp = SV->qd[b_i];
          i2 = A_I_BB_tmp + 63 * b_i;
          for (c_i = 0; c_i < 3; c_i++) {
            b_idx_1 = A_I_i[c_i] * 0.0 + A_I_i[c_i + 3] * 0.0;
            d = A_I_i[c_i + 6];
            b_SV[c_i] =
                (A_I_BB[c_i] * LP_cc[i2] + A_I_BB[c_i + 3] * LP_cc[i2 + 1]) +
                A_I_BB[c_i + 6] *
                    LP_cc[(3 * ((int32_T)LP_BB[b_i] - 1) + 63 * b_i) + 2];
            b_A_I_i[c_i] = (b_idx_1 + d) * c_SV;
            d_A_I_i[c_i] = (b_idx_1 + d) * SV_tmp_tmp;
            c_A_I_i[c_i] = (b_idx_1 + d) * b_SV_tmp_tmp;
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          SV_tmp_tmp = SV->ww[n_tmp];
          b_SV_tmp_tmp = SV->ww[i3];
          b[0] = b_SV_tmp_tmp * c_A_I_i[2] - c_A_I_i[1] * SV_tmp_tmp;
          b_tmp = SV->ww[3 * b_i];
          b[1] = c_A_I_i[0] * SV_tmp_tmp - b_tmp * c_A_I_i[2];
          b[2] = b_tmp * c_A_I_i[1] - c_A_I_i[0] * b_SV_tmp_tmp;
          b_idx_1 = LP_cc[66 * b_i];
          d = LP_cc[66 * b_i + 1];
          d1 = LP_cc[66 * b_i + 2];
          for (i2 = 0; i2 < 3; i2++) {
            real_T y_tmp;
            y_tmp =
                (A_I_i[i2] * b_idx_1 + A_I_i[i2 + 3] * d) + A_I_i[i2 + 6] * d1;
            y[i2] = y_tmp;
            c_A_I_i[i2] = y_tmp;
          }
          b_idx_1 = LP_BB[b_i];
          if (b_idx_1 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &w_emlrtDCI, (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          n[0] = SV->wd[A_I_BB_tmp + 1] * b_SV[2] -
                 b_SV[1] * SV->wd[A_I_BB_tmp + 2];
          n[1] =
              b_SV[0] * SV->wd[A_I_BB_tmp + 2] - SV->wd[A_I_BB_tmp] * b_SV[2];
          n[2] =
              SV->wd[A_I_BB_tmp] * b_SV[1] - b_SV[0] * SV->wd[A_I_BB_tmp + 1];
          i2 = (int32_T)b_idx_1;
          if (i2 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &ab_emlrtDCI, (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n_tmp = SV->ww[A_I_BB_tmp + 2];
          c_n_tmp = SV->ww[A_I_BB_tmp + 1];
          b_n[0] = c_n_tmp * b_SV[2] - b_SV[1] * b_n_tmp;
          d_n_tmp = SV->ww[A_I_BB_tmp];
          b_n[1] = b_SV[0] * b_n_tmp - d_n_tmp * b_SV[2];
          b_n[2] = d_n_tmp * b_SV[1] - b_SV[0] * c_n_tmp;
          if (i2 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &y_emlrtDCI, (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          c_n[0] = c_n_tmp * b_n[2] - b_n[1] * b_n_tmp;
          c_n[1] = b_n[0] * b_n_tmp - d_n_tmp * b_n[2];
          c_n[2] = d_n_tmp * b_n[1] - b_n[0] * c_n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_n_tmp = SV->wd[n_tmp];
          c_n_tmp = SV->wd[i3];
          b_n[0] = c_n_tmp * b_A_I_i[2] - b_A_I_i[1] * b_n_tmp;
          d_n_tmp = SV->wd[3 * b_i];
          b_n[1] = b_A_I_i[0] * b_n_tmp - d_n_tmp * b_A_I_i[2];
          b_n[2] = d_n_tmp * b_A_I_i[1] - b_A_I_i[0] * c_n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d_n[0] = b_SV_tmp_tmp * d_A_I_i[2] - d_A_I_i[1] * SV_tmp_tmp;
          d_n[1] = d_A_I_i[0] * SV_tmp_tmp - b_tmp * d_A_I_i[2];
          d_n[2] = b_tmp * d_A_I_i[1] - d_A_I_i[0] * b_SV_tmp_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_A_I_i[0] = b_SV_tmp_tmp * d_n[2] - d_n[1] * SV_tmp_tmp;
          b_A_I_i[1] = d_n[0] * SV_tmp_tmp - b_tmp * d_n[2];
          b_A_I_i[2] = b_tmp * d_n[1] - d_n[0] * b_SV_tmp_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d_n[0] = c_n_tmp * c_A_I_i[2] - c_A_I_i[1] * b_n_tmp;
          d_n[1] = c_A_I_i[0] * b_n_tmp - d_n_tmp * c_A_I_i[2];
          d_n[2] = d_n_tmp * c_A_I_i[1] - c_A_I_i[0] * c_n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_SV[0] = b_SV_tmp_tmp * y[2] - y[1] * SV_tmp_tmp;
          b_SV[1] = y[0] * SV_tmp_tmp - b_tmp * y[2];
          b_SV[2] = b_tmp * y[1] - y[0] * b_SV_tmp_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d_A_I_i[0] = b_SV_tmp_tmp * b_SV[2] - b_SV[1] * SV_tmp_tmp;
          d_A_I_i[1] = b_SV[0] * SV_tmp_tmp - b_tmp * b_SV[2];
          d_A_I_i[2] = b_tmp * b_SV[1] - b_SV[0] * b_SV_tmp_tmp;
          if (i2 != i1) {
            emlrtIntegerCheckR2012b(b_idx_1, &v_emlrtDCI, (emlrtConstCTX)sp);
          }
          c_SV = SV->qdd[b_i];
          for (i1 = 0; i1 < 3; i1++) {
            n[i1] =
                (((((((SV->vd[i1 + A_I_BB_tmp] + n[i1]) + c_n[i1]) + b_n[i1]) +
                    b_A_I_i[i1]) +
                   2.0 * b[i1]) +
                  ((A_I_i[i1] * 0.0 + A_I_i[i1 + 3] * 0.0) + A_I_i[i1 + 6]) *
                      c_SV) -
                 d_n[i1]) -
                d_A_I_i[i1];
          }
          SV->vd[3 * b_i] = n[0];
          SV->vd[i3] = n[1];
          SV->vd[n_tmp] = n[2];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
  }
  /* %%EOF */
}

/* End of code generation (calc_acc.c) */
