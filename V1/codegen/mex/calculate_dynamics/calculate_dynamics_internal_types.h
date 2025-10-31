/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_dynamics_internal_types.h
 *
 * Code generation for function 'calculate_dynamics'
 *
 */

#pragma once

/* Include files */
#include "calculate_dynamics_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
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
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtDoubleCheckInfo
#define typedef_rtDoubleCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
  int32_T checkKind;
} rtDoubleCheckInfo;
#endif /* typedef_rtDoubleCheckInfo */

#ifndef typedef_rtEqualityCheckInfo
#define typedef_rtEqualityCheckInfo
typedef struct {
  int32_T nDims;
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtEqualityCheckInfo;
#endif /* typedef_rtEqualityCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (calculate_dynamics_internal_types.h) */
