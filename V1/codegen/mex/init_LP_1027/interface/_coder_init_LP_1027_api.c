/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_init_LP_1027_api.c
 *
 * Code generation for function '_coder_init_LP_1027_api'
 *
 */

/* Include files */
#include "_coder_init_LP_1027_api.h"
#include "init_LP_1027.h"
#include "init_LP_1027_data.h"
#include "init_LP_1027_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[21]);

static const mxArray *c_emlrt_marshallOut(const real_T u[63]);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[21])
{
  static const int32_T iv[2] = {1, 21};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (i = 0; i < 21; i++) {
    pData[i] = u[i];
  }
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u[63])
{
  static const int32_T iv[2] = {3, 21};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 21; b_i++) {
    pData[i] = u[3 * b_i];
    pData[i + 1] = u[3 * b_i + 1];
    pData[i + 2] = u[3 * b_i + 2];
    i += 3;
  }
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u)
{
  static const int32_T iv4[3] = {3, 21, 21};
  static const int32_T iv[2] = {3, 63};
  static const int32_T iv1[2] = {3, 3};
  static const int32_T iv2[2] = {1, 21};
  static const int32_T iv3[2] = {21, 21};
  static const char_T *sv[16] = {
      "num_q", "m0", "m",  "mass", "inertia", "inertia0", "J_type", "BB",
      "S0",    "SE", "SS", "Qi",   "Qe",      "cc",       "c0",     "ce"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 16, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(u->num_q);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "num_q", b_y, 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u->m0);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "m0", c_y, 1);
  emlrtSetFieldR2017b(y, 0, "m", b_emlrt_marshallOut(u->m), 2);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->mass);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "mass", d_y, 3);
  e_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 63; b_i++) {
    pData[i] = u->inertia[3 * b_i];
    pData[i + 1] = u->inertia[3 * b_i + 1];
    pData[i + 2] = u->inertia[3 * b_i + 2];
    i += 3;
  }
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "inertia", e_y, 4);
  f_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 3; b_i++) {
    pData[i] = u->inertia0[3 * b_i];
    pData[i + 1] = u->inertia0[3 * b_i + 1];
    pData[i + 2] = u->inertia0[3 * b_i + 2];
    i += 3;
  }
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "inertia0", f_y, 5);
  g_y = NULL;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 21, m, &u->J_type[0]);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "J_type", g_y, 6);
  emlrtSetFieldR2017b(y, 0, "BB", b_emlrt_marshallOut(u->BB), 7);
  emlrtSetFieldR2017b(y, 0, "S0", b_emlrt_marshallOut(u->S0), 8);
  emlrtSetFieldR2017b(y, 0, "SE", b_emlrt_marshallOut(u->SE), 9);
  h_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv3[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 21; b_i++) {
    for (c_i = 0; c_i < 21; c_i++) {
      pData[i + c_i] = u->SS[c_i + 21 * b_i];
    }
    i += 21;
  }
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "SS", h_y, 10);
  emlrtSetFieldR2017b(y, 0, "Qi", c_emlrt_marshallOut(u->Qi), 11);
  emlrtSetFieldR2017b(y, 0, "Qe", c_emlrt_marshallOut(u->Qe), 12);
  i_y = NULL;
  m = emlrtCreateNumericArray(3, (const void *)&iv4[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 21; b_i++) {
    for (c_i = 0; c_i < 21; c_i++) {
      int32_T i1;
      i1 = 3 * c_i + 63 * b_i;
      pData[i] = u->cc[i1];
      pData[i + 1] = u->cc[i1 + 1];
      pData[i + 2] = u->cc[i1 + 2];
      i += 3;
    }
  }
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "cc", i_y, 13);
  emlrtSetFieldR2017b(y, 0, "c0", c_emlrt_marshallOut(u->c0), 14);
  emlrtSetFieldR2017b(y, 0, "ce", c_emlrt_marshallOut(u->ce), 15);
  return y;
}

void init_LP_1027_api(const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  struct0_T LP;
  st.tls = emlrtRootTLSGlobal;
  /* Invoke the target function */
  init_LP_1027(&st, &LP);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, &LP);
}

/* End of code generation (_coder_init_LP_1027_api.c) */
