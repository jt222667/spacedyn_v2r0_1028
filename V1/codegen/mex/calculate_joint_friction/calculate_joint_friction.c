/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculate_joint_friction.c
 *
 * Code generation for function 'calculate_joint_friction'
 *
 */

/* Include files */
#include "calculate_joint_friction.h"
#include "calculate_joint_friction_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void calculate_joint_friction(const emlrtStack *sp, const real_T qd[21],
                              real_T friction_forces[21])
{
  static const real_T fb[21] = {
      7.1649,  13.3287, 6.7645,  7.8656, 4.993,  5.5236, 6.3949,
      16.2233, 10.8006, 6.8534,  9.1136, 6.4825, 6.8079, 6.8188,
      14.559,  9.8068,  10.2333, 7.5364, 6.6155, 8.2332, 5.6067};
  static const real_T fc[21] = {
      0.0013,  -3.2393, 7.0109,   1.8455,  5.2311,  -2.9146, 1.9626,
      -0.3519, 13.0231, -16.2296, -9.2256, -2.4148, 6.3453,  -1.7018,
      0.5225,  -9.2769, 9.009,    8.1262,  -2.7479, -4.0121, 0.0297};
  static const real_T fv[21] = {
      27.7543, 37.342,  9.5503,  42.2625, 21.8571, 28.3255, 28.0928,
      9.1074,  7.0165,  46.6431, 9.6458,  23.9635, 30.4596, 16.3822,
      51.6363, 32.9703, 31.1092, 30.8627, 28.514,  25.6389, 20.0904};
  int32_T i;
  /*  摩擦项f参数计算 */
  /*  参数矩阵格式: [关节编号, 库伦fc, 粘滞fv, 偏置fb] */
  /*  提取各参数列 */
  /*  库伦摩擦系数 */
  /*  粘滞摩擦系数 */
  /*  偏置摩擦系数 */
  for (i = 0; i < 21; i++) {
    real_T d;
    d = qd[i];
    friction_forces[i] = (fc[i] * muDoubleScalarSign(d) + fv[i] * d) + fb[i];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (calculate_joint_friction.c) */
