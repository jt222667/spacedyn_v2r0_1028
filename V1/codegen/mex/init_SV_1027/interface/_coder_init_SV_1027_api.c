/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_init_SV_1027_api.c
 *
 * Code generation for function '_coder_init_SV_1027_api'
 *
 */

/* Include files */
#include "_coder_init_SV_1027_api.h"
#include "init_SV_1027.h"
#include "init_SV_1027_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[63]);

static const mxArray *emlrt_marshallOut(const struct0_T *u);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[63])
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

static const mxArray *emlrt_marshallOut(const struct0_T *u)
{
  static const int32_T iv[2] = {3, 3};
  static const int32_T iv1[2] = {3, 63};
  static const int32_T i = 3;
  static const int32_T i1 = 3;
  static const int32_T i10 = 3;
  static const int32_T i11 = 3;
  static const int32_T i12 = 21;
  static const int32_T i3 = 3;
  static const int32_T i4 = 3;
  static const int32_T i5 = 3;
  static const int32_T i6 = 3;
  static const int32_T i7 = 21;
  static const int32_T i8 = 21;
  static const int32_T i9 = 21;
  static const char_T *sv[21] = {"R0",  "Q0",  "A0", "AA", "RR",  "v0", "w0",
                                 "vd0", "wd0", "q",  "qd", "qdd", "vv", "ww",
                                 "vd",  "wd",  "F0", "T0", "Fe",  "Te", "tau"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T i2;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 21, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->R0[0];
  pData[1] = u->R0[1];
  pData[2] = u->R0[2];
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "R0", b_y, 0);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->Q0[0];
  pData[1] = u->Q0[1];
  pData[2] = u->Q0[2];
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "Q0", c_y, 1);
  d_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i2 = 0;
  for (b_i = 0; b_i < 3; b_i++) {
    pData[i2] = u->A0[3 * b_i];
    pData[i2 + 1] = u->A0[3 * b_i + 1];
    pData[i2 + 2] = u->A0[3 * b_i + 2];
    i2 += 3;
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "A0", d_y, 2);
  e_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i2 = 0;
  for (b_i = 0; b_i < 63; b_i++) {
    pData[i2] = u->AA[3 * b_i];
    pData[i2 + 1] = u->AA[3 * b_i + 1];
    pData[i2 + 2] = u->AA[3 * b_i + 2];
    i2 += 3;
  }
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "AA", e_y, 3);
  emlrtSetFieldR2017b(y, 0, "RR", b_emlrt_marshallOut(u->RR), 4);
  f_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i3, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->v0[0];
  pData[1] = u->v0[1];
  pData[2] = u->v0[2];
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "v0", f_y, 5);
  g_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i4, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->w0[0];
  pData[1] = u->w0[1];
  pData[2] = u->w0[2];
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "w0", g_y, 6);
  h_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i5, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->vd0[0];
  pData[1] = u->vd0[1];
  pData[2] = u->vd0[2];
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "vd0", h_y, 7);
  i_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i6, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->wd0[0];
  pData[1] = u->wd0[1];
  pData[2] = u->wd0[2];
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "wd0", i_y, 8);
  j_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i7, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 21; b_i++) {
    pData[b_i] = u->q[b_i];
  }
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(y, 0, "q", j_y, 9);
  k_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i8, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 21; b_i++) {
    pData[b_i] = u->qd[b_i];
  }
  emlrtAssign(&k_y, m);
  emlrtSetFieldR2017b(y, 0, "qd", k_y, 10);
  l_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i9, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 21; b_i++) {
    pData[b_i] = u->qdd[b_i];
  }
  emlrtAssign(&l_y, m);
  emlrtSetFieldR2017b(y, 0, "qdd", l_y, 11);
  emlrtSetFieldR2017b(y, 0, "vv", b_emlrt_marshallOut(u->vv), 12);
  emlrtSetFieldR2017b(y, 0, "ww", b_emlrt_marshallOut(u->ww), 13);
  emlrtSetFieldR2017b(y, 0, "vd", b_emlrt_marshallOut(u->vd), 14);
  emlrtSetFieldR2017b(y, 0, "wd", b_emlrt_marshallOut(u->wd), 15);
  m_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i10, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->F0[0];
  pData[1] = u->F0[1];
  pData[2] = u->F0[2];
  emlrtAssign(&m_y, m);
  emlrtSetFieldR2017b(y, 0, "F0", m_y, 16);
  n_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i11, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->T0[0];
  pData[1] = u->T0[1];
  pData[2] = u->T0[2];
  emlrtAssign(&n_y, m);
  emlrtSetFieldR2017b(y, 0, "T0", n_y, 17);
  emlrtSetFieldR2017b(y, 0, "Fe", b_emlrt_marshallOut(u->Fe), 18);
  emlrtSetFieldR2017b(y, 0, "Te", b_emlrt_marshallOut(u->Te), 19);
  o_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i12, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 21; b_i++) {
    pData[b_i] = u->tau[b_i];
  }
  emlrtAssign(&o_y, m);
  emlrtSetFieldR2017b(y, 0, "tau", o_y, 20);
  return y;
}

void init_SV_1027_api(const mxArray **plhs)
{
  struct0_T r;
  /* Invoke the target function */
  /* Marshall function outputs */
  init_SV_1027(&r);
  *plhs = emlrt_marshallOut(&r);
}

/* End of code generation (_coder_init_SV_1027_api.c) */
