/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_pos_terminate.c
 *
 * Code generation for function 'calc_pos_terminate'
 *
 */

/* Include files */
#include "calc_pos_terminate.h"
#include "_coder_calc_pos_mex.h"
#include "calc_pos_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calc_pos_atexit(void)
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

void calc_pos_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calc_pos_terminate.c) */
