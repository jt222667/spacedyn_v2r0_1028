/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_pos.c
 *
 * Code generation for function 'calc_pos'
 *
 */

/* Include files */
#include "calc_pos.h"
#include "calc_pos_data.h"
#include "calc_pos_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = {
    28,         /* lineNo */
    9,          /* colNo */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    48,         /* lineNo */
    26,         /* colNo */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    52,         /* lineNo */
    34,         /* colNo */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    1                                 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    52,         /* lineNo */
    61,         /* colNo */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    1                                 /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    52,         /* lineNo */
    61,         /* colNo */
    "LP.cc",    /* aName */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    0                                 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    56,         /* lineNo */
    34,         /* colNo */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    1                                 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    56,         /* lineNo */
    61,         /* colNo */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    1                                 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    56,         /* lineNo */
    61,         /* colNo */
    "LP.cc",    /* aName */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    1,          /* iFirst */
    21,         /* iLast */
    33,         /* lineNo */
    14,         /* colNo */
    "LP.BB",    /* aName */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,          /* iFirst */
    63,         /* iLast */
    48,         /* lineNo */
    26,         /* colNo */
    "SV.AA",    /* aName */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    0                                 /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    48,         /* lineNo */
    26,         /* colNo */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    1                                 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    1,          /* iFirst */
    63,         /* iLast */
    30,         /* lineNo */
    21,         /* colNo */
    "SV.AA",    /* aName */
    "calc_pos", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_pos.m", /* pName */
    0                                 /* checkKind */
};

/* Function Definitions */
void calc_pos(const emlrtStack *sp, const struct0_T *LP, struct1_T *SV)
{
  static const int8_T b_a[3] = {0, 0, 1};
  int32_T A_I_i_tmp;
  int32_T b_i;
  int32_T i;
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
  /*  CALC_POS	Calculate the position vectors of each link */
  /*  */
  /* 		CALC_POS returns the position vectors RR in the Inertia frame.
   */
  /*  */
  /*  CALC_POS    计算每个连杆的位置向量 */
  /*  */
  /*         CALC_POS 返回惯性坐标系中的位置向量 RR。 */
  /* global BB J_type */
  /* global c0 cc */
  /* global num_q Ez */
  /*  初始化 Ez */
  /*  If a Multi body system, */
  /*  Calculation of position vectors */
  i = (int32_T)LP->num_q;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                (int32_T)LP->num_q, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    real_T A_I_i[9];
    real_T c_i;
    c_i = ((real_T)b_i + 1.0) * 3.0;
    for (i1 = 0; i1 < 3; i1++) {
      i2 = (int32_T)(c_i + ((real_T)i1 - 2.0));
      if ((i2 < 1) || (i2 > 63)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 63, &e_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      A_I_i_tmp = 3 * (i2 - 1);
      A_I_i[3 * i1] = SV->AA[A_I_i_tmp];
      A_I_i[3 * i1 + 1] = SV->AA[A_I_i_tmp + 1];
      A_I_i[3 * i1 + 2] = SV->AA[A_I_i_tmp + 2];
    }
    /*  Current (i-th) link connects to the 0-th link */
    if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
        ((int32_T)((uint32_T)b_i + 1U) > 21)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                    &c_emlrtBCI, (emlrtConstCTX)sp);
    }
    c_i = LP->BB[b_i];
    if (c_i == 0.0) {
      /*  Rotational joint */
      if (LP->J_type[b_i] == 'R') {
        i1 = 66 * b_i;
        for (i2 = 0; i2 < 3; i2++) {
          SV->RR[i2 + 3 * b_i] =
              (SV->R0[i2] + ((SV->A0[i2] * LP->c0[3 * b_i] +
                              SV->A0[i2 + 3] * LP->c0[3 * b_i + 1]) +
                             SV->A0[i2 + 6] * LP->c0[3 * b_i + 2])) -
              ((A_I_i[i2] * LP->cc[66 * b_i] + A_I_i[i2 + 3] * LP->cc[i1 + 1]) +
               A_I_i[i2 + 6] * LP->cc[i1 + 2]);
        }
        /*  Prismatic joint */
      } else {
        real_T a[3];
        real_T b_SV[3];
        real_T d;
        real_T d1;
        c_i = SV->q[b_i];
        for (i1 = 0; i1 < 3; i1++) {
          a[i1] = (real_T)b_a[i1] * c_i - LP->cc[(i1 + 3 * b_i) + 63 * b_i];
          b_SV[i1] = SV->R0[i1] + ((SV->A0[i1] * LP->c0[3 * b_i] +
                                    SV->A0[i1 + 3] * LP->c0[3 * b_i + 1]) +
                                   SV->A0[i1 + 6] * LP->c0[3 * b_i + 2]);
        }
        c_i = a[0];
        d = a[1];
        d1 = a[2];
        for (i1 = 0; i1 < 3; i1++) {
          SV->RR[i1 + 3 * b_i] =
              b_SV[i1] +
              ((A_I_i[i1] * c_i + A_I_i[i1 + 3] * d) + A_I_i[i1 + 6] * d1);
        }
      }
      /*  Current (i-th) link doesn't connect to the 0-th link */
    } else {
      real_T A_I_BB[9];
      real_T d;
      real_T d1;
      d = c_i * 3.0;
      if (!(d == c_i * 3.0)) {
        emlrtErrorWithMessageIdR2018a(
            sp, &b_emlrtRTEI,
            "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
            "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing", 0);
      }
      for (i1 = 0; i1 < 3; i1++) {
        c_i = d + ((real_T)i1 - 2.0);
        d1 = (int32_T)muDoubleScalarFloor(c_i);
        if (c_i != d1) {
          emlrtIntegerCheckR2012b(c_i, &e_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)c_i < 1) || ((int32_T)c_i > 63)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, 63, &d_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        A_I_i_tmp = 3 * ((int32_T)c_i - 1);
        A_I_BB[3 * i1] = SV->AA[A_I_i_tmp];
        if (c_i != d1) {
          emlrtIntegerCheckR2012b(c_i, &e_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)c_i < 1) || ((int32_T)c_i > 63)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, 63, &d_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        A_I_BB[3 * i1 + 1] = SV->AA[A_I_i_tmp + 1];
        if (c_i != d1) {
          emlrtIntegerCheckR2012b(c_i, &e_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)c_i < 1) || ((int32_T)c_i > 63)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, 63, &d_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        A_I_BB[3 * i1 + 2] = SV->AA[A_I_i_tmp + 2];
      }
      /*  Rotational joint */
      if (LP->J_type[b_i] == 'R') {
        real_T a[3];
        real_T b_SV[3];
        c_i = LP->BB[b_i];
        i1 = (int32_T)muDoubleScalarFloor(c_i);
        if (c_i != i1) {
          emlrtIntegerCheckR2012b(c_i, &b_emlrtDCI, (emlrtConstCTX)sp);
        }
        i2 = (int32_T)c_i;
        if ((i2 < 1) || (i2 > 21)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, 21, &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i2 != i1) {
          emlrtIntegerCheckR2012b(c_i, &emlrtDCI, (emlrtConstCTX)sp);
        }
        i1 = 3 * (i2 - 1);
        A_I_i_tmp = 3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i;
        for (i2 = 0; i2 < 3; i2++) {
          a[i2] = (A_I_i[i2] * LP->cc[66 * b_i] +
                   A_I_i[i2 + 3] * LP->cc[66 * b_i + 1]) +
                  A_I_i[i2 + 6] * LP->cc[66 * b_i + 2];
          b_SV[i2] =
              SV->RR[i2 + i1] + ((A_I_BB[i2] * LP->cc[i1 + 63 * b_i] +
                                  A_I_BB[i2 + 3] * LP->cc[A_I_i_tmp + 1]) +
                                 A_I_BB[i2 + 6] * LP->cc[A_I_i_tmp + 2]);
        }
        SV->RR[3 * b_i] = b_SV[0] - a[0];
        SV->RR[3 * b_i + 1] = b_SV[1] - a[1];
        SV->RR[3 * b_i + 2] = b_SV[2] - a[2];
        /*  Prismatic joint */
      } else {
        real_T a[3];
        real_T b_SV[3];
        c_i = LP->BB[b_i];
        i1 = (int32_T)muDoubleScalarFloor(c_i);
        if (c_i != i1) {
          emlrtIntegerCheckR2012b(c_i, &d_emlrtDCI, (emlrtConstCTX)sp);
        }
        i2 = (int32_T)c_i;
        if ((i2 < 1) || (i2 > 21)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, 21, &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (i2 != i1) {
          emlrtIntegerCheckR2012b(c_i, &c_emlrtDCI, (emlrtConstCTX)sp);
        }
        c_i = SV->q[b_i];
        i1 = 3 * ((int32_T)LP->BB[b_i] - 1);
        i2 = i1 + 63 * b_i;
        for (A_I_i_tmp = 0; A_I_i_tmp < 3; A_I_i_tmp++) {
          a[A_I_i_tmp] = (real_T)b_a[A_I_i_tmp] * c_i -
                         LP->cc[(A_I_i_tmp + 3 * b_i) + 63 * b_i];
          b_SV[A_I_i_tmp] = SV->RR[A_I_i_tmp + i1] +
                            ((A_I_BB[A_I_i_tmp] * LP->cc[i2] +
                              A_I_BB[A_I_i_tmp + 3] * LP->cc[i2 + 1]) +
                             A_I_BB[A_I_i_tmp + 6] * LP->cc[i2 + 2]);
        }
        c_i = a[0];
        d = a[1];
        d1 = a[2];
        for (i1 = 0; i1 < 3; i1++) {
          SV->RR[i1 + 3 * b_i] =
              b_SV[i1] +
              ((A_I_i[i1] * c_i + A_I_i[i1 + 3] * d) + A_I_i[i1 + 6] * d1);
        }
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* %%EOF */
}

/* End of code generation (calc_pos.c) */
