/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_pos.c
 *
 * Code generation for function 'calc_pos'
 *
 */

/* Include files */
#include "calc_pos.h"
#include "calculate_dynamics_data.h"
#include "calculate_dynamics_internal_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void calc_pos(const emlrtStack *sp, struct_T *SV)
{
  int32_T A_I_i_tmp;
  int32_T c_i;
  int32_T i;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots. */
  /*  (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida, */
  /*  Tohoku University, Japan. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* 	February 4, 1999, Last modification by K.Yoshida */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  */
  /*  CALC_POS	Calculate the position vectors of each link */
  /*  */
  /* 		CALC_POS returns the position vectors RR in the Inertia frame.
   */
  /*  */
  /*  CALC_POS    计算每个连杆的位置向量 */
  /*  */
  /*         CALC_POS 返回惯性坐标系中的位置向量 RR。 */
  /* global BB J_type */
  /* global c0 cc */
  /* global num_q Ez */
  /*  初始化 Ez */
  /*  If a Multi body system, */
  /*  Calculation of position vectors */
  for (i = 0; i < 21; i++) {
    real_T A_I_i[9];
    int32_T b_i;
    int8_T i1;
    b_i = (i + 1) * 3 - 3;
    for (c_i = 0; c_i < 3; c_i++) {
      A_I_i_tmp = 3 * (c_i + b_i);
      A_I_i[3 * c_i] = SV->AA[A_I_i_tmp];
      A_I_i[3 * c_i + 1] = SV->AA[A_I_i_tmp + 1];
      A_I_i[3 * c_i + 2] = SV->AA[A_I_i_tmp + 2];
    }
    /*  Current (i-th) link connects to the 0-th link */
    i1 = iv[i];
    if (i1 == 0) {
      real_T b_idx_0;
      real_T b_idx_1;
      real_T b_idx_2;
      real_T d;
      /*  Rotational joint */
      b_idx_0 = dv[3 * i];
      b_idx_1 = dv[3 * i + 1];
      b_idx_2 = dv[3 * i + 2];
      d = dv1[66 * i];
      c_i = 66 * i;
      for (A_I_i_tmp = 0; A_I_i_tmp < 3; A_I_i_tmp++) {
        SV->RR[A_I_i_tmp + 3 * i] =
            (SV->R0[A_I_i_tmp] +
             ((SV->A0[A_I_i_tmp] * b_idx_0 + SV->A0[A_I_i_tmp + 3] * b_idx_1) +
              SV->A0[A_I_i_tmp + 6] * b_idx_2)) -
            ((A_I_i[A_I_i_tmp] * d + A_I_i[A_I_i_tmp + 3] * dv1[c_i + 1]) +
             A_I_i[A_I_i_tmp + 6] * dv1[c_i + 2]);
      }
      /*  Prismatic joint */
      /*  Current (i-th) link doesn't connect to the 0-th link */
    } else {
      real_T A_I_BB[9];
      real_T b_SV[3];
      real_T b_idx_0;
      real_T b_idx_1;
      real_T b_idx_2;
      c_i = i1 * 3;
      for (A_I_i_tmp = 0; A_I_i_tmp < 3; A_I_i_tmp++) {
        b_i = 3 * ((A_I_i_tmp + c_i) - 3);
        A_I_BB[3 * A_I_i_tmp] = SV->AA[b_i];
        A_I_BB[3 * A_I_i_tmp + 1] = SV->AA[b_i + 1];
        A_I_BB[3 * A_I_i_tmp + 2] = SV->AA[b_i + 2];
      }
      /*  Rotational joint */
      A_I_i_tmp = 3 * (i1 - 1);
      b_i = A_I_i_tmp + 63 * i;
      b_idx_0 = dv1[b_i];
      b_idx_1 = dv1[b_i + 1];
      b_idx_2 = dv1[b_i + 2];
      for (c_i = 0; c_i < 3; c_i++) {
        b_SV[c_i] = SV->RR[c_i + A_I_i_tmp] +
                    ((A_I_BB[c_i] * b_idx_0 + A_I_BB[c_i + 3] * b_idx_1) +
                     A_I_BB[c_i + 6] * b_idx_2);
      }
      b_idx_0 = dv1[66 * i];
      b_idx_1 = dv1[66 * i + 1];
      b_idx_2 = dv1[66 * i + 2];
      for (c_i = 0; c_i < 3; c_i++) {
        SV->RR[c_i + 3 * i] =
            b_SV[c_i] - ((A_I_i[c_i] * b_idx_0 + A_I_i[c_i + 3] * b_idx_1) +
                         A_I_i[c_i + 6] * b_idx_2);
      }
      /*  Prismatic joint */
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* %%EOF */
}

/* End of code generation (calc_pos.c) */
