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
#include "calc_acc.h"
#include "r_ne_data.h"
#include "r_ne_emxutil.h"
#include "r_ne_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    34,     /* lineNo */
    "r_ne", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    39,     /* lineNo */
    "r_ne", /* fcnName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    56,     /* lineNo */
    14,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    4                         /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    56,     /* lineNo */
    14,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    1                         /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    57,     /* lineNo */
    14,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    1                         /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    59,     /* lineNo */
    9,      /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,      /* iFirst */
    21,     /* iLast */
    62,     /* lineNo */
    20,     /* colNo */
    "LP.m", /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    71,     /* lineNo */
    14,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    1                         /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    72,     /* lineNo */
    14,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    1                         /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    79,     /* lineNo */
    13,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    84,     /* lineNo */
    15,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    86,      /* lineNo */
    28,      /* colNo */
    "LP.SS", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    86,     /* lineNo */
    30,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    1                         /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    86,      /* lineNo */
    30,      /* colNo */
    "LP.SS", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    86,     /* lineNo */
    38,     /* colNo */
    "Fj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    90,     /* lineNo */
    24,     /* colNo */
    "FF",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    90,      /* lineNo */
    39,      /* colNo */
    "LP.SE", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    90,     /* lineNo */
    14,     /* colNo */
    "Fj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    92,     /* lineNo */
    15,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtBCInfo h_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    96,      /* lineNo */
    27,      /* colNo */
    "LP.SS", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    96,     /* lineNo */
    108,    /* colNo */
    "Fj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    96,     /* lineNo */
    120,    /* colNo */
    "Tj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    63,     /* lineNo */
    10,     /* colNo */
    "TT",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    103,    /* lineNo */
    24,     /* colNo */
    "TT",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    104,    /* lineNo */
    46,     /* colNo */
    "FF",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    103,    /* lineNo */
    14,     /* colNo */
    "Tj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    106,    /* lineNo */
    24,     /* colNo */
    "Tj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    117,    /* lineNo */
    11,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    120,    /* lineNo */
    36,     /* colNo */
    "Fj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = {
    128,    /* lineNo */
    11,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    131,    /* lineNo */
    65,     /* colNo */
    "Fj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    131,    /* lineNo */
    77,     /* colNo */
    "Tj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = {
    152,    /* lineNo */
    13,     /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    158,    /* lineNo */
    32,     /* colNo */
    "Tj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    162,    /* lineNo */
    32,     /* colNo */
    "Fj",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    62,     /* lineNo */
    10,     /* colNo */
    "FF",   /* aName */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    36,         /* lineNo */
    12,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    65,         /* lineNo */
    27,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m" /* pName */
};

static emlrtDCInfo g_emlrtDCI = {
    70,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
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

static emlrtDCInfo h_emlrtDCI = {
    71,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    72,         /* lineNo */
    33,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    72,         /* lineNo */
    59,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    77,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
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

static emlrtDCInfo l_emlrtDCI = {
    78,         /* lineNo */
    34,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    79,         /* lineNo */
    33,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    79,         /* lineNo */
    59,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
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

static emlrtBCInfo y_emlrtBCI = {
    1,           /* iFirst */
    21,          /* iLast */
    156,         /* lineNo */
    22,          /* colNo */
    "LP.J_type", /* aName */
    "r_ne",      /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    119,     /* lineNo */
    19,      /* colNo */
    "LP.S0", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    1,       /* iFirst */
    21,      /* iLast */
    130,     /* lineNo */
    19,      /* colNo */
    "LP.S0", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    1,       /* iFirst */
    63,      /* iLast */
    154,     /* lineNo */
    25,      /* colNo */
    "SV.AA", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    1,            /* iFirst */
    63,           /* iLast */
    61,           /* lineNo */
    25,           /* colNo */
    "LP.inertia", /* aName */
    "r_ne",       /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    1,       /* iFirst */
    63,      /* iLast */
    60,      /* lineNo */
    22,      /* colNo */
    "SV.AA", /* aName */
    "r_ne",  /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m", /* pName */
    0                         /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
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

static emlrtDCInfo o_emlrtDCI = {
    65,         /* lineNo */
    27,         /* colNo */
    "calc_vel", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\calc_vel.m", /* pName */
    1                             /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = {
    56,     /* lineNo */
    1,      /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    57,     /* lineNo */
    1,      /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    71,     /* lineNo */
    1,      /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    72,     /* lineNo */
    1,      /* colNo */
    "r_ne", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1027\\spacedyn\\r_ne.m" /* pName */
};

/* Function Definitions */
void r_ne(const emlrtStack *sp, const struct0_T *LP, struct1_T *SV,
          real_T Force_data[], int32_T Force_size[1])
{
  static const int8_T b[3] = {0, 0, 1};
  emlrtStack st;
  emxArray_real_T *FF;
  emxArray_real_T *Fj;
  emxArray_real_T *TT;
  emxArray_real_T *Tj;
  real_T A_I_0[9];
  real_T A_I_BB[9];
  real_T A_I_i[9];
  real_T b_A_I_0[9];
  real_T F[3];
  real_T FF0[3];
  real_T T[3];
  real_T TT0[3];
  real_T b_SV[3];
  real_T FF0_tmp;
  real_T SV_tmp_tmp;
  real_T b_SV_tmp_tmp;
  real_T b_n_tmp;
  real_T c_n_tmp;
  real_T d;
  real_T n_tmp;
  real_T *FF_data;
  real_T *Fj_data;
  real_T *TT_data;
  real_T *Tj_data;
  int32_T A_I_BB_tmp;
  int32_T SV_tmp;
  int32_T b_i;
  int32_T c_i;
  int32_T d_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
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
  /*  初始化 Ez */
  /*  初始化 Gravity */
  /*  Calculation of coordinate transfromation matrices */
  memcpy(&A_I_0[0], &SV->A0[0], 9U * sizeof(real_T));
  /*  Calculation of velocity vectors vv,ww */
  /*  NOTE:	vv,ww are in the Inertial frame */
  st.site = &emlrtRSI;
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
    /*  Calculation of velocity vectors vv,ww */
    i = (int32_T)LP->num_q;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                  (int32_T)LP->num_q, &h_emlrtRTEI, &st);
    for (b_i = 0; b_i < i; b_i++) {
      /*  Check the link connection: Is the lower one of this link, 0 ? */
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > 21)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                      &x_emlrtBCI, &st);
      }
      d = LP->BB[b_i];
      if (d == 0.0) {
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
          i1 = 66 * b_i;
          for (i2 = 0; i2 < 3; i2++) {
            d = A_I_i[i2];
            n_tmp = d * 0.0;
            FF0_tmp = d * LP->cc[66 * b_i];
            d = A_I_i[i2 + 3];
            n_tmp += d * 0.0;
            FF0_tmp += d * LP->cc[i1 + 1];
            d = A_I_i[i2 + 6];
            n_tmp += d;
            FF0_tmp += d * LP->cc[i1 + 2];
            F[i2] = FF0_tmp;
            b_SV[i2] = (SV->A0[i2] * LP->c0[3 * b_i] +
                        SV->A0[i2 + 3] * LP->c0[3 * b_i + 1]) +
                       SV->A0[i2 + 6] * LP->c0[3 * b_i + 2];
            SV->ww[i2 + 3 * b_i] = SV->w0[i2] + n_tmp * SV->qd[b_i];
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
          A_I_BB_tmp = 3 * b_i + 2;
          b_SV_tmp_tmp = SV->ww[A_I_BB_tmp];
          SV_tmp = 3 * b_i + 1;
          FF0_tmp = SV->ww[SV_tmp];
          SV_tmp_tmp = SV->ww[3 * b_i];
          SV->vv[3 * b_i] =
              (SV->v0[0] + (SV->w0[1] * b_SV[2] - b_SV[1] * SV->w0[2])) -
              (FF0_tmp * F[2] - F[1] * b_SV_tmp_tmp);
          SV->vv[SV_tmp] =
              (SV->v0[1] + (b_SV[0] * SV->w0[2] - SV->w0[0] * b_SV[2])) -
              (F[0] * b_SV_tmp_tmp - SV_tmp_tmp * F[2]);
          SV->vv[A_I_BB_tmp] =
              (SV->v0[2] + (SV->w0[0] * b_SV[1] - b_SV[0] * SV->w0[1])) -
              (SV_tmp_tmp * F[1] - F[0] * FF0_tmp);
          /*  Prismatic joint */
        } else {
          for (c_i = 0; c_i < 3; c_i++) {
            SV->ww[c_i + 3 * b_i] = SV->w0[c_i];
            d = A_I_i[c_i];
            n_tmp = d * 0.0;
            FF0_tmp = d * LP->cc[66 * b_i];
            d = A_I_i[c_i + 3];
            n_tmp += d * 0.0;
            FF0_tmp += d * LP->cc[66 * b_i + 1];
            d = A_I_i[c_i + 6];
            n_tmp += d;
            FF0_tmp += d * LP->cc[66 * b_i + 2];
            F[c_i] = FF0_tmp;
            b_SV[c_i] = (SV->A0[c_i] * LP->c0[3 * b_i] +
                         SV->A0[c_i + 3] * LP->c0[3 * b_i + 1]) +
                        SV->A0[c_i + 6] * LP->c0[3 * b_i + 2];
            T[c_i] = n_tmp;
            TT0[c_i] = n_tmp * SV->q[b_i];
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
          A_I_BB_tmp = 3 * b_i + 2;
          b_SV_tmp_tmp = SV->ww[A_I_BB_tmp];
          SV_tmp = 3 * b_i + 1;
          FF0_tmp = SV->ww[SV_tmp];
          FF0[0] = FF0_tmp * F[2] - F[1] * b_SV_tmp_tmp;
          SV_tmp_tmp = SV->ww[3 * b_i];
          FF0[1] = F[0] * b_SV_tmp_tmp - SV_tmp_tmp * F[2];
          FF0[2] = SV_tmp_tmp * F[1] - F[0] * FF0_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          SV->vv[3 * b_i] =
              (((SV->v0[0] + (SV->w0[1] * b_SV[2] - b_SV[1] * SV->w0[2])) -
                FF0[0]) +
               (FF0_tmp * TT0[2] - TT0[1] * b_SV_tmp_tmp)) +
              T[0] * SV->qd[b_i];
          SV->vv[SV_tmp] =
              (((SV->v0[1] + (b_SV[0] * SV->w0[2] - SV->w0[0] * b_SV[2])) -
                FF0[1]) +
               (TT0[0] * b_SV_tmp_tmp - SV_tmp_tmp * TT0[2])) +
              T[1] * SV->qd[b_i];
          SV->vv[A_I_BB_tmp] =
              (((SV->v0[2] + (SV->w0[0] * b_SV[1] - b_SV[0] * SV->w0[1])) -
                FF0[2]) +
               (SV_tmp_tmp * TT0[1] - TT0[0] * FF0_tmp)) +
              T[2] * SV->qd[b_i];
        }
        /*  Current (i-th) link doesn't connect to the 0-th link */
      } else {
        n_tmp = d * 3.0;
        if (!(n_tmp == d * 3.0)) {
          emlrtErrorWithMessageIdR2018a(
              &st, &i_emlrtRTEI,
              "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
              "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
              0);
        }
        for (i1 = 0; i1 < 3; i1++) {
          d = n_tmp + ((real_T)i1 - 2.0);
          FF0_tmp = (int32_T)muDoubleScalarFloor(d);
          if (d != FF0_tmp) {
            emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 63, &fb_emlrtBCI, &st);
          }
          A_I_BB_tmp = 3 * ((int32_T)d - 1);
          A_I_BB[3 * i1] = SV->AA[A_I_BB_tmp];
          if (d != FF0_tmp) {
            emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 63, &fb_emlrtBCI, &st);
          }
          A_I_BB[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
          if (d != FF0_tmp) {
            emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > 63)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 63, &fb_emlrtBCI, &st);
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
          d = LP->BB[b_i];
          i1 = (int32_T)muDoubleScalarFloor(d);
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &g_emlrtDCI, &st);
          }
          i2 = (int32_T)d;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 21, &v_emlrtBCI, &st);
          }
          for (i2 = 0; i2 < 3; i2++) {
            b_SV[i2] =
                SV->ww[i2 + 3 * ((int32_T)LP->BB[b_i] - 1)] +
                ((A_I_i[i2] * 0.0 + A_I_i[i2 + 3] * 0.0) + A_I_i[i2 + 6]) *
                    SV->qd[b_i];
          }
          SV->ww[3 * b_i] = b_SV[0];
          i2 = 3 * b_i + 1;
          SV->ww[i2] = b_SV[1];
          d_i = 3 * b_i + 2;
          SV->ww[d_i] = b_SV[2];
          d = LP->BB[b_i];
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &j_emlrtDCI, &st);
          }
          A_I_BB_tmp = 3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i;
          for (SV_tmp = 0; SV_tmp < 3; SV_tmp++) {
            F[SV_tmp] = (A_I_i[SV_tmp] * LP->cc[66 * b_i] +
                         A_I_i[SV_tmp + 3] * LP->cc[66 * b_i + 1]) +
                        A_I_i[SV_tmp + 6] * LP->cc[66 * b_i + 2];
            b_SV[SV_tmp] = (A_I_BB[SV_tmp] * LP->cc[A_I_BB_tmp] +
                            A_I_BB[SV_tmp + 3] * LP->cc[A_I_BB_tmp + 1]) +
                           A_I_BB[SV_tmp + 6] * LP->cc[A_I_BB_tmp + 2];
          }
          d = LP->BB[b_i];
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &i_emlrtDCI, &st);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          SV_tmp = (int32_T)d;
          A_I_BB_tmp = 3 * (SV_tmp - 1);
          b_n_tmp = SV->ww[A_I_BB_tmp + 2];
          c_n_tmp = SV->ww[A_I_BB_tmp + 1];
          n_tmp = SV->ww[A_I_BB_tmp];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_SV_tmp_tmp = SV->ww[d_i];
          FF0_tmp = SV->ww[i2];
          SV_tmp_tmp = SV->ww[3 * b_i];
          if (SV_tmp != i1) {
            emlrtIntegerCheckR2012b(d, &h_emlrtDCI, &st);
          }
          d = (SV->vv[A_I_BB_tmp + 1] + (b_SV[0] * b_n_tmp - n_tmp * b_SV[2])) -
              (F[0] * b_SV_tmp_tmp - SV_tmp_tmp * F[2]);
          n_tmp =
              (SV->vv[A_I_BB_tmp + 2] + (n_tmp * b_SV[1] - b_SV[0] * c_n_tmp)) -
              (SV_tmp_tmp * F[1] - F[0] * FF0_tmp);
          SV->vv[3 * b_i] =
              (SV->vv[A_I_BB_tmp] + (c_n_tmp * b_SV[2] - b_SV[1] * b_n_tmp)) -
              (FF0_tmp * F[2] - F[1] * b_SV_tmp_tmp);
          SV->vv[i2] = d;
          SV->vv[d_i] = n_tmp;
          /*  Prismatic joint */
        } else {
          d = LP->BB[b_i];
          i1 = (int32_T)muDoubleScalarFloor(d);
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &k_emlrtDCI, &st);
          }
          i2 = (int32_T)d;
          if ((i2 < 1) || (i2 > 21)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 21, &w_emlrtBCI, &st);
          }
          SV_tmp = 3 * (i2 - 1);
          b_SV_tmp_tmp = SV->ww[SV_tmp + 1];
          SV_tmp_tmp = SV->ww[SV_tmp + 2];
          SV->ww[3 * b_i] = SV->ww[SV_tmp];
          d_i = 3 * b_i + 1;
          SV->ww[d_i] = b_SV_tmp_tmp;
          A_I_BB_tmp = 3 * b_i + 2;
          SV->ww[A_I_BB_tmp] = SV_tmp_tmp;
          if (i2 != i1) {
            emlrtIntegerCheckR2012b(d, &n_emlrtDCI, &st);
          }
          for (i2 = 0; i2 < 3; i2++) {
            d = A_I_i[i2];
            n_tmp = d * LP->cc[66 * b_i];
            FF0_tmp = d * 0.0;
            d = A_I_i[i2 + 3];
            n_tmp += d * LP->cc[66 * b_i + 1];
            FF0_tmp += d * 0.0;
            d = A_I_i[i2 + 6];
            n_tmp += d * LP->cc[66 * b_i + 2];
            FF0_tmp += d;
            F[i2] = n_tmp;
            b_SV[i2] =
                (A_I_BB[i2] *
                     LP->cc[3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i] +
                 A_I_BB[i2 + 3] *
                     LP->cc[(3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i) + 1]) +
                A_I_BB[i2 + 6] *
                    LP->cc[(3 * ((int32_T)LP->BB[b_i] - 1) + 63 * b_i) + 2];
            TT0[i2] = FF0_tmp * SV->q[b_i];
          }
          d = LP->BB[b_i];
          if (d != i1) {
            emlrtIntegerCheckR2012b(d, &m_emlrtDCI, &st);
          }
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          T[0] = SV->ww[SV_tmp + 1] * b_SV[2] - b_SV[1] * SV->ww[SV_tmp + 2];
          T[1] = b_SV[0] * SV->ww[SV_tmp + 2] - SV->ww[SV_tmp] * b_SV[2];
          T[2] = SV->ww[SV_tmp] * b_SV[1] - b_SV[0] * SV->ww[SV_tmp + 1];
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          b_SV_tmp_tmp = SV->ww[A_I_BB_tmp];
          FF0_tmp = SV->ww[d_i];
          FF0[0] = FF0_tmp * F[2] - F[1] * b_SV_tmp_tmp;
          SV_tmp_tmp = SV->ww[3 * b_i];
          FF0[1] = F[0] * b_SV_tmp_tmp - SV_tmp_tmp * F[2];
          FF0[2] = SV_tmp_tmp * F[1] - F[0] * FF0_tmp;
          /* CROSS	Vector cross product */
          /*  */
          /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
          /*  */
          /* 	Copyright (C) Peter Corke 1990 */
          /*  */
          F[0] = FF0_tmp * TT0[2] - TT0[1] * b_SV_tmp_tmp;
          F[1] = TT0[0] * b_SV_tmp_tmp - SV_tmp_tmp * TT0[2];
          F[2] = SV_tmp_tmp * TT0[1] - TT0[0] * FF0_tmp;
          if ((int32_T)d != i1) {
            emlrtIntegerCheckR2012b(d, &l_emlrtDCI, &st);
          }
          for (i1 = 0; i1 < 3; i1++) {
            T[i1] = (((SV->vv[i1 + SV_tmp] + T[i1]) - FF0[i1]) + F[i1]) +
                    ((A_I_i[i1] * 0.0 + A_I_i[i1 + 3] * 0.0) + A_I_i[i1 + 6]) *
                        SV->qd[b_i];
          }
          SV->vv[3 * b_i] = T[0];
          SV->vv[d_i] = T[1];
          SV->vv[A_I_BB_tmp] = T[2];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
  }
  /* %%EOF */
  /*  Calculation of acceletion vectors vd,wd */
  /*  NOTE:	vd,wd are in the Inertial frame */
  st.site = &b_emlrtRSI;
  calc_acc(&st, LP->num_q, LP->J_type, LP->BB, LP->cc, LP->c0, SV);
  /*  Calculation of inertia force & torque of link 0 */
  /*  NOTE:	FF,TT(FF0,TT0) are in the Inertial frame. */
  for (b_i = 0; b_i < 3; b_i++) {
    FF0[b_i] = LP->m0 * SV->vd0[b_i];
    d = A_I_0[b_i];
    n_tmp = A_I_0[b_i + 3];
    FF0_tmp = A_I_0[b_i + 6];
    for (i = 0; i < 3; i++) {
      b_A_I_0[b_i + 3 * i] =
          (d * LP->inertia0[3 * i] + n_tmp * LP->inertia0[3 * i + 1]) +
          FF0_tmp * LP->inertia0[3 * i + 2];
    }
    d = b_A_I_0[b_i];
    n_tmp = b_A_I_0[b_i + 3];
    FF0_tmp = b_A_I_0[b_i + 6];
    SV_tmp_tmp = 0.0;
    for (i = 0; i < 3; i++) {
      b_SV_tmp_tmp =
          (d * A_I_0[i] + n_tmp * A_I_0[i + 3]) + FF0_tmp * A_I_0[i + 6];
      A_I_BB[b_i + 3 * i] = b_SV_tmp_tmp;
      SV_tmp_tmp += b_SV_tmp_tmp * SV->w0[i];
    }
    b_SV[b_i] = SV_tmp_tmp;
  }
  /* CROSS	Vector cross product */
  /*  */
  /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
  /*  */
  /* 	Copyright (C) Peter Corke 1990 */
  /*  */
  T[0] = SV->w0[1] * b_SV[2] - b_SV[1] * SV->w0[2];
  T[1] = b_SV[0] * SV->w0[2] - SV->w0[0] * b_SV[2];
  T[2] = SV->w0[0] * b_SV[1] - b_SV[0] * SV->w0[1];
  d = SV->wd0[0];
  n_tmp = SV->wd0[1];
  FF0_tmp = SV->wd0[2];
  for (i = 0; i < 3; i++) {
    TT0[i] =
        ((A_I_BB[i] * d + A_I_BB[i + 3] * n_tmp) + A_I_BB[i + 6] * FF0_tmp) +
        T[i];
  }
  /*  Calculation of inertia force & torque of link i */
  /*  from link 1 to n */
  /*  Single or multi body ? */
  /*  If a Multi body system, */
  if (!(LP->num_q >= 0.0)) {
    emlrtNonNegativeCheckR2012b(LP->num_q, &emlrtDCI, (emlrtConstCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(LP->num_q);
  if (LP->num_q != i) {
    emlrtIntegerCheckR2012b(LP->num_q, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &FF, &l_emlrtRTEI);
  i1 = FF->size[0] * FF->size[1];
  FF->size[0] = 3;
  i2 = (int32_T)LP->num_q;
  FF->size[1] = i2;
  emxEnsureCapacity_real_T(sp, FF, i1, &l_emlrtRTEI);
  FF_data = FF->data;
  SV_tmp = 3 * i2;
  for (i1 = 0; i1 < SV_tmp; i1++) {
    FF_data[i1] = 0.0;
  }
  if (i2 != i) {
    emlrtIntegerCheckR2012b(LP->num_q, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &TT, &m_emlrtRTEI);
  i1 = TT->size[0] * TT->size[1];
  TT->size[0] = 3;
  TT->size[1] = i2;
  emxEnsureCapacity_real_T(sp, TT, i1, &m_emlrtRTEI);
  TT_data = TT->data;
  for (i1 = 0; i1 < SV_tmp; i1++) {
    TT_data[i1] = 0.0;
  }
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                (int32_T)LP->num_q, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i2; b_i++) {
    real_T b_A_I_i[9];
    SV_tmp_tmp = ((real_T)b_i + 1.0) * 3.0;
    for (i1 = 0; i1 < 3; i1++) {
      d_i = (int32_T)(SV_tmp_tmp + ((real_T)i1 - 2.0));
      if ((d_i < 1) || (d_i > 63)) {
        emlrtDynamicBoundsCheckR2012b(d_i, 1, 63, &eb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      A_I_BB_tmp = 3 * (d_i - 1);
      A_I_i[3 * i1] = SV->AA[A_I_BB_tmp];
      A_I_i[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
      A_I_i[3 * i1 + 2] = SV->AA[A_I_BB_tmp + 2];
    }
    for (i1 = 0; i1 < 3; i1++) {
      d_i = (int32_T)(SV_tmp_tmp + ((real_T)i1 - 2.0));
      if ((d_i < 1) || (d_i > 63)) {
        emlrtDynamicBoundsCheckR2012b(d_i, 1, 63, &db_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      A_I_BB_tmp = 3 * (d_i - 1);
      A_I_BB[3 * i1] = LP->inertia[A_I_BB_tmp];
      A_I_BB[3 * i1 + 1] = LP->inertia[A_I_BB_tmp + 1];
      A_I_BB[3 * i1 + 2] = LP->inertia[A_I_BB_tmp + 2];
    }
    if (b_i + 1 > 21) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, 21, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((int32_T)((uint32_T)b_i + 1U) > FF->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                    FF->size[1], &u_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      d_i = i1 + 3 * b_i;
      FF_data[d_i] = LP->m[b_i] * SV->vd[d_i];
      d = A_I_i[i1];
      n_tmp = A_I_i[i1 + 3];
      FF0_tmp = A_I_i[i1 + 6];
      for (d_i = 0; d_i < 3; d_i++) {
        b_A_I_i[i1 + 3 * d_i] =
            (d * A_I_BB[3 * d_i] + n_tmp * A_I_BB[3 * d_i + 1]) +
            FF0_tmp * A_I_BB[3 * d_i + 2];
      }
      d = b_A_I_i[i1];
      n_tmp = b_A_I_i[i1 + 3];
      FF0_tmp = b_A_I_i[i1 + 6];
      SV_tmp_tmp = 0.0;
      for (d_i = 0; d_i < 3; d_i++) {
        b_SV_tmp_tmp = (d * A_I_i[d_i] + n_tmp * A_I_i[d_i + 3]) +
                       FF0_tmp * A_I_i[d_i + 6];
        b_A_I_0[i1 + 3 * d_i] = b_SV_tmp_tmp;
        SV_tmp_tmp += b_SV_tmp_tmp * SV->ww[d_i + 3 * b_i];
      }
      b_SV[i1] = SV_tmp_tmp;
    }
    /* CROSS	Vector cross product */
    /*  */
    /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
    /*  */
    /* 	Copyright (C) Peter Corke 1990 */
    /*  */
    i1 = 3 * b_i + 1;
    d = SV->ww[i1];
    d_i = 3 * b_i + 2;
    n_tmp = SV->ww[d_i];
    T[0] = d * b_SV[2] - b_SV[1] * n_tmp;
    FF0_tmp = SV->ww[3 * b_i];
    T[1] = b_SV[0] * n_tmp - FF0_tmp * b_SV[2];
    T[2] = FF0_tmp * b_SV[1] - b_SV[0] * d;
    if ((int32_T)((uint32_T)b_i + 1U) > TT->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                    TT->size[1], &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    d = SV->wd[3 * b_i];
    n_tmp = SV->wd[i1];
    FF0_tmp = SV->wd[d_i];
    for (i1 = 0; i1 < 3; i1++) {
      TT_data[i1 + 3 * b_i] = ((b_A_I_0[i1] * d + b_A_I_0[i1 + 3] * n_tmp) +
                               b_A_I_0[i1 + 6] * FF0_tmp) +
                              T[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  Equilibrium of forces & torques on each link */
  /*  On the i-th link */
  if (i2 != i) {
    emlrtIntegerCheckR2012b(LP->num_q, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &Fj, &n_emlrtRTEI);
  i1 = Fj->size[0] * Fj->size[1];
  Fj->size[0] = 3;
  Fj->size[1] = i2;
  emxEnsureCapacity_real_T(sp, Fj, i1, &n_emlrtRTEI);
  Fj_data = Fj->data;
  for (i1 = 0; i1 < SV_tmp; i1++) {
    Fj_data[i1] = 0.0;
  }
  if (i2 != i) {
    emlrtIntegerCheckR2012b(LP->num_q, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &Tj, &o_emlrtRTEI);
  i = Tj->size[0] * Tj->size[1];
  Tj->size[0] = 3;
  Tj->size[1] = i2;
  emxEnsureCapacity_real_T(sp, Tj, i, &o_emlrtRTEI);
  Tj_data = Tj->data;
  for (i = 0; i < SV_tmp; i++) {
    Tj_data[i] = 0.0;
  }
  if (LP->num_q != 0.0) {
    /*  Multi body system */
    /*  from link n to 1 */
    emlrtForLoopVectorCheckR2021a(LP->num_q, -1.0, 1.0, mxDOUBLE_CLASS,
                                  (int32_T)LP->num_q, &b_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (b_i = 0; b_i < i2; b_i++) {
      real_T Fj_tmp;
      real_T b_Fj_tmp;
      real_T c_Fj_tmp;
      real_T d_Fj_tmp;
      real_T e_Fj_tmp;
      real_T f_Fj_tmp;
      real_T g_Fj_tmp;
      int32_T Fj_tmp_tmp;
      c_i = i2 - b_i;
      F[0] = 0.0;
      T[0] = 0.0;
      F[1] = 0.0;
      T[1] = 0.0;
      F[2] = 0.0;
      T[2] = 0.0;
      i = i2 + (int32_T)(1.0 - ((real_T)c_i + 1.0));
      emlrtForLoopVectorCheckR2021a((real_T)c_i + 1.0, 1.0, LP->num_q,
                                    mxDOUBLE_CLASS, i, &c_emlrtRTEI,
                                    (emlrtConstCTX)sp);
      for (j = 0; j < i; j++) {
        b_SV_tmp_tmp = ((real_T)c_i + 1.0) + (real_T)j;
        if ((c_i < 1) || (c_i > 21)) {
          emlrtDynamicBoundsCheckR2012b(c_i, 1, 21, &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (b_SV_tmp_tmp != (int32_T)b_SV_tmp_tmp) {
          emlrtIntegerCheckR2012b(b_SV_tmp_tmp, &f_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)b_SV_tmp_tmp < 1) || ((int32_T)b_SV_tmp_tmp > 21)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_SV_tmp_tmp, 1, 21,
                                        &c_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)b_SV_tmp_tmp < 1) ||
            ((int32_T)b_SV_tmp_tmp > Fj->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_SV_tmp_tmp, 1, Fj->size[1],
                                        &d_emlrtBCI, (emlrtConstCTX)sp);
        }
        SV_tmp_tmp = LP->SS[(c_i + 21 * ((int32_T)b_SV_tmp_tmp - 1)) - 1];
        SV_tmp = 3 * ((int32_T)b_SV_tmp_tmp - 1);
        F[0] += SV_tmp_tmp * Fj_data[SV_tmp];
        F[1] += SV_tmp_tmp * Fj_data[SV_tmp + 1];
        F[2] += SV_tmp_tmp * Fj_data[SV_tmp + 2];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      if ((c_i < 1) || (c_i > 21)) {
        emlrtDynamicBoundsCheckR2012b(c_i, 1, 21, &f_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((c_i < 1) || (c_i > FF->size[1])) {
        emlrtDynamicBoundsCheckR2012b(c_i, 1, FF->size[1], &e_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((c_i < 1) || (c_i > Fj->size[1])) {
        emlrtDynamicBoundsCheckR2012b(c_i, 1, Fj->size[1], &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Fj_tmp_tmp = 3 * (c_i - 1);
      Fj_tmp = LP->SE[c_i - 1];
      b_Fj_tmp = FF_data[Fj_tmp_tmp];
      c_Fj_tmp = SV->Fe[Fj_tmp_tmp];
      Fj_data[Fj_tmp_tmp] = (b_Fj_tmp + F[0]) + Fj_tmp * c_Fj_tmp;
      d_Fj_tmp = FF_data[Fj_tmp_tmp + 1];
      e_Fj_tmp = SV->Fe[Fj_tmp_tmp + 1];
      Fj_data[Fj_tmp_tmp + 1] = (d_Fj_tmp + F[1]) + Fj_tmp * e_Fj_tmp;
      f_Fj_tmp = FF_data[Fj_tmp_tmp + 2];
      g_Fj_tmp = SV->Fe[Fj_tmp_tmp + 2];
      Fj_data[Fj_tmp_tmp + 2] = (f_Fj_tmp + F[2]) + Fj_tmp * g_Fj_tmp;
      emlrtForLoopVectorCheckR2021a((real_T)c_i + 1.0, 1.0, LP->num_q,
                                    mxDOUBLE_CLASS, i, &d_emlrtRTEI,
                                    (emlrtConstCTX)sp);
      for (j = 0; j < i; j++) {
        boolean_T a;
        b_SV_tmp_tmp = ((real_T)c_i + 1.0) + (real_T)j;
        a = (LP->J_type[c_i - 1] == 'P');
        d_i = c_i * 3 - 3;
        for (i1 = 0; i1 < 3; i1++) {
          A_I_BB_tmp = 3 * (i1 + d_i);
          b_A_I_0[3 * i1] = SV->AA[A_I_BB_tmp];
          b_A_I_0[3 * i1 + 1] = SV->AA[A_I_BB_tmp + 1];
          b_A_I_0[3 * i1 + 2] = SV->AA[A_I_BB_tmp + 2];
          SV_tmp = i1 + Fj_tmp_tmp;
          b_SV[i1] = (LP->cc[SV_tmp + 63 * ((int32_T)b_SV_tmp_tmp - 1)] -
                      LP->cc[SV_tmp + 63 * (c_i - 1)]) +
                     (real_T)a * (real_T)b[i1] * SV->q[c_i - 1];
        }
        d = b_SV[0];
        n_tmp = b_SV[1];
        FF0_tmp = b_SV[2];
        for (i1 = 0; i1 < 3; i1++) {
          b_SV[i1] = (b_A_I_0[i1] * d + b_A_I_0[i1 + 3] * n_tmp) +
                     b_A_I_0[i1 + 6] * FF0_tmp;
        }
        if (((int32_T)b_SV_tmp_tmp < 1) || ((int32_T)b_SV_tmp_tmp > 21)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_SV_tmp_tmp, 1, 21,
                                        &h_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)b_SV_tmp_tmp < 1) ||
            ((int32_T)b_SV_tmp_tmp > Fj->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_SV_tmp_tmp, 1, Fj->size[1],
                                        &i_emlrtBCI, (emlrtConstCTX)sp);
        }
        /* CROSS	Vector cross product */
        /*  */
        /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
        /*  */
        /* 	Copyright (C) Peter Corke 1990 */
        /*  */
        A_I_BB_tmp = 3 * ((int32_T)b_SV_tmp_tmp - 1);
        b_n_tmp = Fj_data[A_I_BB_tmp + 2];
        c_n_tmp = Fj_data[A_I_BB_tmp + 1];
        n_tmp = Fj_data[A_I_BB_tmp];
        if (((int32_T)b_SV_tmp_tmp < 1) ||
            ((int32_T)b_SV_tmp_tmp > Tj->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_SV_tmp_tmp, 1, Tj->size[1],
                                        &j_emlrtBCI, (emlrtConstCTX)sp);
        }
        SV_tmp_tmp = LP->SS[(c_i + 21 * ((int32_T)b_SV_tmp_tmp - 1)) - 1];
        T[0] += SV_tmp_tmp *
                ((b_SV[1] * b_n_tmp - c_n_tmp * b_SV[2]) + Tj_data[A_I_BB_tmp]);
        T[1] += SV_tmp_tmp * ((n_tmp * b_SV[2] - b_SV[0] * b_n_tmp) +
                              Tj_data[A_I_BB_tmp + 1]);
        T[2] += SV_tmp_tmp * ((b_SV[0] * c_n_tmp - n_tmp * b_SV[1]) +
                              Tj_data[A_I_BB_tmp + 2]);
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      d_i = c_i * 3 - 3;
      for (i = 0; i < 3; i++) {
        A_I_BB_tmp = 3 * (i + d_i);
        A_I_i[3 * i] = SV->AA[A_I_BB_tmp];
        A_I_i[3 * i + 1] = SV->AA[A_I_BB_tmp + 1];
        A_I_i[3 * i + 2] = SV->AA[A_I_BB_tmp + 2];
      }
      /*  Rotational joint */
      i = Fj_tmp_tmp + 63 * (c_i - 1);
      for (i1 = 0; i1 < 3; i1++) {
        b_SV[i1] = (A_I_i[i1] * LP->cc[i] + A_I_i[i1 + 3] * LP->cc[i + 1]) +
                   A_I_i[i1 + 6] * LP->cc[i + 2];
      }
      if ((c_i < 1) || (c_i > FF->size[1])) {
        emlrtDynamicBoundsCheckR2012b(c_i, 1, FF->size[1], &m_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      if ((c_i < 1) || (c_i > TT->size[1])) {
        emlrtDynamicBoundsCheckR2012b(c_i, 1, TT->size[1], &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((c_i < 1) || (c_i > Tj->size[1])) {
        emlrtDynamicBoundsCheckR2012b(c_i, 1, Tj->size[1], &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Tj_data[Fj_tmp_tmp] = (TT_data[Fj_tmp_tmp] + T[0]) -
                            (b_SV[1] * f_Fj_tmp - d_Fj_tmp * b_SV[2]);
      b_SV_tmp_tmp = SV->q[c_i - 1];
      SV_tmp_tmp = 0.0 * b_SV_tmp_tmp;
      Tj_data[Fj_tmp_tmp + 1] = (TT_data[Fj_tmp_tmp + 1] + T[1]) -
                                (b_Fj_tmp * b_SV[2] - b_SV[0] * f_Fj_tmp);
      Tj_data[Fj_tmp_tmp + 2] = (TT_data[Fj_tmp_tmp + 2] + T[2]) -
                                (b_SV[0] * d_Fj_tmp - b_Fj_tmp * b_SV[1]);
      d = (LP->ce[Fj_tmp_tmp] - LP->cc[3 * (c_i - 1) + 63 * (c_i - 1)]) +
          SV_tmp_tmp;
      n_tmp = (LP->ce[Fj_tmp_tmp + 1] -
               LP->cc[(3 * (c_i - 1) + 63 * (c_i - 1)) + 1]) +
              SV_tmp_tmp;
      FF0_tmp = (LP->ce[Fj_tmp_tmp + 2] -
                 LP->cc[(3 * (c_i - 1) + 63 * (c_i - 1)) + 2]) +
                (real_T)(LP->J_type[c_i - 1] == 'P') * b_SV_tmp_tmp;
      for (i = 0; i < 3; i++) {
        b_SV[i] =
            (A_I_i[i] * d + A_I_i[i + 3] * n_tmp) + A_I_i[i + 6] * FF0_tmp;
      }
      /* CROSS	Vector cross product */
      /*  */
      /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
      /*  */
      /* 	Copyright (C) Peter Corke 1990 */
      /*  */
      if ((c_i < 1) || (c_i > Tj->size[1])) {
        emlrtDynamicBoundsCheckR2012b(c_i, 1, Tj->size[1], &o_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      d = Tj_data[Fj_tmp_tmp + 1] +
          Fj_tmp * ((c_Fj_tmp * b_SV[2] - b_SV[0] * g_Fj_tmp) +
                    SV->Te[Fj_tmp_tmp + 1]);
      n_tmp = Tj_data[Fj_tmp_tmp + 2] +
              Fj_tmp * ((b_SV[0] * e_Fj_tmp - c_Fj_tmp * b_SV[1]) +
                        SV->Te[Fj_tmp_tmp + 2]);
      Tj_data[Fj_tmp_tmp] +=
          Fj_tmp *
          ((b_SV[1] * g_Fj_tmp - e_Fj_tmp * b_SV[2]) + SV->Te[Fj_tmp_tmp]);
      Tj_data[Fj_tmp_tmp + 1] = d;
      Tj_data[Fj_tmp_tmp + 2] = n_tmp;
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
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                  (int32_T)LP->num_q, &e_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (b_i = 0; b_i < i2; b_i++) {
      if ((int32_T)((uint32_T)b_i + 1U) > 21) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                      &ab_emlrtBCI, (emlrtConstCTX)sp);
      }
      d = LP->S0[b_i];
      if (d != 0.0) {
        if (b_i + 1 > Fj->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Fj->size[1], &p_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        F[0] += d * Fj_data[3 * b_i];
        F[1] += d * Fj_data[3 * b_i + 1];
        F[2] += d * Fj_data[3 * b_i + 2];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    FF0[0] += F[0];
    FF0[1] += F[1];
    FF0[2] += F[2];
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                  (int32_T)LP->num_q, &f_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (b_i = 0; b_i < i2; b_i++) {
      if ((int32_T)((uint32_T)b_i + 1U) > 21) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                      &bb_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (LP->S0[b_i] != 0.0) {
        d = LP->c0[3 * b_i];
        i = 3 * b_i + 1;
        n_tmp = LP->c0[i];
        i1 = 3 * b_i + 2;
        FF0_tmp = LP->c0[i1];
        for (d_i = 0; d_i < 3; d_i++) {
          b_SV[d_i] = (A_I_0[d_i] * d + A_I_0[d_i + 3] * n_tmp) +
                      A_I_0[d_i + 6] * FF0_tmp;
        }
        if (b_i + 1 > Fj->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Fj->size[1], &q_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        /* CROSS	Vector cross product */
        /*  */
        /* 	CROSS(V1, V2) returns the vector cross product V1 x V2 */
        /*  */
        /* 	Copyright (C) Peter Corke 1990 */
        /*  */
        if (b_i + 1 > Tj->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Tj->size[1], &r_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        d = LP->S0[b_i];
        T[0] += d * ((b_SV[1] * Fj_data[i1] - Fj_data[i] * b_SV[2]) +
                     Tj_data[3 * b_i]);
        T[1] += d * ((Fj_data[3 * b_i] * b_SV[2] - b_SV[0] * Fj_data[i1]) +
                     Tj_data[i]);
        T[2] += d * ((b_SV[0] * Fj_data[i] - Fj_data[3 * b_i] * b_SV[1]) +
                     Tj_data[i1]);
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    TT0[0] += T[0];
    TT0[1] += T[1];
    TT0[2] += T[2];
  }
  emxFree_real_T(sp, &TT);
  emxFree_real_T(sp, &FF);
  /*  Calculation of torques of each joint */
  /*  Single body */
  if (LP->num_q == 0.0) {
    /*  Single body, */
    Force_size[0] = 6;
    Force_data[0] = FF0[0];
    Force_data[3] = TT0[0];
    Force_data[1] = FF0[1];
    Force_data[4] = TT0[1];
    Force_data[2] = FF0[2];
    Force_data[5] = TT0[2];
  } else {
    /*  Multi body system */
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                  (int32_T)LP->num_q, &g_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (b_i = 0; b_i < i2; b_i++) {
      SV_tmp_tmp = ((real_T)b_i + 1.0) * 3.0;
      for (i = 0; i < 3; i++) {
        i1 = (int32_T)(SV_tmp_tmp + ((real_T)i - 2.0));
        if ((i1 < 1) || (i1 > 63)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, 63, &cb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        A_I_BB_tmp = 3 * (i1 - 1);
        A_I_i[3 * i] = SV->AA[A_I_BB_tmp];
        A_I_i[3 * i + 1] = SV->AA[A_I_BB_tmp + 1];
        A_I_i[3 * i + 2] = SV->AA[A_I_BB_tmp + 2];
      }
      if ((int32_T)((uint32_T)b_i + 1U) > 21) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                      &y_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (LP->J_type[b_i] == 'R') {
        /*  Rotational joint */
        if (b_i + 1 > Tj->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Tj->size[1], &s_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        SV_tmp_tmp = 0.0;
        for (i = 0; i < 3; i++) {
          SV_tmp_tmp += Tj_data[i + 3 * b_i] *
                        ((A_I_i[i] * 0.0 + A_I_i[i + 3] * 0.0) + A_I_i[i + 6]);
        }
        SV->tau[b_i] = SV_tmp_tmp;
      } else {
        /*  Prismatic joint */
        if (b_i + 1 > Fj->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Fj->size[1], &t_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        SV_tmp_tmp = 0.0;
        for (i = 0; i < 3; i++) {
          SV_tmp_tmp += Fj_data[i + 3 * b_i] *
                        ((A_I_i[i] * 0.0 + A_I_i[i + 3] * 0.0) + A_I_i[i + 6]);
        }
        SV->tau[b_i] = SV_tmp_tmp;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    /*  Multi body system, */
    Force_size[0] = 27;
    Force_data[0] = FF0[0];
    Force_data[3] = TT0[0];
    Force_data[1] = FF0[1];
    Force_data[4] = TT0[1];
    Force_data[2] = FF0[2];
    Force_data[5] = TT0[2];
    memcpy(&Force_data[6], &SV->tau[0], 21U * sizeof(real_T));
  }
  emxFree_real_T(sp, &Tj);
  emxFree_real_T(sp, &Fj);
  /*  Compose a generalized force */
  /*  Single or multi body ? */
  /* %%EOF */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (r_ne.c) */
