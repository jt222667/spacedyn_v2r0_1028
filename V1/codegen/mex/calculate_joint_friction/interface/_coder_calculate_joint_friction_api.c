/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calculate_joint_friction_api.c
 *
 * Code generation for function '_coder_calculate_joint_friction_api'
 *
 */

/* Include files */
#include "_coder_calculate_joint_friction_api.h"
#include "calculate_joint_friction.h"
#include "calculate_joint_friction_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[21];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[21];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *qd,
                                 const char_T *identifier))[21];

static const mxArray *emlrt_marshallOut(const real_T u[21]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[21]
{
  real_T(*y)[21];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
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

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *qd,
                                 const char_T *identifier))[21]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[21];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(qd), &thisId);
  emlrtDestroyArray(&qd);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[21])
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

void calculate_joint_friction_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*friction_forces)[21];
  real_T(*qd)[21];
  st.tls = emlrtRootTLSGlobal;
  friction_forces = (real_T(*)[21])mxMalloc(sizeof(real_T[21]));
  /* Marshall function inputs */
  qd = emlrt_marshallIn(&st, emlrtAlias(prhs), "qd");
  /* Invoke the target function */
  calculate_joint_friction(&st, *qd, *friction_forces);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*friction_forces);
}

/* End of code generation (_coder_calculate_joint_friction_api.c) */
