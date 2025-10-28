%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	February 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% F_KINE_J	Forward Kinematics:
%		Caluculate the Position/Orientation of the joints
%		corresponding the point specified by connection vector 'joints.'
%		POS : 3x1 vector, ORI : 3x3 matrix,
%		POS_j : 3xn, ORI : 3x3n,
%		where n : number of joints between the End-point to link 0.
%
% F_KINE_J    正向运动学：计算某个关节位置、方向
%        计算连接向量'joints.'指定点对应关节的位置/姿态
%        其中：
%        位置：3x1向量，姿态：3x3矩阵，
%        位置矩阵：3xn，姿态矩阵：3x3n，
%        其中n：终点到第0连杆之间的关节数。

function [ POS_j , ORI_j ] = f_kin_j( LP, SV, joints )

global Ez


% Check the number of the corresponding joints
n = length( joints );


% Calculation of Orientation and Position of each joints
POS_j = [];
ORI_j = [];

for i = 1 : 1 : n
   
   PorR = ( LP.J_type(joints(i)) == 'P' );
   ORI_tmp = SV.AA(:,joints(i)*3-2:joints(i)*3);
   POS_tmp = SV.RR(:,joints(i)) + ORI_tmp * ( LP.cc(:,joints(i),joints(i)) - PorR*Ez * SV.q(joints(i)) );
   
   POS_j = [POS_j POS_tmp];
   ORI_j = [ORI_j ORI_tmp];
   
end


%%%EOF
