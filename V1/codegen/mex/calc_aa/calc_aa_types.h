/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_aa_types.h
 *
 * Code generation for function 'calc_aa'
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

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T R0[3];
  real_T Q0[3];
  real_T A0[9];
  real_T AA[189];
  real_T RR[63];
  real_T v0[3];
  real_T w0[3];
  real_T vd0[3];
  real_T wd0[3];
  real_T q[21];
  real_T qd[21];
  real_T qdd[21];
  real_T vv[63];
  real_T ww[63];
  real_T vd[63];
  real_T wd[63];
  real_T F0[3];
  real_T T0[3];
  real_T Fe[63];
  real_T Te[63];
  real_T tau[21];
} struct1_T;
#endif /* typedef_struct1_T */

/* End of code generation (calc_aa_types.h) */
