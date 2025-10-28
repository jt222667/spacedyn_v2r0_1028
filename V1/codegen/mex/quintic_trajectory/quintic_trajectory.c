/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * quintic_trajectory.c
 *
 * Code generation for function 'quintic_trajectory'
 *
 */

/* Include files */
#include "quintic_trajectory.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void quintic_trajectory(const emlrtStack *sp, real_T t, real_T T, real_T q0,
                        real_T qf, real_T *pos, real_T *vel, real_T *acc)
{
  (void)sp;
  if (t <= 0.0) {
    *pos = q0;
    *vel = 0.0;
    *acc = 0.0;
  } else if (t >= T) {
    *pos = qf;
    *vel = 0.0;
    *acc = 0.0;
  } else {
    real_T a3;
    real_T a3_tmp;
    real_T a4;
    real_T a5;
    real_T b_pos_tmp;
    real_T pos_tmp;
    /*  仅在 0..T 区间使用标准五次多项式 */
    a3_tmp = qf - q0;
    a3 = 10.0 * a3_tmp / muDoubleScalarPower(T, 3.0);
    a4 = -15.0 * a3_tmp / muDoubleScalarPower(T, 4.0);
    a5 = 6.0 * a3_tmp / muDoubleScalarPower(T, 5.0);
    pos_tmp = t * t;
    b_pos_tmp = muDoubleScalarPower(t, 3.0);
    a3_tmp = muDoubleScalarPower(t, 4.0);
    *pos = ((((q0 + 0.0 * t) + 0.0 * pos_tmp) + a3 * b_pos_tmp) + a4 * a3_tmp) +
           a5 * muDoubleScalarPower(t, 5.0);
    *vel = ((0.0 * t + 3.0 * a3 * pos_tmp) + 4.0 * a4 * b_pos_tmp) +
           5.0 * a5 * a3_tmp;
    *acc = (6.0 * a3 * t + 12.0 * a4 * pos_tmp) + 20.0 * a5 * b_pos_tmp;
  }
}

/* End of code generation (quintic_trajectory.c) */
