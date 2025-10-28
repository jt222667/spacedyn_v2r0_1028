/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calculate_joint_friction_mex.c
 *
 * Code generation for function '_coder_calculate_joint_friction_mex'
 *
 */

/* Include files */
#include "_coder_calculate_joint_friction_mex.h"
#include "_coder_calculate_joint_friction_api.h"
#include "calculate_joint_friction_data.h"
#include "calculate_joint_friction_initialize.h"
#include "calculate_joint_friction_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calculate_joint_friction_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        24, "calculate_joint_friction");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "calculate_joint_friction");
  }
  /* Call the function. */
  calculate_joint_friction_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&calculate_joint_friction_atexit);
  /* Module initialization. */
  calculate_joint_friction_initialize();
  /* Dispatch the entry-point. */
  calculate_joint_friction_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  calculate_joint_friction_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "GBK", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_calculate_joint_friction_mex.c) */
