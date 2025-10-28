/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_aa_terminate.c
 *
 * Code generation for function 'calc_aa_terminate'
 *
 */

/* Include files */
#include "calc_aa_terminate.h"
#include "_coder_calc_aa_mex.h"
#include "calc_aa_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calc_aa_atexit(void)
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

void calc_aa_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calc_aa_terminate.c) */
