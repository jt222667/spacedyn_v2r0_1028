/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_quintic_trajectory_api.c
 *
 * Code generation for function '_coder_quintic_trajectory_api'
 *
 */

/* Include files */
#include "_coder_quintic_trajectory_api.h"
#include "quintic_trajectory.h"
#include "quintic_trajectory_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(t), &thisId);
  emlrtDestroyArray(&t);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void quintic_trajectory_api(const mxArray *const prhs[4], int32_T nlhs,
                            const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T T;
  real_T acc;
  real_T pos;
  real_T q0;
  real_T qf;
  real_T t;
  real_T vel;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  T = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "T");
  q0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "q0");
  qf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "qf");
  /* Invoke the target function */
  quintic_trajectory(&st, t, T, q0, qf, &pos, &vel, &acc);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(pos);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(vel);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(acc);
  }
}

/* End of code generation (_coder_quintic_trajectory_api.c) */
