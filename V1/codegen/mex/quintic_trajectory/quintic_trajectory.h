/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * quintic_trajectory.h
 *
 * Code generation for function 'quintic_trajectory'
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
void quintic_trajectory(const emlrtStack *sp, real_T t, real_T T, real_T q0,
                        real_T qf, real_T *pos, real_T *vel, real_T *acc);

/* End of code generation (quintic_trajectory.h) */
