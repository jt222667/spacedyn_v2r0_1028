/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_single_init_2_mex.c
 *
 * Code generation for function '_coder_single_init_2_mex'
 *
 */

/* Include files */
#include "_coder_single_init_2_mex.h"
#include "_coder_single_init_2_api.h"
#include "rt_nonfinite.h"
#include "single_init_2_data.h"
#include "single_init_2_initialize.h"
#include "single_init_2_terminate.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)prhs;
  mexAtExit(&single_init_2_atexit);
  /* Module initialization. */
  single_init_2_initialize();
  /* Dispatch the entry-point. */
  single_init_2_mexFunction(nlhs, plhs, nrhs);
  /* Module termination. */
  single_init_2_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "GBK", true);
  return emlrtRootTLSGlobal;
}

void single_init_2_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        13, "single_init_2");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "single_init_2");
  }
  /* Call the function. */
  single_init_2_api(&outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_single_init_2_mex.c) */
