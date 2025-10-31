/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_dynamics_terminate.c
 *
 * Code generation for function 'calculate_dynamics_terminate'
 *
 */

/* Include files */
#include "calculate_dynamics_terminate.h"
#include "_coder_calculate_dynamics_mex.h"
#include "calculate_dynamics_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calculate_dynamics_atexit(void)
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

void calculate_dynamics_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calculate_dynamics_terminate.c) */
