/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_dynamics_initialize.c
 *
 * Code generation for function 'calculate_dynamics_initialize'
 *
 */

/* Include files */
#include "calculate_dynamics_initialize.h"
#include "_coder_calculate_dynamics_mex.h"
#include "calculate_dynamics_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void calculate_dynamics_once(void);

/* Function Definitions */
static void calculate_dynamics_once(void)
{
  mex_InitInfAndNan();
}

void calculate_dynamics_initialize(void)
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
    calculate_dynamics_once();
  }
}

/* End of code generation (calculate_dynamics_initialize.c) */
