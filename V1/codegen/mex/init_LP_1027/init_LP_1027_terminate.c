/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * init_LP_1027_terminate.c
 *
 * Code generation for function 'init_LP_1027_terminate'
 *
 */

/* Include files */
#include "init_LP_1027_terminate.h"
#include "_coder_init_LP_1027_mex.h"
#include "init_LP_1027_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void init_LP_1027_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void init_LP_1027_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (init_LP_1027_terminate.c) */
