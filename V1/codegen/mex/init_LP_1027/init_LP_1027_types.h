/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * init_LP_1027_types.h
 *
 * Code generation for function 'init_LP_1027'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T num_q;
  real_T m0;
  real_T m[21];
  real_T mass;
  real_T inertia[189];
  real_T inertia0[9];
  char_T J_type[21];
  real_T BB[21];
  real_T S0[21];
  real_T SE[21];
  real_T SS[441];
  real_T Qi[63];
  real_T Qe[63];
  real_T cc[1323];
  real_T c0[63];
  real_T ce[63];
} struct0_T;
#endif /* typedef_struct0_T */

/* End of code generation (init_LP_1027_types.h) */
