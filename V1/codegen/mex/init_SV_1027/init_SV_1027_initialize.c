/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * init_SV_1027_initialize.c
 *
 * Code generation for function 'init_SV_1027_initialize'
 *
 */

/* Include files */
#include "init_SV_1027_initialize.h"
#include "_coder_init_SV_1027_mex.h"
#include "init_SV_1027_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void init_SV_1027_once(void);

/* Function Definitions */
static void init_SV_1027_once(void)
{
  mex_InitInfAndNan();
}

void init_SV_1027_initialize(void)
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
    init_SV_1027_once();
  }
}

/* End of code generation (init_SV_1027_initialize.c) */
