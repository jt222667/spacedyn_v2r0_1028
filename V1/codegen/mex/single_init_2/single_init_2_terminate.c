/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * single_init_2_terminate.c
 *
 * Code generation for function 'single_init_2_terminate'
 *
 */

/* Include files */
#include "single_init_2_terminate.h"
#include "_coder_single_init_2_mex.h"
#include "rt_nonfinite.h"
#include "single_init_2_data.h"

/* Function Definitions */
void single_init_2_atexit(void)
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

void single_init_2_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (single_init_2_terminate.c) */
