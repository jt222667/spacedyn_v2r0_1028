/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_joint_friction.h
 *
 * Code generation for function 'calculate_joint_friction'
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
void calculate_joint_friction(const emlrtStack *sp, const real_T qd[21],
                              real_T friction_forces[21]);

/* End of code generation (calculate_joint_friction.h) */
