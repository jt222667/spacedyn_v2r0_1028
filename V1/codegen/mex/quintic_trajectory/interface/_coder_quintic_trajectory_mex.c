/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_quintic_trajectory_mex.c
 *
 * Code generation for function '_coder_quintic_trajectory_mex'
 *
 */

/* Include files */
#include "_coder_quintic_trajectory_mex.h"
#include "_coder_quintic_trajectory_api.h"
#include "quintic_trajectory_data.h"
#include "quintic_trajectory_initialize.h"
#include "quintic_trajectory_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&quintic_trajectory_atexit);
  /* Module initialization. */
  quintic_trajectory_initialize();
  /* Dispatch the entry-point. */
  quintic_trajectory_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  quintic_trajectory_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "GBK", true);
  return emlrtRootTLSGlobal;
}

void quintic_trajectory_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                    int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        18, "quintic_trajectory");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "quintic_trajectory");
  }
  /* Call the function. */
  quintic_trajectory_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_quintic_trajectory_mex.c) */
