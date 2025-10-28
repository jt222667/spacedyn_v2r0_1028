%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	February 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% forward kinematics for end-effector
% F_KIN_E	Foward Kinematics
%		Caluculate the Position/Orientation of the point
%		specified by connection vector 'joints.'
%		POS : 3x1 vector, ORI : 3x3 matrix.
%
% F_KIN_E    正向运动学：计算末端执行器位置、方向
%        计算由连接向量'joints.'指定的点的位置/姿态
%        POS：3x1向量，ORI：3x3矩阵。

function [ POS_e , ORI_e ] = f_kin_e(LP, SV, joints)


% Check number of the corresponding joints
n = length(joints);
k = joints(n);

% Calcurate coordinate trasformation matrix of Effector
A_I_i = SV.AA(:,k*3-2:k*3);
A_i_EE = rpy2dc(LP.Qe(:,k))';
ORI_e = A_I_i*A_i_EE;

% Calculate position vector of Effector
POS_e = SV.RR(:,k) + A_I_i * LP.ce(:,k);


%%%EOF

