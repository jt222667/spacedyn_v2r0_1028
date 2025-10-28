function [sys,x0,str,ts] = mycode_ctrl_0(t,x,u,flag)

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
T  = 10;   % 轨迹时长（s）
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

F = 1;
% ---------- OG ----------
if F==1
    LP = init_LP_1028_mex;
    SV = init_SV_1027_mex;
    [M, C, G] = calculate_dynamics(qr, dqr, LP, SV);
    
    disp(M);
    disp(['rank(M)：', num2str(rank(M))]);
    disp(['cond(M)：', num2str(cond(M))]);
    disp(['rcond(M)：', num2str(rcond(M))]);
    disp(['nnz(M)：', num2str(nnz(M))]);
    disp(['det(M)：', num2str(det(M))]);
    disp(['trace(M)：', num2str(trace(M))]);

    F = calculate_joint_friction_mex(dqr);
    tau = M * ddqd + C + G + F ;

    % ---------- SMC ----------
elseif F==2
    % dq = dq + 0.01*randn(size(dq));
    e = qd - qr;
    de = dqd - dqr;
    [LP, SV] = INIT_mex;
    [M, C, G] = calculate_dynamics(qr, dqr, LP, SV);
    F = calculate_joint_friction_mex(dqr);
    k = 10;
    epsilon = 10.0;
    P = diag([20, 20, 20, 200, 200, 200, 200,20, 20, 20, 20, 20, 20, 20,20, 20, 20, 20, 20, 20, 200]);
    s = de + P * e;
    S_dot = -k * s - epsilon * sign(s); % 指数趋近律
    tau_dist = zeros(21,1);
    % if t > 2.5 && t < 2.55
    %     tau_dist(3) = 5;
    % end
    tau = M*(ddqd + P*de) + C + G - M * S_dot + tau_dist + F ;

    % ---------- SMC 调参 ----------
elseif F==3
    % ---------- 误差 ----------
    e  = qd - qr;
    de = dqd - dqr;
    % ---------- 动力学 ----------
    [LP, SV] = INIT_mex;
    [M, C, G] = calculate_dynamics(qr, dqr, LP, SV);
    F = calculate_joint_friction_mex(dqr);
    % ---------- 参数 ----------
    k = 80;
    epsilon = 100;
    lambda = 25;
    rho = 50;
    P = diag(50*ones(21,1));
    P(4:7,4:7) = 120*eye(4);
    % ---------- 滑模面 ----------
    s = de + P * e;
    % ---------- 改进指数趋近律 ----------
    S_dot = -k * s - epsilon * tanh(lambda * s) - rho * sign(s);
    % ---------- 外部扰动 ----------
    tau_dist = zeros(21,1);
    % if t > 2.5 && t < 2.55
    %     tau_dist(3) = 5;
    % end
    % ---------- 控制律 ----------
    tau = M*(ddqd + P*de) + C + G - M * S_dot + F + tau_dist;

    % ---------- NFTSMC ----------
elseif F==4
    % LP = single_init_2_mex;
    % LP = init_LP_1027_mex;
    LP = init_LP_1028_mex;
    SV = init_SV_1027_mex;
    [M, C, G] = calculate_dynamics(qr, dqr, LP, SV);

    disp(M);

    disp(['rank(M)：', num2str(rank(M))]);
    disp(['cond(M)：', num2str(cond(M))]);
    disp(['rcond(M)：', num2str(rcond(M))]);
    disp(['nnz(M)：', num2str(nnz(M))]);
    disp(['det(M)：', num2str(det(M))]);
    disp(['trace(M)：', num2str(trace(M))]);

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
    % if t > 2.5 && t < 2.55
    %     tau_dist(3) = 5;
    % end
    tau = M * ( B \ (ds - A) + ddqd ) + C + G + tau_dist + F  ;

    % ---------- PD ----------
elseif F==5
    % dq = dq + 0.01*randn(size(dq));
    % ---------- 误差 ----------
    e  = qr - qd;
    de = dqr - dqd;
    % ---------- 控制增益 ----------
    Kp = diag(100*ones(size(qr)));
    Kd = diag(20*ones(size(qr)));
    % ---------- 动力学计算 ----------
    [LP, SV] = INIT_mex;
    [M, C, G] = calculate_dynamics(qr, dqr, LP, SV);
    F = calculate_joint_friction_mex(dqr);
    ddqd = -Kp * e - Kd * de;
    tau_dist = zeros(21,1);
    % if t > 2.5 && t < 2.55
    %     tau_dist(3) = 5;
    % end
    tau = M * ddqd + C + G + F + tau_dist ;

end

sys = zeros(84,1);
sys(1:21)  = tau;
sys(22:42) = qr;
sys(43:63) = dqr;
sys(64:84) = qd;
