/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_r_ne_mex.c
 *
 * Code generation for function '_coder_r_ne_mex'
 *
 */

/* Include files */
#include "_coder_r_ne_mex.h"
#include "_coder_r_ne_api.h"
#include "r_ne_data.h"
#include "r_ne_initialize.h"
#include "r_ne_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&r_ne_atexit);
  /* Module initialization. */
  r_ne_initialize();
  /* Dispatch the entry-point. */
  r_ne_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  r_ne_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "GBK", true);
  return emlrtRootTLSGlobal;
}

void r_ne_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                      const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        4, "r_ne");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "r_ne");
  }
  /* Call the function. */
  r_ne_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_r_ne_mex.c) */
