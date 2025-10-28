% ========== 三分支机器人 21 自由度控制器 ==========
function [sys,x0,str,ts] = mycode_ctrl_og(t,x,u,flag)
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

% ========== 初始化 ==========
function [sys,x0,str,ts] = mdlInitializeSizes
sizes = simsizes;
sizes.NumOutputs     = 105;   
sizes.NumInputs      = 42; 
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);

x0  = [];
str = [];
ts  = [0 0];

% ========== 输出 ==========
function sys = mdlOutputs(t,x,u)

% ---------- 轨迹生成初始化 ----------
T  = 1;   % 轨迹时长
nq = 21;  % 总关节数
q0 = zeros(nq,1);
qf = zeros(nq,1);   % 三条臂末端都走 [0 -> 1] 的轨迹
qf(1) = 1/6;
qf(2) = 0.5*pi;
qd   = zeros(nq,1); % 期望位置
dqd  = zeros(nq,1); % 期望速度
ddqd = zeros(nq,1); % 期望加速度

% ---------- 输入分解 ----------
qr  = u(1:21);        % 实际关节位置
dqr = u(22:42);    % 实际关节速度

% ---------- 当下时刻指定关节i对应的期望轨迹（角度、角速度、角加速度） ----------
for i = 1:nq
        [qd(i), dqd(i), ddqd(i)] = quintic_trajectory(t, T, q0(i), qf(i));
end

% ---------- 计算动力学方程 ----------
[M, C, G] = calculate_dynamics(qd, dqd);
F = calculate_joint_friction(dqd);
tau = M * ddqd + C + G + F ;

% ---------- 输出结果 ----------
sys(1:21)  = tau;   % 力矩输出
sys(22:42) = qr;    % 实际关节角
sys(43:63) = dqr;   % 实际角速度
sys(64:84) = dqd;  % 期望角速度
sys(85:105) = qd;    % 期望轨迹
