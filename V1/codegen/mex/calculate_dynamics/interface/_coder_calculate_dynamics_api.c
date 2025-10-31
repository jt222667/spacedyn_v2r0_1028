/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calculate_dynamics_api.c
 *
 * Code generation for function '_coder_calculate_dynamics_api'
 *
 */

/* Include files */
#include "_coder_calculate_dynamics_api.h"
#include "calculate_dynamics.h"
#include "calculate_dynamics_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[21];

static const mxArray *b_emlrt_marshallOut(const real_T u[21]);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[21];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *q,
                                 const char_T *identifier))[21];

static const mxArray *emlrt_marshallOut(const real_T u[441]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[21]
{
  real_T(*y)[21];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const real_T u[21])
{
  static const int32_T i = 0;
  static const int32_T i1 = 21;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[21]
{
  static const int32_T dims = 21;
  real_T(*ret)[21];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  ret = (real_T(*)[21])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *q,
                                 const char_T *identifier))[21]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[21];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(q), &thisId);
  emlrtDestroyArray(&q);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[441])
{
  static const int32_T b_iv[2] = {0, 0};
  static const int32_T iv1[2] = {21, 21};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void calculate_dynamics_api(const mxArray *const prhs[2], int32_T nlhs,
                            const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*M)[441];
  real_T(*C)[21];
  real_T(*F)[21];
  real_T(*G)[21];
  real_T(*dq)[21];
  real_T(*q)[21];
  st.tls = emlrtRootTLSGlobal;
  M = (real_T(*)[441])mxMalloc(sizeof(real_T[441]));
  C = (real_T(*)[21])mxMalloc(sizeof(real_T[21]));
  G = (real_T(*)[21])mxMalloc(sizeof(real_T[21]));
  F = (real_T(*)[21])mxMalloc(sizeof(real_T[21]));
  /* Marshall function inputs */
  q = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "q");
  dq = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "dq");
  /* Invoke the target function */
  calculate_dynamics(&st, *q, *dq, *M, *C, *G, *F);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*M);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*C);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(*G);
  }
  if (nlhs > 3) {
    plhs[3] = b_emlrt_marshallOut(*F);
  }
}

/* End of code generation (_coder_calculate_dynamics_api.c) */
