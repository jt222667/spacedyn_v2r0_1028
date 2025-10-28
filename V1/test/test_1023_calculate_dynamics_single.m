%% ===================== calculate_dynamics_single.m =====================
function [M, C, G] = test_1023_calculate_dynamics_single(q, dq)

global LP SV

SV.q = q;
SV.qd = dq;
SV.qdd = zeros(LP.num_q, 1);

% 计算 G
SV.qd = zeros(LP.num_q, 1);
SV.qdd = zeros(LP.num_q, 1);
SV = calc_aa(LP, SV);
SV = calc_pos(LP, SV);
Force = r_ne(LP, SV);
G = Force(7:6+LP.num_q);

% 计算 M
M = zeros(LP.num_q);
for k = 1:LP.num_q
    SV.q = q;
    SV.qd = zeros(LP.num_q,1);
    qdd_tmp = zeros(LP.num_q,1);
    qdd_tmp(k) = 1;
    SV.qdd = qdd_tmp;
    SV = calc_aa(LP,SV);
    SV = calc_pos(LP,SV);
    Force_k = r_ne(LP,SV);
    tau_k = Force_k(7:6+LP.num_q);
    M(:,k) = tau_k - G;
end

% 计算 C
SV.q = q;
SV.qd = dq;
SV.qdd = zeros(LP.num_q,1);
SV = calc_aa(LP,SV);
SV = calc_pos(LP,SV);
Force_c = r_ne(LP,SV);
tau_c = Force_c(7:6+LP.num_q);
C = tau_c - G;
end
