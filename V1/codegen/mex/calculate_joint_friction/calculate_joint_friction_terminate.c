/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_joint_friction_terminate.c
 *
 * Code generation for function 'calculate_joint_friction_terminate'
 *
 */

/* Include files */
#include "calculate_joint_friction_terminate.h"
#include "_coder_calculate_joint_friction_mex.h"
#include "calculate_joint_friction_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calculate_joint_friction_atexit(void)
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

void calculate_joint_friction_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calculate_joint_friction_terminate.c) */
