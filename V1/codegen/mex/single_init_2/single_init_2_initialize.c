/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * single_init_2_initialize.c
 *
 * Code generation for function 'single_init_2_initialize'
 *
 */

/* Include files */
#include "single_init_2_initialize.h"
#include "_coder_single_init_2_mex.h"
#include "rt_nonfinite.h"
#include "single_init_2_data.h"

/* Function Declarations */
static void single_init_2_once(void);

/* Function Definitions */
static void single_init_2_once(void)
{
  mex_InitInfAndNan();
}

void single_init_2_initialize(void)
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
    single_init_2_once();
  }
}

/* End of code generation (single_init_2_initialize.c) */
