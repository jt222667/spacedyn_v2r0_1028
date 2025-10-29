/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_init_LP_1029_mex.c
 *
 * Code generation for function '_coder_init_LP_1029_mex'
 *
 */

/* Include files */
#include "_coder_init_LP_1029_mex.h"
#include "_coder_init_LP_1029_api.h"
#include "init_LP_1029_data.h"
#include "init_LP_1029_initialize.h"
#include "init_LP_1029_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void init_LP_1029_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs)
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
                        12, "init_LP_1029");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "init_LP_1029");
  }
  /* Call the function. */
  init_LP_1029_api(&outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)prhs;
  mexAtExit(&init_LP_1029_atexit);
  /* Module initialization. */
  init_LP_1029_initialize();
  /* Dispatch the entry-point. */
  init_LP_1029_mexFunction(nlhs, plhs, nrhs);
  /* Module termination. */
  init_LP_1029_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "GBK", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_init_LP_1029_mex.c) */
