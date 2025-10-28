/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_acc_initialize.c
 *
 * Code generation for function 'calc_acc_initialize'
 *
 */

/* Include files */
#include "calc_acc_initialize.h"
#include "_coder_calc_acc_mex.h"
#include "calc_acc_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void calc_acc_once(void);

/* Function Definitions */
static void calc_acc_once(void)
{
  mex_InitInfAndNan();
}

void calc_acc_initialize(void)
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
    calc_acc_once();
  }
}

/* End of code generation (calc_acc_initialize.c) */
