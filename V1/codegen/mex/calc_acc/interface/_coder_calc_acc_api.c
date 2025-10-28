/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calc_acc_api.c
 *
 * Code generation for function '_coder_calc_acc_api'
 *
 */

/* Include files */
#include "_coder_calc_acc_api.h"
#include "calc_acc.h"
#include "calc_acc_data.h"
#include "calc_acc_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static const mxArray *b_emlrt_marshallOut(const real_T u[63]);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[21]);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[189]);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *LP,
                             const char_T *identifier, struct0_T *y);

static const mxArray *emlrt_marshallOut(const struct1_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[21]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[441]);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[63]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[1323]);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SV,
                               const char_T *identifier, struct1_T *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[21]);

static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[21]);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[189]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[21]);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[441]);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[63]);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[1323]);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[21]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[16] = {
      "num_q", "m0", "m",  "mass", "inertia", "inertia0", "J_type", "BB",
      "S0",    "SE", "SS", "Qi",   "Qe",      "cc",       "c0",     "ce"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 16,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "num_q";
  y->num_q = c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "num_q")),
      &thisId);
  thisId.fIdentifier = "m0";
  y->m0 = c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "m0")),
      &thisId);
  thisId.fIdentifier = "m";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "m")),
      &thisId, y->m);
  thisId.fIdentifier = "mass";
  y->mass = c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "mass")),
      &thisId);
  thisId.fIdentifier = "inertia";
  e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "inertia")),
      &thisId, y->inertia);
  thisId.fIdentifier = "inertia0";
  f_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "inertia0")),
      &thisId, y->inertia0);
  thisId.fIdentifier = "J_type";
  g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "J_type")),
      &thisId, y->J_type);
  thisId.fIdentifier = "BB";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "BB")),
      &thisId, y->BB);
  thisId.fIdentifier = "S0";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8, "S0")),
      &thisId, y->S0);
  thisId.fIdentifier = "SE";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "SE")),
      &thisId, y->SE);
  thisId.fIdentifier = "SS";
  h_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10, "SS")),
      &thisId, y->SS);
  thisId.fIdentifier = "Qi";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 11, "Qi")),
      &thisId, y->Qi);
  thisId.fIdentifier = "Qe";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 12, "Qe")),
      &thisId, y->Qe);
  thisId.fIdentifier = "cc";
  j_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 13, "cc")),
      &thisId, y->cc);
  thisId.fIdentifier = "c0";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 14, "c0")),
      &thisId, y->c0);
  thisId.fIdentifier = "ce";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 15, "ce")),
      &thisId, y->ce);
  emlrtDestroyArray(&u);
}

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

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[21])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[189])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *LP,
                             const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(LP), &thisId, y);
  emlrtDestroyArray(&LP);
}

static const mxArray *emlrt_marshallOut(const struct1_T *u)
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

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[21])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[441])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[63])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[1323])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SV,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(SV), &thisId, y);
  emlrtDestroyArray(&SV);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[21] = {
      "R0",  "Q0", "A0", "AA", "RR", "v0", "w0", "vd0", "wd0", "q",  "qd",
      "qdd", "vv", "ww", "vd", "wd", "F0", "T0", "Fe",  "Te",  "tau"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 21,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "R0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "R0")),
      &thisId, y->R0);
  thisId.fIdentifier = "Q0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "Q0")),
      &thisId, y->Q0);
  thisId.fIdentifier = "A0";
  f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "A0")),
      &thisId, y->A0);
  thisId.fIdentifier = "AA";
  e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "AA")),
      &thisId, y->AA);
  thisId.fIdentifier = "RR";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "RR")),
      &thisId, y->RR);
  thisId.fIdentifier = "v0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "v0")),
      &thisId, y->v0);
  thisId.fIdentifier = "w0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "w0")),
      &thisId, y->w0);
  thisId.fIdentifier = "vd0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "vd0")),
      &thisId, y->vd0);
  thisId.fIdentifier = "wd0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8, "wd0")),
      &thisId, y->wd0);
  thisId.fIdentifier = "q";
  n_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "q")),
      &thisId, y->q);
  thisId.fIdentifier = "qd";
  n_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10, "qd")),
      &thisId, y->qd);
  thisId.fIdentifier = "qdd";
  n_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 11, "qdd")),
      &thisId, y->qdd);
  thisId.fIdentifier = "vv";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 12, "vv")),
      &thisId, y->vv);
  thisId.fIdentifier = "ww";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 13, "ww")),
      &thisId, y->ww);
  thisId.fIdentifier = "vd";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 14, "vd")),
      &thisId, y->vd);
  thisId.fIdentifier = "wd";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 15, "wd")),
      &thisId, y->wd);
  thisId.fIdentifier = "F0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 16, "F0")),
      &thisId, y->F0);
  thisId.fIdentifier = "T0";
  m_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 17, "T0")),
      &thisId, y->T0);
  thisId.fIdentifier = "Fe";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 18, "Fe")),
      &thisId, y->Fe);
  thisId.fIdentifier = "Te";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 19, "Te")),
      &thisId, y->Te);
  thisId.fIdentifier = "tau";
  n_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 20, "tau")),
      &thisId, y->tau);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[21])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[21])
{
  static const int32_T dims[2] = {1, 21};
  real_T(*r)[21];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[21])emlrtMxGetData(src);
  for (i = 0; i < 21; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[189])
{
  static const int32_T dims[2] = {3, 63};
  real_T(*r)[189];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[189])emlrtMxGetData(src);
  for (i = 0; i < 189; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = {3, 3};
  real_T(*r)[9];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (i = 0; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[21])
{
  static const int32_T dims[2] = {1, 21};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)sp, src, &ret[0], 21);
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[441])
{
  static const int32_T dims[2] = {21, 21};
  real_T(*r)[441];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[441])emlrtMxGetData(src);
  for (i = 0; i < 441; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[63])
{
  static const int32_T dims[2] = {3, 21};
  real_T(*r)[63];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[63])emlrtMxGetData(src);
  for (i = 0; i < 63; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[1323])
{
  static const int32_T dims[3] = {3, 21, 21};
  real_T(*r)[1323];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 3U,
                          (const void *)&dims[0]);
  r = (real_T(*)[1323])emlrtMxGetData(src);
  for (i = 0; i < 1323; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims = 3;
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[21])
{
  static const int32_T dims = 21;
  real_T(*r)[21];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[21])emlrtMxGetData(src);
  for (i = 0; i < 21; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

void calc_acc_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  struct0_T LP;
  struct1_T SV;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "LP", &LP);
  k_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "SV", &SV);
  /* Invoke the target function */
  calc_acc(&st, &LP, &SV);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&SV);
}

/* End of code generation (_coder_calc_acc_api.c) */
