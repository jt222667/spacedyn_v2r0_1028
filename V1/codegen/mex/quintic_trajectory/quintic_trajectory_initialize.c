/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * quintic_trajectory_initialize.c
 *
 * Code generation for function 'quintic_trajectory_initialize'
 *
 */

/* Include files */
#include "quintic_trajectory_initialize.h"
#include "_coder_quintic_trajectory_mex.h"
#include "quintic_trajectory_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void quintic_trajectory_once(void);

/* Function Definitions */
static void quintic_trajectory_once(void)
{
  mex_InitInfAndNan();
}

void quintic_trajectory_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
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
    quintic_trajectory_once();
  }
}

/* End of code generation (quintic_trajectory_initialize.c) */
