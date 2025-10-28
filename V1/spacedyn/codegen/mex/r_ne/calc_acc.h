/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_acc.h
 *
 * Code generation for function 'calc_acc'
 *
 */

#pragma once

/* Include files */
#include "r_ne_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void calc_acc(const emlrtStack *sp, real_T LP_num_q, const char_T LP_J_type[21],
              const real_T LP_BB[21], const real_T LP_cc[1386],
              const real_T LP_c0[63], struct1_T *SV);

/* End of code generation (calc_acc.h) */
