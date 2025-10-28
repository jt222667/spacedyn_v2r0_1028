%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	June 8, 1998, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% CALC_GJ	Calculate the Generalized Jacobian.
%
%   CALC_GJ returns the generalized jacobian, GJ (6xn).
%
% CALC_GJ    计算广义雅可比矩阵。
%
%   CALC_GJ 返回广义雅可比矩阵 GJ（6×n），描述的是 末端执行器的运动学关系
function GJ = calc_gj( LP, SV, num_e )

global Ez


% 惯性矩阵
HH = calc_hh( LP, SV );

% 找到从末端连杆到第0连杆的路径
joints = j_num( LP, num_e );

% 计算雅可比矩阵和惯性矩阵
Jm = calc_je( LP, SV, joints );

[ pe, tmp1 ] = f_kin_e( LP, SV, joints );
% Js 是一个 6×6 矩阵，把「基座的线速度+角速度」映射到「末端点的速度与角速度」
Js = [   eye(3,3) -tilde(pe-SV.R0);
       zeros(3,3)         eye(3,3) ];

Hs = HH(1:6,1:6);
Hm = HH(1:6,7:6+LP.num_q);

% Calculate the Generalized Jacobian
GJ = Jm - Js*inv(Hs)*Hm;


%%% EOF
