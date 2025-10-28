/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_joint_friction_initialize.c
 *
 * Code generation for function 'calculate_joint_friction_initialize'
 *
 */

/* Include files */
#include "calculate_joint_friction_initialize.h"
#include "_coder_calculate_joint_friction_mex.h"
#include "calculate_joint_friction_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void calculate_joint_friction_once(void);

/* Function Definitions */
static void calculate_joint_friction_once(void)
{
  mex_InitInfAndNan();
}

void calculate_joint_friction_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    calculate_joint_friction_once();
  }
}

/* End of code generation (calculate_joint_friction_initialize.c) */
