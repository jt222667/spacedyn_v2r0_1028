/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * r_ne_initialize.c
 *
 * Code generation for function 'r_ne_initialize'
 *
 */

/* Include files */
#include "r_ne_initialize.h"
#include "_coder_r_ne_mex.h"
#include "r_ne_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void r_ne_once(void);

/* Function Definitions */
static void r_ne_once(void)
{
  mex_InitInfAndNan();
}

void r_ne_initialize(void)
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
    r_ne_once();
  }
}

/* End of code generation (r_ne_initialize.c) */
