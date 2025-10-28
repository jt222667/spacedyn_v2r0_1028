/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_vel_terminate.c
 *
 * Code generation for function 'calc_vel_terminate'
 *
 */

/* Include files */
#include "calc_vel_terminate.h"
#include "_coder_calc_vel_mex.h"
#include "calc_vel_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calc_vel_atexit(void)
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

void calc_vel_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calc_vel_terminate.c) */
