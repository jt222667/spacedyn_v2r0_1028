function [sys,x0,str,ts] = mycode_ctrl_1027(t,x,u,flag)

switch flag
    case 0
        [sys,x0,str,ts] = mdlInitializeSizes;
    case 3
        sys = mdlOutputs(t,x,u);
    case {2,4,9}
        sys = [];
    otherwise
        error(['Unhandled flag = ',num2str(flag)]);
end

function [sys,x0,str,ts] = mdlInitializeSizes
sizes = simsizes;
sizes.NumOutputs     = 84;
sizes.NumInputs      = 42;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);

x0  = [];
str = [];
ts  = [0.001 0];

function sys = mdlOutputs(t,x,u)

% ---------- 读取测量量 ----------
qr  = u(1:21);      % 实际关节角度
dqr = u(22:42);     % 实际关节角速度

% ---------- 轨迹生成初始化 ----------
T  = 5;   % 轨迹时长（s）
nq = 21;  % 关节数
q0 = zeros(nq,1);
qf = zeros(nq,1);
qd   = zeros(nq,1); % 期望位置
dqd  = zeros(nq,1); % 期望速度
ddqd = zeros(nq,1); % 期望加速度

% ---------- 当下时刻指定关节i对应的期望轨迹（角度、角速度、角加速度） ----------
qf(1) = 0.5*pi;
qf(2) = 0.5*pi;
qf(3) = 0.5*pi;
qf(4) = 0.5*pi;
qf(5) = 0.5*pi;
qf(6) = 0.5*pi;
qf(7) = 0.5*pi;

for i = 1:nq
    [qd(i), dqd(i), ddqd(i)] = quintic_trajectory_mex(t, T, q0(i), qf(i));
end


% ---------- NFTSMC ----------
LP = init_LP_1027_mex;
SV = init_SV_1027_mex;
[M, C, G] = calculate_dynamics(qr, dqr, LP, SV);

F = calculate_joint_friction_mex(dqr);
% ---------- 误差 ----------
e  = qr - qd;
de = dqr - dqd;
% ---------- 控制律参数 ----------
alpha = 0.8*eye(nq);
beta  = 1.0*eye(nq);
m = 5/3;
n = 9/7;
K1 = 1000*eye(nq);
K2 = 200*eye(nq);
% ---------- 滑模面 ----------
s = e + alpha*((abs(e).^m).*sign(e)) + beta*((abs(de).^n).*sign(de));
% 修正项
A = de + alpha * m * (abs(e).^(m-1)) .* de;
epsilon = 1e-9;
B = diag(diag(beta) .* n .* ((abs(de)+epsilon).^(n-1)));
% 滑模控制律
ds = -K1 * beta * n * (abs(de).^(n-1)) .* s - K2 * (abs(e).^(diag(alpha))) .* sign(s);
% ---------- 动力学计算 ----------
tau_dist = zeros(21,1);
tau = M * ( B \ (ds - A) + ddqd ) + C + G + tau_dist + F  ;
sys = zeros(84,1);
sys(1:21)  = tau;
sys(22:42) = qr;
sys(43:63) = dqr;
sys(64:84) = qd;
