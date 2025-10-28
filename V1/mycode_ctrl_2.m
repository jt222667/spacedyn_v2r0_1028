% ========== 三分支机器人 21 自由度控制器 ==========
function [sys,x0,str,ts] = mycode_ctrl_2(t,x,u,flag)
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

function sys = mdlOutputs(t,x,u)

% ---------- 读取测量量 ----------
qr  = u(1:21);      % 实际关节角度
dqr = u(22:42);     % 实际关节角速度

% ---------- 轨迹生成初始化 ----------
T  = 1;   % 轨迹时长（s）
nq = 21;  % 关节数
q0 = zeros(nq,1);
qf = zeros(nq,1);
qd   = zeros(nq,1); % 期望位置
dqd  = zeros(nq,1); % 期望速度
ddqd = zeros(nq,1); % 期望加速度

% ---------- 当下时刻指定关节i对应的期望轨迹（角度、角速度、角加速度） ----------
qf(1) = 1/6;
qf(2) = 0.5*pi;

for i = 1:nq
    [qd(i), dqd(i), ddqd(i)] = quintic_trajectory(t, T, q0(i), qf(i));
end

% ---------- 计算当前状态下的动力学项（用测量 q, qd） ----------
[M, C, G] = calculate_dynamics(qr, dqr);

% ------------------ PTSMC 参数（可调） ------------------
% 预设时间与幂次
T1 = 1;        % 预设收敛时间（e1）
T2 = 0.8;      % 预设收敛时间（s）
alpha = 0.5;   % 0 < alpha < 1
beta  = 0.5;   % 0 < beta  < 1

% 设计自由度参数（论文采用 p1=p2=2, q1=q2=1, mu1=mu2=1 为示例）
p1 = 4; q1 = 1; mu1 = 1;
p2 = 4; q2 = 1; mu2 = 1;

% 按论文精确定义 b1,b2,b3
b1 = pi / ( alpha * T1 );
b2 = ( pi * p1 ) / ( alpha * mu1 * T1 * sqrt(p1 * q1) ) * ( 1/2 )^(1 - alpha/2);
b3 = ( pi * q1 * mu1 ) / ( alpha * T1 * sqrt(p1 * q1) ) * ( 1/2 )^(1 + alpha/2);

% 按论文精确定义 k1,k2,k3
k1 = pi / ( beta * T2 );
k2 = ( pi * p2 ) / ( beta * mu2 * T2 * sqrt(p2 * q2) ) * ( 1/2 )^(1 - beta/2);
k3 = ( pi * q2 * mu2 ) / ( beta * T2 * sqrt(p2 * q2) ) * ( 1/2 )^(1 + beta/2);

% 扰动补偿与饱和阈值（按论文 K >= |E(t)|；h 为饱和阈值）
K = 0.05;      % 根据实际扰动调整
h = 1e2;    % 饱和阈值，可调
EPS = 1e-8; % 数值稳定化（避免 0^(-alpha) 精度问题）

% ------------------ 计算误差与滑模量 ------------------
e1 = qr - qd;
e2 = dqr - dqd;

% 滑模面 s (文章的 s = e2 + b1 e1 + b2|e1|^{1-alpha} sign(e1) + b3|e1|^{1+alpha} sign(e1))
s = e2 + b1 .* e1 ...
    + b2 .* (abs(e1).^(1 - alpha) .* sign(e1)) ...
    + b3 .* (abs(e1).^(1 + alpha) .* sign(e1));

% ------------------ 等效项（ueq 的误差相关部分） ------------------
% 文章等效控制有 b1*e2 + b2(1-alpha)|e1|^{-alpha} e2 + b3(1+alpha)|e1|^{alpha} e2
% 直接实现时对 |e1|^{-alpha} 做数值保护
inv_abs_e1_alpha = 1 ./ ( (abs(e1) + EPS) .^ alpha );  % 安全替代  |e1|^{-alpha}
b2_term_raw = b2 * (1 - alpha) .* ( inv_abs_e1_alpha .* e2 );  % 可能很大 -> 用饱和
b2_term = sat_vec( b2_term_raw, h );
b1_term = b1 .* e2;
b3_term = b3 * (1 + alpha) .* ( abs(e1) .^ alpha .* e2 );
eq_terms = b1_term + b2_term + b3_term;    % 这是 ueq 中与 e2 相关的那一部分

% ------------------ 切换项 usw ------------------
% usw = k1*s + k2 |s|^{1-beta} sign(s) + k3 |s|^{1+beta} sign(s) + K sign(s)
usw = k1 .* s ...
    + k2 .* ( abs(s).^(1 - beta) .* sign(s) ) ...
    + k3 .* ( abs(s).^(1 + beta) .* sign(s) ) ...
    + K  .* sign(s);

% ------------------ 最终计算力矩 tau ------------------
% F = zeros(nq,1);
F = calculate_joint_friction(dqr);
tau = M * ( ddqd - eq_terms - usw ) + C + G + F ;

% ---------- 输出结果 ----------
sys = zeros(105,1);
sys(1:21)  = tau;   % 计算得到的力矩
sys(22:42) = qr;    % 参考轨迹
sys(43:63) = dqr;
sys(64:84) = dqd;
sys(85:105) = qd;

