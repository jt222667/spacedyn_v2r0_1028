/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calculate_dynamics_mex.c
 *
 * Code generation for function '_coder_calculate_dynamics_mex'
 *
 */

/* Include files */
#include "_coder_calculate_dynamics_mex.h"
#include "_coder_calculate_dynamics_api.h"
#include "calculate_dynamics_data.h"
#include "calculate_dynamics_initialize.h"
#include "calculate_dynamics_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calculate_dynamics_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                    int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[4];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        18, "calculate_dynamics");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "calculate_dynamics");
  }
  /* Call the function. */
  calculate_dynamics_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&calculate_dynamics_atexit);
  /* Module initialization. */
  calculate_dynamics_initialize();
  /* Dispatch the entry-point. */
  calculate_dynamics_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  calculate_dynamics_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "GBK", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_calculate_dynamics_mex.c) */
