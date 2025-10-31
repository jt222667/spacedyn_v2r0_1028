/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * r_ne.h
 *
 * Code generation for function 'r_ne'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void r_ne(const emlrtStack *sp, const real_T SV_A0[9], const real_T SV_AA[189],
          const real_T SV_w0[3], const real_T SV_vd0[3], const real_T SV_wd0[3],
          const real_T SV_q[21], const real_T SV_qd[21],
          const real_T SV_qdd[21], real_T SV_ww[63], real_T SV_vd[63],
          real_T SV_wd[63], const real_T SV_Fe[63], const real_T SV_Te[63],
          real_T Force[27]);

/* End of code generation (r_ne.h) */
