/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * init_SV_1027.c
 *
 * Code generation for function 'init_SV_1027'
 *
 */

/* Include files */
#include "init_SV_1027.h"
#include "init_SV_1027_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void init_SV_1027(struct0_T *SV)
{
  /*  基座相对于惯性系I位移 */
  SV->R0[0] = 0.0;
  SV->Q0[0] = 0.0;
  SV->R0[1] = 0.0;
  SV->Q0[1] = 0.0;
  SV->R0[2] = 0.0;
  SV->Q0[2] = 0.0;
  /*  基座相对于惯性系I姿态 */
  memset(&SV->A0[0], 0, 9U * sizeof(real_T));
  SV->A0[0] = 1.0;
  SV->A0[4] = 1.0;
  SV->A0[8] = 1.0;
  /*  基座相对于惯性系I旋转矩阵 */
  memset(&SV->AA[0], 0, 189U * sizeof(real_T));
  /*  关节相对于惯性系I旋转矩阵 */
  memset(&SV->RR[0], 0, 63U * sizeof(real_T));
  /*  关节相对于惯性系I位移 */
  /*  基座质心线速度 */
  /*  基座质心角速度 */
  /*  基座质心线加速度 */
  SV->v0[0] = 0.0;
  SV->w0[0] = 0.0;
  SV->vd0[0] = 0.0;
  SV->wd0[0] = 0.0;
  SV->v0[1] = 0.0;
  SV->w0[1] = 0.0;
  SV->vd0[1] = 0.0;
  SV->wd0[1] = 0.0;
  SV->v0[2] = 0.0;
  SV->w0[2] = 0.0;
  SV->vd0[2] = 0.0;
  SV->wd0[2] = 0.0;
  /*  基座质心角加速度 */
  /*  关节角度 */
  /*  关节角速度 */
  memset(&SV->q[0], 0, 21U * sizeof(real_T));
  memset(&SV->qd[0], 0, 21U * sizeof(real_T));
  memset(&SV->qdd[0], 0, 21U * sizeof(real_T));
  /*  关节角加速度 */
  /*  连杆质心线速度 */
  /*  连杆质心线加速度 */
  /*  连杆质心角速度 */
  /*  连杆质心角加速度 */
  /*  作用在基座质心的力 */
  SV->F0[0] = 0.0;
  SV->T0[0] = 0.0;
  SV->F0[1] = 0.0;
  SV->T0[1] = 0.0;
  SV->F0[2] = 0.0;
  SV->T0[2] = 0.0;
  /*  作用在基座质心的力矩 */
  /*  作用在末端点的力 */
  memset(&SV->vv[0], 0, 63U * sizeof(real_T));
  memset(&SV->ww[0], 0, 63U * sizeof(real_T));
  memset(&SV->vd[0], 0, 63U * sizeof(real_T));
  memset(&SV->wd[0], 0, 63U * sizeof(real_T));
  memset(&SV->Fe[0], 0, 63U * sizeof(real_T));
  memset(&SV->Te[0], 0, 63U * sizeof(real_T));
  /*  作用在末端点的力矩 */
  memset(&SV->tau[0], 0, 21U * sizeof(real_T));
  /*  关节力矩 */
}

/* End of code generation (init_SV_1027.c) */
