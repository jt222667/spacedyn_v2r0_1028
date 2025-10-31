/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_dynamics.h
 *
 * Code generation for function 'calculate_dynamics'
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
void calculate_dynamics(const emlrtStack *sp, const real_T q[21],
                        const real_T dq[21], real_T M[441], real_T C[21],
                        real_T G[21], real_T F[21]);

/* End of code generation (calculate_dynamics.h) */
