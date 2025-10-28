/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calc_vel_mex.c
 *
 * Code generation for function '_coder_calc_vel_mex'
 *
 */

/* Include files */
#include "_coder_calc_vel_mex.h"
#include "_coder_calc_vel_api.h"
#include "calc_vel_data.h"
#include "calc_vel_initialize.h"
#include "calc_vel_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calc_vel_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
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
                        8, "calc_vel");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "calc_vel");
  }
  /* Call the function. */
  calc_vel_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&calc_vel_atexit);
  /* Module initialization. */
  calc_vel_initialize();
  /* Dispatch the entry-point. */
  calc_vel_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  calc_vel_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "GBK", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_calc_vel_mex.c) */
