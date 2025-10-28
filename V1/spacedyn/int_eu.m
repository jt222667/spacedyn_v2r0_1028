%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    version 1 // Oct 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% INT_EU	Integration of the system motion by a simple Euler method
%
%		INT_EU returns velocity & position vectors 
%		of each link of the system in the inertia frame.
%		It uses a simple, most primitive  Euler integration.
%
%		(The fomula of delta_CO = tilde(w0')*C0 is used.
%		But its integration is subject to error accumulation,
%		yielding non-normal, non-orthogonal C0.
%		int_eu2 is recommended for large attitude motion.) 
%
%		A constant time step is used.
%
%		[R0,A0,q,v0,w0,qd]=int_eu(R0,A0,q,v0,w0,qd,vd0,wd0,qdd)
%	
%		NOTE:v0,w0,vd0,wd0 are in the inertia frame.
%
% INT_EU    采用简单欧拉方法对系统运动进行积分
%
%        INT_EU 返回系统各连杆在惯性坐标系中的速度与位置向量。
%        该方法采用最基础的欧拉积分法。
%
%        （采用 delta_CO = tilde(w0')*C0 的公式。
%        但其积分易受误差累积影响，
%        导致 C0 矩阵非规范且非正交。
%        建议大型姿态运动使用 int_eu2。）
%
%        采用恒定时间步长。
%
%        [R0,A0,q,v0,w0,qd]=int_eu(R0,A0,q,v0,w0,qd,vd0,wd0,qdd)
%    
%        注：v0,w0,vd0,wd0 均在惯性坐标系中。
%


function SV = int_eu( LP, SV )

global d_time


% Single body
if LP.num_q == 0
   q_n = [];
   qd_n = [];
   
% Multi bodies
else
   qd_n = SV.qd + SV.qdd * d_time;
   q_n  = SV.q  + SV.qd  * d_time;
   
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Integration of v0, R0, and A0
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

R0_n = SV.R0 + SV.v0  * d_time;
v0_n = SV.v0 + SV.vd0 * d_time;
w0_n = SV.w0 + SV.wd0 * d_time;

% Note that C0 is the direction cosines of body 0
% C0 = ( A0 )^T

C0 = ( SV.A0 )';

% dC0 is the time derivative of C0
dC0 = (tilde(SV.w0))' * C0;
C0_n = C0 + dC0 * d_time;

% outputs
SV.R0 = R0_n;
SV.A0 = ( C0_n )';
SV.v0 = v0_n;
SV.w0 = w0_n;
SV.q  = q_n;
SV.qd = qd_n;


%%%EOF
