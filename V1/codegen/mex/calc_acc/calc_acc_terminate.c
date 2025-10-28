/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_acc_terminate.c
 *
 * Code generation for function 'calc_acc_terminate'
 *
 */

/* Include files */
#include "calc_acc_terminate.h"
#include "_coder_calc_acc_mex.h"
#include "calc_acc_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calc_acc_atexit(void)
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

void calc_acc_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calc_acc_terminate.c) */
