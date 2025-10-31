/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_aa.c
 *
 * Code generation for function 'calc_aa'
 *
 */

/* Include files */
#include "calc_aa.h"
#include "calculate_dynamics_data.h"
#include "calculate_dynamics_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void calc_aa(const emlrtStack *sp, struct_T *SV)
{
  static const real_T b_dv[63] = {0.0,
                                  0.0,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  0.0,
                                  2.0943951023931953,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  0.0,
                                  4.1887902047863905,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0,
                                  1.5707963267948966,
                                  0.0,
                                  0.0,
                                  -1.5707963267948966,
                                  0.0,
                                  0.0};
  static const int8_T b_iv[3] = {1, 0, 0};
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
  /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
  /*  Tohoku University, Japan. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*    version 1 // Oct 4, 1999, Last modification by K.Yoshida */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  CALC_AA 	Calculate the coordinate transfrom matrices in the Robotics
   * convention. */
  /*  */
  /*    CALC_TRN( A0 , q ) returns the coordinate tranformation matrices AA. */
  /*    AA is a collection of A_I_1, A_I_2, ... A_I_n. */
  /*  */
  /*  CALC_AA     计算机器人学坐标系中的坐标变换矩阵。 */
  /*  */
  /*    CALC_TRN( A0 , q ) 返回坐标变换矩阵 AA。 */
  /*    AA 是由 A_I_1, A_I_2, ... A_I_n 组成的集合。 */
  /*  如果是一个多体系统 */
  /*  坐标变换矩阵的计算 */
  /*  基座的旋转矩阵 */
  for (i = 0; i < 21; i++) {
    int8_T b_i;
    /*  检查链接连接：此关节是否是0关节 */
    b_i = iv[i];
    if (b_i == 0) {
      real_T b_Cy_tmp[9];
      real_T c_Cz_tmp[9];
      real_T d_Cz_tmp[9];
      real_T Cx_tmp;
      real_T Cy_tmp;
      real_T Cz_tmp;
      real_T b_Cx_tmp;
      real_T b_Cz_tmp;
      real_T pitch;
      real_T roll;
      real_T yaw;
      int32_T a_tmp;
      /*  第(i)个链节与第0个链节相连 */
      /*  如果是旋转关节 */
      /*  Qi暂且认为是各个关节的初始状态 */
      /*  单一平移自由度的运动副 */
      /*  SV.AA的第i*3-2到i*3列 */
      roll = b_dv[3 * i];
      pitch = b_dv[3 * i + 1];
      yaw = b_dv[3 * i + 2] + SV->q[i];
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1 // Oct 4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /*  	RPY2DC	Roll/pitch/yaw angles to direction cosine matrix */
      /*  */
      /* 		RPY2DC(R,P,Y) returns a 3x3 direction cosine matrix */
      /* 		for the specified roll/pitch/yaw angles.   */
      /* 		These correspond to rotations about the X, Y, Z axes
       * respectively. */
      /*  */
      /* 		See also DC2RPY, EUL2DC. */
      /*  */
      /*      RPY2DC    将滚转/俯仰/偏航角度转换为方向余弦矩阵 */
      /*  */
      /*         RPY2DC(R,P,Y) 返回一个 3x3 方向余弦矩阵 */
      /*         对应指定的横滚/俯仰/偏航角度。   */
      /*         这些角度分别对应围绕 X、Y、Z 轴的旋转。 */
      /*  */
      /*         另请参阅 DC2RPY、EUL2DC。 */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1.0 // Oct.4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /* CZ	A Principal Coordinate Transformation Matrix, Dirction
       * Cosines; C3 */
      /*  */
      /* 	CZ(theta) returns a 3x3 transformation representing a  */
      /* 	rotation of theta about the Z axis. */
      /*  */
      /* 	See also CX, CY. */
      Cz_tmp = muDoubleScalarSin(yaw);
      b_Cz_tmp = muDoubleScalarCos(yaw);
      /* %%EOF */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1.0 // Oct.4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /* CY	A Principal Coordinate Transformation Matrix, Dirction
       * Cosines; C2 */
      /*  */
      /* 	CY(theta) returns a 3x3 transformation representing a  */
      /* 	rotation of theta about the Y axis. */
      /*  */
      /* 	See also CX, CZ. */
      /*  */
      Cy_tmp = muDoubleScalarSin(pitch);
      yaw = muDoubleScalarCos(pitch);
      /* %%EOF */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1.0 // Oct.4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /* CX	A Principal Coordinate Transformation Matrix, Dirction
       * Cosines; C1 */
      /*  */
      /* 	CX(theta) returns a 3x3 transformation representing a  */
      /* 	rotation of theta about the X axis. */
      /*  */
      /* 	See also CY, CZ. */
      /*  */
      Cx_tmp = muDoubleScalarSin(roll);
      b_Cx_tmp = muDoubleScalarCos(roll);
      /* %%EOF */
      c_Cz_tmp[0] = b_Cz_tmp;
      c_Cz_tmp[3] = Cz_tmp;
      c_Cz_tmp[6] = 0.0;
      c_Cz_tmp[1] = -Cz_tmp;
      c_Cz_tmp[4] = b_Cz_tmp;
      c_Cz_tmp[7] = 0.0;
      b_Cy_tmp[0] = yaw;
      b_Cy_tmp[3] = 0.0;
      b_Cy_tmp[6] = -Cy_tmp;
      c_Cz_tmp[2] = 0.0;
      b_Cy_tmp[1] = 0.0;
      c_Cz_tmp[5] = 0.0;
      b_Cy_tmp[4] = 1.0;
      c_Cz_tmp[8] = 1.0;
      b_Cy_tmp[7] = 0.0;
      b_Cy_tmp[2] = Cy_tmp;
      b_Cy_tmp[5] = 0.0;
      b_Cy_tmp[8] = yaw;
      for (i1 = 0; i1 < 3; i1++) {
        pitch = c_Cz_tmp[i1];
        roll = c_Cz_tmp[i1 + 3];
        i2 = (int32_T)c_Cz_tmp[i1 + 6];
        for (i3 = 0; i3 < 3; i3++) {
          d_Cz_tmp[i1 + 3 * i3] =
              (pitch * b_Cy_tmp[3 * i3] + roll * b_Cy_tmp[3 * i3 + 1]) +
              (real_T)i2 * b_Cy_tmp[3 * i3 + 2];
        }
      }
      b_Cy_tmp[1] = 0.0;
      b_Cy_tmp[4] = b_Cx_tmp;
      b_Cy_tmp[7] = Cx_tmp;
      b_Cy_tmp[2] = 0.0;
      b_Cy_tmp[5] = -Cx_tmp;
      b_Cy_tmp[8] = b_Cx_tmp;
      for (i1 = 0; i1 < 3; i1++) {
        i2 = b_iv[i1];
        b_Cy_tmp[3 * i1] = i2;
        pitch = b_Cy_tmp[3 * i1 + 1];
        roll = b_Cy_tmp[3 * i1 + 2];
        for (i3 = 0; i3 < 3; i3++) {
          c_Cz_tmp[i1 + 3 * i3] =
              (d_Cz_tmp[i3] * (real_T)i2 + d_Cz_tmp[i3 + 3] * pitch) +
              d_Cz_tmp[i3 + 6] * roll;
        }
      }
      a_tmp = (i + 1) * 3 - 3;
      for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < 3; i2++) {
          i3 = i1 + 3 * (i2 + a_tmp);
          SV->AA[i3] = 0.0;
          SV->AA[i3] += SV->A0[i1] * c_Cz_tmp[3 * i2];
          SV->AA[i3] += SV->A0[i1 + 3] * c_Cz_tmp[3 * i2 + 1];
          SV->AA[i3] += SV->A0[i1 + 6] * c_Cz_tmp[3 * i2 + 2];
        }
      }
      /*  此关节是不是0关节 */
    } else {
      real_T a[9];
      real_T b_Cy_tmp[9];
      real_T c_Cz_tmp[9];
      real_T d_Cz_tmp[9];
      real_T Cx_tmp;
      real_T b_Cx_tmp;
      real_T pitch;
      real_T roll;
      real_T yaw;
      int32_T a_tmp;
      /*  Current (i-th) link doesn't connect to the 0-th link */
      /*  Rotational joint */
      /*  Prismatic joint */
      /*  在 SpaceDyn 的数据结构里，每个编号的连杆只有一个唯一实例 */
      i1 = b_i * 3;
      for (i2 = 0; i2 < 3; i2++) {
        a_tmp = 3 * ((i2 + i1) - 3);
        a[3 * i2] = SV->AA[a_tmp];
        a[3 * i2 + 1] = SV->AA[a_tmp + 1];
        a[3 * i2 + 2] = SV->AA[a_tmp + 2];
      }
      real_T Cy_tmp;
      real_T Cz_tmp;
      real_T b_Cz_tmp;
      roll = b_dv[3 * i];
      pitch = b_dv[3 * i + 1];
      yaw = b_dv[3 * i + 2] + SV->q[i];
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1 // Oct 4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /*  	RPY2DC	Roll/pitch/yaw angles to direction cosine matrix */
      /*  */
      /* 		RPY2DC(R,P,Y) returns a 3x3 direction cosine matrix */
      /* 		for the specified roll/pitch/yaw angles.   */
      /* 		These correspond to rotations about the X, Y, Z axes
       * respectively. */
      /*  */
      /* 		See also DC2RPY, EUL2DC. */
      /*  */
      /*      RPY2DC    将滚转/俯仰/偏航角度转换为方向余弦矩阵 */
      /*  */
      /*         RPY2DC(R,P,Y) 返回一个 3x3 方向余弦矩阵 */
      /*         对应指定的横滚/俯仰/偏航角度。   */
      /*         这些角度分别对应围绕 X、Y、Z 轴的旋转。 */
      /*  */
      /*         另请参阅 DC2RPY、EUL2DC。 */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1.0 // Oct.4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /* CZ	A Principal Coordinate Transformation Matrix, Dirction
       * Cosines; C3 */
      /*  */
      /* 	CZ(theta) returns a 3x3 transformation representing a  */
      /* 	rotation of theta about the Z axis. */
      /*  */
      /* 	See also CX, CY. */
      Cz_tmp = muDoubleScalarSin(yaw);
      b_Cz_tmp = muDoubleScalarCos(yaw);
      /* %%EOF */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1.0 // Oct.4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /* CY	A Principal Coordinate Transformation Matrix, Dirction
       * Cosines; C2 */
      /*  */
      /* 	CY(theta) returns a 3x3 transformation representing a  */
      /* 	rotation of theta about the Y axis. */
      /*  */
      /* 	See also CX, CZ. */
      /*  */
      Cy_tmp = muDoubleScalarSin(pitch);
      yaw = muDoubleScalarCos(pitch);
      /* %%EOF */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
      /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
      /*  Tohoku University, Japan. */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*     version 1.0 // Oct.4, 1999, Last modification by K.Yoshida */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*  */
      /* CX	A Principal Coordinate Transformation Matrix, Dirction
       * Cosines; C1 */
      /*  */
      /* 	CX(theta) returns a 3x3 transformation representing a  */
      /* 	rotation of theta about the X axis. */
      /*  */
      /* 	See also CY, CZ. */
      /*  */
      Cx_tmp = muDoubleScalarSin(roll);
      b_Cx_tmp = muDoubleScalarCos(roll);
      /* %%EOF */
      c_Cz_tmp[0] = b_Cz_tmp;
      c_Cz_tmp[3] = Cz_tmp;
      c_Cz_tmp[6] = 0.0;
      c_Cz_tmp[1] = -Cz_tmp;
      c_Cz_tmp[4] = b_Cz_tmp;
      c_Cz_tmp[7] = 0.0;
      b_Cy_tmp[0] = yaw;
      b_Cy_tmp[3] = 0.0;
      b_Cy_tmp[6] = -Cy_tmp;
      c_Cz_tmp[2] = 0.0;
      b_Cy_tmp[1] = 0.0;
      c_Cz_tmp[5] = 0.0;
      b_Cy_tmp[4] = 1.0;
      c_Cz_tmp[8] = 1.0;
      b_Cy_tmp[7] = 0.0;
      b_Cy_tmp[2] = Cy_tmp;
      b_Cy_tmp[5] = 0.0;
      b_Cy_tmp[8] = yaw;
      for (i1 = 0; i1 < 3; i1++) {
        pitch = c_Cz_tmp[i1];
        roll = c_Cz_tmp[i1 + 3];
        i2 = (int32_T)c_Cz_tmp[i1 + 6];
        for (i3 = 0; i3 < 3; i3++) {
          d_Cz_tmp[i1 + 3 * i3] =
              (pitch * b_Cy_tmp[3 * i3] + roll * b_Cy_tmp[3 * i3 + 1]) +
              (real_T)i2 * b_Cy_tmp[3 * i3 + 2];
        }
      }
      b_Cy_tmp[1] = 0.0;
      b_Cy_tmp[4] = b_Cx_tmp;
      b_Cy_tmp[7] = Cx_tmp;
      b_Cy_tmp[2] = 0.0;
      b_Cy_tmp[5] = -Cx_tmp;
      b_Cy_tmp[8] = b_Cx_tmp;
      for (i1 = 0; i1 < 3; i1++) {
        i2 = b_iv[i1];
        b_Cy_tmp[3 * i1] = i2;
        pitch = b_Cy_tmp[3 * i1 + 1];
        roll = b_Cy_tmp[3 * i1 + 2];
        for (i3 = 0; i3 < 3; i3++) {
          c_Cz_tmp[i1 + 3 * i3] =
              (d_Cz_tmp[i3] * (real_T)i2 + d_Cz_tmp[i3 + 3] * pitch) +
              d_Cz_tmp[i3 + 6] * roll;
        }
      }
      a_tmp = (i + 1) * 3 - 3;
      for (i1 = 0; i1 < 3; i1++) {
        pitch = a[i1];
        roll = a[i1 + 3];
        yaw = a[i1 + 6];
        for (i2 = 0; i2 < 3; i2++) {
          SV->AA[i1 + 3 * (i2 + a_tmp)] =
              (pitch * c_Cz_tmp[3 * i2] + roll * c_Cz_tmp[3 * i2 + 1]) +
              yaw * c_Cz_tmp[3 * i2 + 2];
        }
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* %%EOF */
}

/* End of code generation (calc_aa.c) */
