/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * quintic_trajectory_terminate.c
 *
 * Code generation for function 'quintic_trajectory_terminate'
 *
 */

/* Include files */
#include "quintic_trajectory_terminate.h"
#include "_coder_quintic_trajectory_mex.h"
#include "quintic_trajectory_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void quintic_trajectory_atexit(void)
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

void quintic_trajectory_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (quintic_trajectory_terminate.c) */
