function [M, C, G] = calculate_dynamics(q, dq, LP, SV) %#codegen

% ---------- 计算 G ----------
SV.q = q;
SV.qd = zeros(21, 1);
SV.qdd = zeros(21, 1);
SV = calc_aa_mex(LP, SV);
SV = calc_pos_mex(LP, SV);
Force = r_ne_mex(LP, SV);
G = Force(7:27);

% ---------- 计算 M ----------
M = zeros(21);
for k = 1:21
    SV.q = q;
    SV.qd = zeros(21, 1);
    qdd_tmp = zeros(21, 1);
    qdd_tmp(k) = 1;
    SV.qdd = qdd_tmp;
    SV = calc_aa_mex(LP, SV);
    SV = calc_pos_mex(LP, SV);
    Force_k = r_ne_mex(LP, SV);
    tau_k = Force_k(7:27);
    M(:, k) = tau_k - G;
end

% ---------- 计算 C ----------
SV.q = q;
SV.qd = dq;
SV.qdd = zeros(21, 1);
SV = calc_aa_mex(LP, SV);
SV = calc_pos_mex(LP, SV);
Force_c = r_ne_mex(LP, SV);
tau_c = Force_c(7:27);
C = tau_c - G;

end
