/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_vel.c
 *
 * Code generation for function 'calc_vel'
 *
 */

/* Include files */
#include "calc_vel.h"
#include "calc_vel_data.h"
#include "calc_vel_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = {
    36,         /* lineNo */
    12,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    65,         /* lineNo */
    27,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    70,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    70,         /* lineNo */
    34,         /* colNo */
    "SV.ww",    /* aName */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    71,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    72,         /* lineNo */
    33,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    72,         /* lineNo */
    59,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    77,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    77,         /* lineNo */
    34,         /* colNo */
    "SV.ww",    /* aName */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    78,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    79,         /* lineNo */
    33,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    79,         /* lineNo */
    59,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    39,         /* lineNo */
    16,         /* colNo */
    "LP.BB",    /* aName */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,          /* iFirst */
    63,         /* iLast */
    65,         /* lineNo */
    27,         /* colNo */
    "SV.AA",    /* aName */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    0                             /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    65,         /* lineNo */
    27,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

/* Function Definitions */
void calc_vel(const emlrtStack *sp, const struct0_T *LP, struct1_T *SV)
{
  real_T n[3];
  int32_T A_I_BB_tmp;
  int32_T b_i;
  int32_T c_i;
  int32_T i1;
  int32_T i2;
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
  if (LP->num_q == 0.0) {
    memset(&SV->vv[0], 0, 63U * sizeof(real_T));
    memset(&SV->ww[0], 0, 63U * sizeof(real_T));
    /*  If a Multi body system, */
  } else {
    int32_T i;
    /*  Calculation of velocity vectors vv,ww */
    i = (int32_T)LP->num_q;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                  (int32_T)LP->num_q, &emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (b_i = 0; b_i < i; b_i++) {
      real_T d;
      /*  Check the link connection: Is the lower one of this link, 0 ? */
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > 21)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                      &c_emlrtBCI, (emlrtConstCTX)sp);
      }
      d = LP->BB[b_i];
      if (d == 0.0) {
        real_T A_I_i[9];
        /*  Current (i-th) link connects to the 0-th link */
        c_i = (b_i + 1) * 3 - 3;
        for (i1 = 0; i1 < 3; i1++) {
          A_I_BB_tmp = 3 * (i1 + c_i);
          A_I_i[3 * i1] = SV->AA[A_I_BB_tmp];
          A_I_i[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
          A_I_i[3 * i1 + 2] = SV->AA[A_I_BB_tmp + 2];
        }
        /*  Rotational joint */
        if (LP->J_type[b_i] == 'R') {
          real_T b_SV[3];
          real_T y[3];
          real_T b_SV_tmp_tmp;
          real_T d1;
          b_SV_tmp_tmp = SV->qd[b_i];
          i1 = 66 * b_i;
          for (i2 = 0; i2 < 3; i2++) {
            real_T SV_tmp_tmp;
            d = A_I_i[i2];
            d1 = A_I_i[i2 + 3];
            SV_tmp_tmp = A_I_i[i2 + 6];
            SV->ww[i2 + 3 * b_i] =
                SV->w0[i2] + ((d * 0.0 + d1 * 0.0) + SV_tmp_tmp) * b_SV_tmp_tmp;
            b_SV[i2] = (d * LP->cc[66 * b_i] + d1 * LP->cc[i1 + 1]) +
                       SV_tmp_tmp * LP->cc[i1 + 2];
            y[i2] = (SV->A0[i2] * LP->c0[3 * b_i] +
                     SV->A0[i2 + 3] * LP->c0[3 * b_i + 1]) +
                    SV->A0[i2 + 6] * LP->c0[3 * b_i + 2];
          }
          real_T b_n_tmp;
          real_T c_n_tmp;
          real_T n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          d = y[0] * SV->w0[2] - SV->w0[0] * y[2];
          d1 = SV->w0[0] * y[1] - y[0] * SV->w0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          A_I_BB_tmp = 3 * b_i + 2;
          n_tmp = SV->ww[A_I_BB_tmp];
          c_i = 3 * b_i + 1;
          b_n_tmp = SV->ww[c_i];
          c_n_tmp = SV->ww[3 * b_i];
          SV->vv[3 * b_i] =
              (SV->v0[0] + (SV->w0[1] * y[2] - y[1] * SV->w0[2])) -
              (b_n_tmp * b_SV[2] - b_SV[1] * n_tmp);
          SV->vv[c_i] = (SV->v0[1] + d) - (b_SV[0] * n_tmp - c_n_tmp * b_SV[2]);
          SV->vv[A_I_BB_tmp] =
              (SV->v0[2] + d1) - (c_n_tmp * b_SV[1] - b_SV[0] * b_n_tmp);
          /*  Prismatic joint */
        } else {
          real_T b_A_I_i[3];
          real_T b_SV[3];
          real_T y[3];
          real_T SV_tmp_tmp;
          real_T d1;
          for (c_i = 0; c_i < 3; c_i++) {
            SV->ww[c_i + 3 * b_i] = SV->w0[c_i];
            d = A_I_i[c_i];
            d1 = d * 0.0;
            SV_tmp_tmp = d * LP->cc[66 * b_i];
            d = A_I_i[c_i + 3];
            d1 += d * 0.0;
            SV_tmp_tmp += d * LP->cc[66 * b_i + 1];
            d = A_I_i[c_i + 6];
            d1 += d;
            SV_tmp_tmp += d * LP->cc[66 * b_i + 2];
            b_SV[c_i] = SV_tmp_tmp;
            y[c_i] = (SV->A0[c_i] * LP->c0[3 * b_i] +
                      SV->A0[c_i + 3] * LP->c0[3 * b_i + 1]) +
                     SV->A0[c_i + 6] * LP->c0[3 * b_i + 2];
            n[c_i] = d1;
            b_A_I_i[c_i] = d1 * SV->q[b_i];
          }
          real_T b_SV_tmp_tmp;
          real_T b_n_tmp;
          real_T c_n_tmp;
          real_T n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          SV_tmp_tmp = SV->w0[1] * y[2] - y[1] * SV->w0[2];
          d = y[0] * SV->w0[2] - SV->w0[0] * y[2];
          d1 = SV->w0[0] * y[1] - y[0] * SV->w0[1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          A_I_BB_tmp = 3 * b_i + 2;
          n_tmp = SV->ww[A_I_BB_tmp];
          c_i = 3 * b_i + 1;
          b_n_tmp = SV->ww[c_i];
          c_n_tmp = SV->ww[3 * b_i];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_SV_tmp_tmp = SV->qd[b_i];
          SV->vv[3 * b_i] = (((SV->v0[0] + SV_tmp_tmp) -
                              (b_n_tmp * b_SV[2] - b_SV[1] * n_tmp)) +
                             (b_n_tmp * b_A_I_i[2] - b_A_I_i[1] * n_tmp)) +
                            n[0] * b_SV_tmp_tmp;
          SV->vv[c_i] =
              (((SV->v0[1] + d) - (b_SV[0] * n_tmp - c_n_tmp * b_SV[2])) +
               (b_A_I_i[0] * n_tmp - c_n_tmp * b_A_I_i[2])) +
              n[1] * b_SV_tmp_tmp;
          SV->vv[A_I_BB_tmp] =
              (((SV->v0[2] + d1) - (c_n_tmp * b_SV[1] - b_SV[0] * b_n_tmp)) +
               (c_n_tmp * b_A_I_i[1] - b_A_I_i[0] * b_n_tmp)) +
              n[2] * b_SV_tmp_tmp;
        }
        /*  Current (i-th) link doesn't connect to the 0-th link */
      } else {
        real_T A_I_BB[9];
        real_T A_I_i[9];
        real_T SV_tmp_tmp;
        real_T d1;
        d1 = d * 3.0;
        if (!(d1 == d * 3.0)) {
          emlrtErrorWithMessageIdR2018a(
              sp, &b_emlrtRTEI,
              "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
              "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
              0);
        }
        for (i1 = 0; i1 < 3; i1++) {
          d = d1 + ((real_T)i1 - 2.0);
          SV_tmp_tmp = (int32_T)muDoubleScalarFloor(d);
          if (d != SV_tmp_tmp) {
            emlrtIntegerCheckR2012b(d, &i_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d < 1) || ((int32_T)d > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 63, &d_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          A_I_BB_tmp = 3 * ((int32_T)d - 1);
          A_I_BB[3 * i1] = SV->AA[A_I_BB_tmp];
          if (d != SV_tmp_tmp) {
            emlrtIntegerCheckR2012b(d, &i_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d < 1) || ((int32_T)d > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 63, &d_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          A_I_BB[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
          if (d != SV_tmp_tmp) {
            emlrtIntegerCheckR2012b(d, &i_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d < 1) || ((int32_T)d > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 63, &d_emlrtBCI,
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
        if (LP->J_type[b_i] == 'R') {
          real_T b_SV[3];
          real_T y[3];
          real_T b_SV_tmp_tmp;
          real_T b_n_tmp;
          real_T c_n_tmp;
          real_T d_n_tmp;
          real_T n_tmp;
          int32_T i3;
          d = LP->BB[b_i];
          i1 = (int32_T)muDoubleScalarFloor(d);
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)d;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 21, &emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          b_SV_tmp_tmp = SV->qd[b_i];
          for (i2 = 0; i2 < 3; i2++) {
            b_SV[i2] =
                SV->ww[i2 + 3 * ((int32_T)LP->BB[b_i] - 1)] +
                ((A_I_i[i2] * 0.0 + A_I_i[i2 + 3] * 0.0) + A_I_i[i2 + 6]) *
                    b_SV_tmp_tmp;
          }
          SV->ww[3 * b_i] = b_SV[0];
          i2 = 3 * b_i + 1;
          SV->ww[i2] = b_SV[1];
          i3 = 3 * b_i + 2;
          SV->ww[i3] = b_SV[2];
          d = LP->BB[b_i];
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &d_emlrtDCI, (emlrtConstCTX)sp);
          }
          c_i = 3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i;
          for (A_I_BB_tmp = 0; A_I_BB_tmp < 3; A_I_BB_tmp++) {
            b_SV[A_I_BB_tmp] = (A_I_i[A_I_BB_tmp] * LP->cc[66 * b_i] +
                                A_I_i[A_I_BB_tmp + 3] * LP->cc[66 * b_i + 1]) +
                               A_I_i[A_I_BB_tmp + 6] * LP->cc[66 * b_i + 2];
            y[A_I_BB_tmp] = (A_I_BB[A_I_BB_tmp] * LP->cc[c_i] +
                             A_I_BB[A_I_BB_tmp + 3] * LP->cc[c_i + 1]) +
                            A_I_BB[A_I_BB_tmp + 6] * LP->cc[c_i + 2];
          }
          d = LP->BB[b_i];
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          A_I_BB_tmp = (int32_T)d;
          c_i = 3 * (A_I_BB_tmp - 1);
          n_tmp = SV->ww[c_i + 2];
          b_n_tmp = SV->ww[c_i + 1];
          c_n_tmp = SV->ww[c_i];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_SV_tmp_tmp = SV->ww[i3];
          d_n_tmp = SV->ww[i2];
          SV_tmp_tmp = SV->ww[3 * b_i];
          if (A_I_BB_tmp != i1) {
            emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
          }
          d = (SV->vv[c_i + 1] + (y[0] * n_tmp - c_n_tmp * y[2])) -
              (b_SV[0] * b_SV_tmp_tmp - SV_tmp_tmp * b_SV[2]);
          d1 = (SV->vv[c_i + 2] + (c_n_tmp * y[1] - y[0] * b_n_tmp)) -
               (SV_tmp_tmp * b_SV[1] - b_SV[0] * d_n_tmp);
          SV->vv[3 * b_i] = (SV->vv[c_i] + (b_n_tmp * y[2] - y[1] * n_tmp)) -
                            (d_n_tmp * b_SV[2] - b_SV[1] * b_SV_tmp_tmp);
          SV->vv[i2] = d;
          SV->vv[i3] = d1;
          /*  Prismatic joint */
        } else {
          real_T b_A_I_i[3];
          real_T b_SV[3];
          real_T b_n[3];
          real_T y[3];
          real_T b_SV_tmp_tmp;
          real_T b_n_tmp;
          real_T c_n_tmp;
          real_T n_tmp;
          int32_T i3;
          d = LP->BB[b_i];
          i1 = (int32_T)muDoubleScalarFloor(d);
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &e_emlrtDCI, (emlrtConstCTX)sp);
          }
          i2 = (int32_T)d;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 21, &b_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          A_I_BB_tmp = 3 * (i2 - 1);
          SV_tmp_tmp = SV->ww[A_I_BB_tmp + 1];
          b_SV_tmp_tmp = SV->ww[A_I_BB_tmp + 2];
          SV->ww[3 * b_i] = SV->ww[A_I_BB_tmp];
          i3 = 3 * b_i + 1;
          SV->ww[i3] = SV_tmp_tmp;
          c_i = 3 * b_i + 2;
          SV->ww[c_i] = b_SV_tmp_tmp;
          if (i2 != i1) {
            emlrtIntegerCheckR2012b(d, &h_emlrtDCI, (emlrtConstCTX)sp);
          }
          b_SV_tmp_tmp = SV->q[b_i];
          for (i2 = 0; i2 < 3; i2++) {
            d = A_I_i[i2];
            d1 = d * LP->cc[66 * b_i];
            SV_tmp_tmp = d * 0.0;
            d = A_I_i[i2 + 3];
            d1 += d * LP->cc[66 * b_i + 1];
            SV_tmp_tmp += d * 0.0;
            d = A_I_i[i2 + 6];
            d1 += d * LP->cc[66 * b_i + 2];
            SV_tmp_tmp += d;
            b_SV[i2] = d1;
            y[i2] =
                (A_I_BB[i2] *
                     LP->cc[3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i] +
                 A_I_BB[i2 + 3] *
                     LP->cc[(3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i) + 1]) +
                A_I_BB[i2 + 6] *
                    LP->cc[(3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i) + 2];
            b_A_I_i[i2] = SV_tmp_tmp * b_SV_tmp_tmp;
          }
          d = LP->BB[b_i];
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtConstCTX)sp);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          n[0] = SV->ww[A_I_BB_tmp + 1] * y[2] - y[1] * SV->ww[A_I_BB_tmp + 2];
          n[1] = y[0] * SV->ww[A_I_BB_tmp + 2] - SV->ww[A_I_BB_tmp] * y[2];
          n[2] = SV->ww[A_I_BB_tmp] * y[1] - y[0] * SV->ww[A_I_BB_tmp + 1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          n_tmp = SV->ww[c_i];
          b_n_tmp = SV->ww[i3];
          b_n[0] = b_n_tmp * b_SV[2] - b_SV[1] * n_tmp;
          c_n_tmp = SV->ww[3 * b_i];
          b_n[1] = b_SV[0] * n_tmp - c_n_tmp * b_SV[2];
          b_n[2] = c_n_tmp * b_SV[1] - b_SV[0] * b_n_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          y[0] = b_n_tmp * b_A_I_i[2] - b_A_I_i[1] * n_tmp;
          y[1] = b_A_I_i[0] * n_tmp - c_n_tmp * b_A_I_i[2];
          y[2] = c_n_tmp * b_A_I_i[1] - b_A_I_i[0] * b_n_tmp;
          if ((int32_T)d != i1) {
            emlrtIntegerCheckR2012b(d, &f_emlrtDCI, (emlrtConstCTX)sp);
          }
          b_SV_tmp_tmp = SV->qd[b_i];
          for (i1 = 0; i1 < 3; i1++) {
            n[i1] = (((SV->vv[i1 + A_I_BB_tmp] + n[i1]) - b_n[i1]) + y[i1]) +
                    ((A_I_i[i1] * 0.0 + A_I_i[i1 + 3] * 0.0) + A_I_i[i1 + 6]) *
                        b_SV_tmp_tmp;
          }
          SV->vv[3 * b_i] = n[0];
          SV->vv[i3] = n[1];
          SV->vv[c_i] = n[2];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
  }
  /* %%EOF */
}

/* End of code generation (calc_vel.c) */
