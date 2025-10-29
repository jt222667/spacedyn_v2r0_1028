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
#include "calc_aa_data.h"
#include "calc_aa_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = {
    27,        /* lineNo */
    9,         /* colNo */
    "calc_aa", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_aa.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    61,        /* lineNo */
    38,        /* colNo */
    "calc_aa", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_aa.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,         /* iFirst */
    21,        /* iLast */
    30,        /* lineNo */
    14,        /* colNo */
    "LP.BB",   /* aName */
    "calc_aa", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_aa.m", /* pName */
    0                                /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,         /* iFirst */
    63,        /* iLast */
    61,        /* lineNo */
    38,        /* colNo */
    "SV.AA",   /* aName */
    "calc_aa", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_aa.m", /* pName */
    0                                /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    61,        /* lineNo */
    38,        /* colNo */
    "calc_aa", /* fName */
    "C:\\Users\\J\\Desktop\\SpaceDyn-2.0\\src\\matlab\\spacedyn_v2r0_"
    "1028\\V1\\spacedyn\\calc_aa.m", /* pName */
    1                                /* checkKind */
};

/* Function Definitions */
void calc_aa(const emlrtStack *sp, const struct0_T *LP, struct1_T *SV)
{
  static const int8_T iv[3] = {1, 0, 0};
  int32_T b_i;
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
  i = (int32_T)LP->num_q;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, LP->num_q, mxDOUBLE_CLASS,
                                (int32_T)LP->num_q, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    /*  检查链接连接：此关节是否是0关节 */
    if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
        ((int32_T)((uint32_T)b_i + 1U) > 21)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, 21,
                                    &emlrtBCI, (emlrtConstCTX)sp);
    }
    if (LP->BB[b_i] == 0.0) {
      real_T A_BB_i[9];
      int32_T Cy_tmp_tmp;
      /*  第(i)个链节与第0个链节相连 */
      /*  如果是旋转关节 */
      /*  Qi暂且认为是各个关节的初始状态 */
      if (LP->J_type[b_i] == 'R') {
        real_T c_Cz_tmp[9];
        real_T d_Cz_tmp[9];
        real_T Cx_tmp;
        real_T Cy_tmp;
        real_T Cz_tmp;
        real_T Cz_tmp_tmp;
        real_T b_Cy_tmp;
        real_T b_Cz_tmp;
        Cz_tmp_tmp = LP->Qi[3 * b_i + 2] + SV->q[b_i];
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
        Cz_tmp = muDoubleScalarSin(Cz_tmp_tmp);
        b_Cz_tmp = muDoubleScalarCos(Cz_tmp_tmp);
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
        Cy_tmp_tmp = 3 * b_i + 1;
        Cy_tmp = muDoubleScalarSin(LP->Qi[Cy_tmp_tmp]);
        b_Cy_tmp = muDoubleScalarCos(LP->Qi[Cy_tmp_tmp]);
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
        Cx_tmp = muDoubleScalarSin(LP->Qi[3 * b_i]);
        Cz_tmp_tmp = muDoubleScalarCos(LP->Qi[3 * b_i]);
        /* %%EOF */
        c_Cz_tmp[0] = b_Cz_tmp;
        c_Cz_tmp[3] = Cz_tmp;
        c_Cz_tmp[6] = 0.0;
        c_Cz_tmp[1] = -Cz_tmp;
        c_Cz_tmp[4] = b_Cz_tmp;
        c_Cz_tmp[7] = 0.0;
        A_BB_i[0] = b_Cy_tmp;
        A_BB_i[3] = 0.0;
        A_BB_i[6] = -Cy_tmp;
        c_Cz_tmp[2] = 0.0;
        A_BB_i[1] = 0.0;
        c_Cz_tmp[5] = 0.0;
        A_BB_i[4] = 1.0;
        c_Cz_tmp[8] = 1.0;
        A_BB_i[7] = 0.0;
        A_BB_i[2] = Cy_tmp;
        A_BB_i[5] = 0.0;
        A_BB_i[8] = b_Cy_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          b_Cy_tmp = c_Cz_tmp[i1];
          b_Cz_tmp = c_Cz_tmp[i1 + 3];
          i2 = (int32_T)c_Cz_tmp[i1 + 6];
          for (i3 = 0; i3 < 3; i3++) {
            d_Cz_tmp[i1 + 3 * i3] =
                (b_Cy_tmp * A_BB_i[3 * i3] + b_Cz_tmp * A_BB_i[3 * i3 + 1]) +
                (real_T)i2 * A_BB_i[3 * i3 + 2];
          }
        }
        c_Cz_tmp[1] = 0.0;
        c_Cz_tmp[4] = Cz_tmp_tmp;
        c_Cz_tmp[7] = Cx_tmp;
        c_Cz_tmp[2] = 0.0;
        c_Cz_tmp[5] = -Cx_tmp;
        c_Cz_tmp[8] = Cz_tmp_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          i2 = iv[i1];
          c_Cz_tmp[3 * i1] = i2;
          b_Cy_tmp = c_Cz_tmp[3 * i1 + 1];
          b_Cz_tmp = c_Cz_tmp[3 * i1 + 2];
          for (i3 = 0; i3 < 3; i3++) {
            A_BB_i[i1 + 3 * i3] =
                (d_Cz_tmp[i3] * (real_T)i2 + d_Cz_tmp[i3 + 3] * b_Cy_tmp) +
                d_Cz_tmp[i3 + 6] * b_Cz_tmp;
          }
        }
        /*  单一平移自由度的运动副 */
      } else {
        real_T c_Cz_tmp[9];
        real_T d_Cz_tmp[9];
        real_T Cx_tmp;
        real_T Cy_tmp;
        real_T Cz_tmp;
        real_T Cz_tmp_tmp;
        real_T b_Cy_tmp;
        real_T b_Cz_tmp;
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
        Cy_tmp_tmp = 3 * b_i + 2;
        Cz_tmp = muDoubleScalarSin(LP->Qi[Cy_tmp_tmp]);
        b_Cz_tmp = muDoubleScalarCos(LP->Qi[Cy_tmp_tmp]);
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
        Cy_tmp_tmp = 3 * b_i + 1;
        Cy_tmp = muDoubleScalarSin(LP->Qi[Cy_tmp_tmp]);
        b_Cy_tmp = muDoubleScalarCos(LP->Qi[Cy_tmp_tmp]);
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
        Cx_tmp = muDoubleScalarSin(LP->Qi[3 * b_i]);
        Cz_tmp_tmp = muDoubleScalarCos(LP->Qi[3 * b_i]);
        /* %%EOF */
        c_Cz_tmp[0] = b_Cz_tmp;
        c_Cz_tmp[3] = Cz_tmp;
        c_Cz_tmp[6] = 0.0;
        c_Cz_tmp[1] = -Cz_tmp;
        c_Cz_tmp[4] = b_Cz_tmp;
        c_Cz_tmp[7] = 0.0;
        A_BB_i[0] = b_Cy_tmp;
        A_BB_i[3] = 0.0;
        A_BB_i[6] = -Cy_tmp;
        c_Cz_tmp[2] = 0.0;
        A_BB_i[1] = 0.0;
        c_Cz_tmp[5] = 0.0;
        A_BB_i[4] = 1.0;
        c_Cz_tmp[8] = 1.0;
        A_BB_i[7] = 0.0;
        A_BB_i[2] = Cy_tmp;
        A_BB_i[5] = 0.0;
        A_BB_i[8] = b_Cy_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          b_Cy_tmp = c_Cz_tmp[i1];
          b_Cz_tmp = c_Cz_tmp[i1 + 3];
          i2 = (int32_T)c_Cz_tmp[i1 + 6];
          for (i3 = 0; i3 < 3; i3++) {
            d_Cz_tmp[i1 + 3 * i3] =
                (b_Cy_tmp * A_BB_i[3 * i3] + b_Cz_tmp * A_BB_i[3 * i3 + 1]) +
                (real_T)i2 * A_BB_i[3 * i3 + 2];
          }
        }
        c_Cz_tmp[1] = 0.0;
        c_Cz_tmp[4] = Cz_tmp_tmp;
        c_Cz_tmp[7] = Cx_tmp;
        c_Cz_tmp[2] = 0.0;
        c_Cz_tmp[5] = -Cx_tmp;
        c_Cz_tmp[8] = Cz_tmp_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          i2 = iv[i1];
          c_Cz_tmp[3 * i1] = i2;
          b_Cy_tmp = c_Cz_tmp[3 * i1 + 1];
          b_Cz_tmp = c_Cz_tmp[3 * i1 + 2];
          for (i3 = 0; i3 < 3; i3++) {
            A_BB_i[i1 + 3 * i3] =
                (d_Cz_tmp[i3] * (real_T)i2 + d_Cz_tmp[i3 + 3] * b_Cy_tmp) +
                d_Cz_tmp[i3 + 6] * b_Cz_tmp;
          }
        }
      }
      /*  SV.AA的第i*3-2到i*3列 */
      Cy_tmp_tmp = (b_i + 1) * 3 - 3;
      for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < 3; i2++) {
          i3 = i1 + 3 * (i2 + Cy_tmp_tmp);
          SV->AA[i3] = 0.0;
          SV->AA[i3] += SV->A0[i1] * A_BB_i[3 * i2];
          SV->AA[i3] += SV->A0[i1 + 3] * A_BB_i[3 * i2 + 1];
          SV->AA[i3] += SV->A0[i1 + 6] * A_BB_i[3 * i2 + 2];
        }
      }
      /*  此关节是不是0关节 */
    } else {
      real_T A_BB_i[9];
      real_T c_Cz_tmp[9];
      real_T Cz_tmp_tmp;
      real_T b_Cy_tmp;
      real_T b_Cz_tmp;
      int32_T Cy_tmp_tmp;
      /*  Current (i-th) link doesn't connect to the 0-th link */
      /*  Rotational joint */
      if (LP->J_type[b_i] == 'R') {
        real_T d_Cz_tmp[9];
        real_T Cx_tmp;
        real_T Cy_tmp;
        real_T Cz_tmp;
        Cz_tmp_tmp = LP->Qi[3 * b_i + 2] + SV->q[b_i];
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
        Cz_tmp = muDoubleScalarSin(Cz_tmp_tmp);
        b_Cz_tmp = muDoubleScalarCos(Cz_tmp_tmp);
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
        Cy_tmp_tmp = 3 * b_i + 1;
        Cy_tmp = muDoubleScalarSin(LP->Qi[Cy_tmp_tmp]);
        b_Cy_tmp = muDoubleScalarCos(LP->Qi[Cy_tmp_tmp]);
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
        Cz_tmp_tmp = LP->Qi[3 * b_i];
        Cx_tmp = muDoubleScalarSin(Cz_tmp_tmp);
        Cz_tmp_tmp = muDoubleScalarCos(Cz_tmp_tmp);
        /* %%EOF */
        c_Cz_tmp[0] = b_Cz_tmp;
        c_Cz_tmp[3] = Cz_tmp;
        c_Cz_tmp[6] = 0.0;
        c_Cz_tmp[1] = -Cz_tmp;
        c_Cz_tmp[4] = b_Cz_tmp;
        c_Cz_tmp[7] = 0.0;
        A_BB_i[0] = b_Cy_tmp;
        A_BB_i[3] = 0.0;
        A_BB_i[6] = -Cy_tmp;
        c_Cz_tmp[2] = 0.0;
        A_BB_i[1] = 0.0;
        c_Cz_tmp[5] = 0.0;
        A_BB_i[4] = 1.0;
        c_Cz_tmp[8] = 1.0;
        A_BB_i[7] = 0.0;
        A_BB_i[2] = Cy_tmp;
        A_BB_i[5] = 0.0;
        A_BB_i[8] = b_Cy_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          b_Cy_tmp = c_Cz_tmp[i1];
          b_Cz_tmp = c_Cz_tmp[i1 + 3];
          i2 = (int32_T)c_Cz_tmp[i1 + 6];
          for (i3 = 0; i3 < 3; i3++) {
            d_Cz_tmp[i1 + 3 * i3] =
                (b_Cy_tmp * A_BB_i[3 * i3] + b_Cz_tmp * A_BB_i[3 * i3 + 1]) +
                (real_T)i2 * A_BB_i[3 * i3 + 2];
          }
        }
        c_Cz_tmp[1] = 0.0;
        c_Cz_tmp[4] = Cz_tmp_tmp;
        c_Cz_tmp[7] = Cx_tmp;
        c_Cz_tmp[2] = 0.0;
        c_Cz_tmp[5] = -Cx_tmp;
        c_Cz_tmp[8] = Cz_tmp_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          i2 = iv[i1];
          c_Cz_tmp[3 * i1] = i2;
          b_Cy_tmp = c_Cz_tmp[3 * i1 + 1];
          b_Cz_tmp = c_Cz_tmp[3 * i1 + 2];
          for (i3 = 0; i3 < 3; i3++) {
            A_BB_i[i1 + 3 * i3] =
                (d_Cz_tmp[i3] * (real_T)i2 + d_Cz_tmp[i3 + 3] * b_Cy_tmp) +
                d_Cz_tmp[i3 + 6] * b_Cz_tmp;
          }
        }
        /*  Prismatic joint */
      } else {
        real_T d_Cz_tmp[9];
        real_T Cx_tmp;
        real_T Cy_tmp;
        real_T Cz_tmp;
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
        Cz_tmp_tmp = LP->Qi[3 * b_i + 2];
        Cz_tmp = muDoubleScalarSin(Cz_tmp_tmp);
        b_Cz_tmp = muDoubleScalarCos(Cz_tmp_tmp);
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
        Cz_tmp_tmp = LP->Qi[3 * b_i + 1];
        Cy_tmp = muDoubleScalarSin(Cz_tmp_tmp);
        b_Cy_tmp = muDoubleScalarCos(Cz_tmp_tmp);
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
        Cz_tmp_tmp = LP->Qi[3 * b_i];
        Cx_tmp = muDoubleScalarSin(Cz_tmp_tmp);
        Cz_tmp_tmp = muDoubleScalarCos(Cz_tmp_tmp);
        /* %%EOF */
        c_Cz_tmp[0] = b_Cz_tmp;
        c_Cz_tmp[3] = Cz_tmp;
        c_Cz_tmp[6] = 0.0;
        c_Cz_tmp[1] = -Cz_tmp;
        c_Cz_tmp[4] = b_Cz_tmp;
        c_Cz_tmp[7] = 0.0;
        A_BB_i[0] = b_Cy_tmp;
        A_BB_i[3] = 0.0;
        A_BB_i[6] = -Cy_tmp;
        c_Cz_tmp[2] = 0.0;
        A_BB_i[1] = 0.0;
        c_Cz_tmp[5] = 0.0;
        A_BB_i[4] = 1.0;
        c_Cz_tmp[8] = 1.0;
        A_BB_i[7] = 0.0;
        A_BB_i[2] = Cy_tmp;
        A_BB_i[5] = 0.0;
        A_BB_i[8] = b_Cy_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          b_Cy_tmp = c_Cz_tmp[i1];
          b_Cz_tmp = c_Cz_tmp[i1 + 3];
          i2 = (int32_T)c_Cz_tmp[i1 + 6];
          for (i3 = 0; i3 < 3; i3++) {
            d_Cz_tmp[i1 + 3 * i3] =
                (b_Cy_tmp * A_BB_i[3 * i3] + b_Cz_tmp * A_BB_i[3 * i3 + 1]) +
                (real_T)i2 * A_BB_i[3 * i3 + 2];
          }
        }
        c_Cz_tmp[1] = 0.0;
        c_Cz_tmp[4] = Cz_tmp_tmp;
        c_Cz_tmp[7] = Cx_tmp;
        c_Cz_tmp[2] = 0.0;
        c_Cz_tmp[5] = -Cx_tmp;
        c_Cz_tmp[8] = Cz_tmp_tmp;
        for (i1 = 0; i1 < 3; i1++) {
          i2 = iv[i1];
          c_Cz_tmp[3 * i1] = i2;
          b_Cy_tmp = c_Cz_tmp[3 * i1 + 1];
          b_Cz_tmp = c_Cz_tmp[3 * i1 + 2];
          for (i3 = 0; i3 < 3; i3++) {
            A_BB_i[i1 + 3 * i3] =
                (d_Cz_tmp[i3] * (real_T)i2 + d_Cz_tmp[i3 + 3] * b_Cy_tmp) +
                d_Cz_tmp[i3 + 6] * b_Cz_tmp;
          }
        }
      }
      /*  在 SpaceDyn 的数据结构里，每个编号的连杆只有一个唯一实例 */
      b_Cy_tmp = LP->BB[b_i];
      b_Cz_tmp = b_Cy_tmp * 3.0;
      if (!(b_Cz_tmp == b_Cy_tmp * 3.0)) {
        emlrtErrorWithMessageIdR2018a(
            sp, &b_emlrtRTEI,
            "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
            "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing", 0);
      }
      for (i1 = 0; i1 < 3; i1++) {
        b_Cy_tmp = b_Cz_tmp + ((real_T)i1 - 2.0);
        Cz_tmp_tmp = (int32_T)muDoubleScalarFloor(b_Cy_tmp);
        if (b_Cy_tmp != Cz_tmp_tmp) {
          emlrtIntegerCheckR2012b(b_Cy_tmp, &emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)b_Cy_tmp < 1) || ((int32_T)b_Cy_tmp > 63)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_Cy_tmp, 1, 63, &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Cy_tmp_tmp = 3 * ((int32_T)b_Cy_tmp - 1);
        c_Cz_tmp[3 * i1] = SV->AA[Cy_tmp_tmp];
        if (b_Cy_tmp != Cz_tmp_tmp) {
          emlrtIntegerCheckR2012b(b_Cy_tmp, &emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)b_Cy_tmp < 1) || ((int32_T)b_Cy_tmp > 63)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_Cy_tmp, 1, 63, &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        c_Cz_tmp[3 * i1 + 1] = SV->AA[Cy_tmp_tmp + 1];
        if (b_Cy_tmp != Cz_tmp_tmp) {
          emlrtIntegerCheckR2012b(b_Cy_tmp, &emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)b_Cy_tmp < 1) || ((int32_T)b_Cy_tmp > 63)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_Cy_tmp, 1, 63, &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        c_Cz_tmp[3 * i1 + 2] = SV->AA[Cy_tmp_tmp + 2];
      }
      Cy_tmp_tmp = (b_i + 1) * 3 - 3;
      for (i1 = 0; i1 < 3; i1++) {
        b_Cy_tmp = c_Cz_tmp[i1];
        b_Cz_tmp = c_Cz_tmp[i1 + 3];
        Cz_tmp_tmp = c_Cz_tmp[i1 + 6];
        for (i2 = 0; i2 < 3; i2++) {
          i3 = i1 + 3 * (i2 + Cy_tmp_tmp);
          SV->AA[i3] = 0.0;
          SV->AA[i3] += b_Cy_tmp * A_BB_i[3 * i2];
          SV->AA[i3] += b_Cz_tmp * A_BB_i[3 * i2 + 1];
          SV->AA[i3] += Cz_tmp_tmp * A_BB_i[3 * i2 + 2];
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
