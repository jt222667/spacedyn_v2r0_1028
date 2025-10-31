function [M, C, G, F] = calculate_dynamics(q, dq) %#codegen

% ---------- 初始化 ----------
LP = init_LP_1028();
SV = init_SV_1027();

% ---------- 计算 G ----------
SV.q = q;
SV.qd = zeros(21, 1);
SV.qdd = zeros(21, 1);
SV = calc_aa(LP, SV);
SV = calc_pos(LP, SV);
Force = r_ne(LP, SV);
G = Force(7:27);

% ---------- 计算 M ----------
M = zeros(21);
for k = 1:21
    SV.q = q;
    SV.qd = zeros(21, 1);
    qdd_tmp = zeros(21, 1);
    qdd_tmp(k) = 1;
    SV.qdd = qdd_tmp;
    SV = calc_aa(LP, SV);
    SV = calc_pos(LP, SV);
    Force_k = r_ne(LP, SV);
    tau_k = Force_k(7:27);
    M(:, k) = tau_k - G;
end

% ---------- 计算 C ----------
SV.q = q;
SV.qd = dq;
SV.qdd = zeros(21, 1);
SV = calc_aa(LP, SV);
SV = calc_pos(LP, SV);
Force_c = r_ne(LP, SV);
tau_c = Force_c(7:27);
C = tau_c - G;

% ---------- 计算 F ----------
friction_params = [
    1,   0.0013,  27.7543,  7.1649;
    2,  -3.2393,  37.3420, 13.3287;
    3,   7.0109,   9.5503,  6.7645;
    4,   1.8455,  42.2625,  7.8656;
    5,   5.2311,  21.8571,  4.9930;
    6,  -2.9146,  28.3255,  5.5236;
    7,   1.9626,  28.0928,  6.3949;
    8,  -0.3519,   9.1074, 16.2233;
    9,  13.0231,   7.0165, 10.8006;
    10, -16.2296, 46.6431,  6.8534;
    11, -9.2256,   9.6458,  9.1136;
    12, -2.4148,  23.9635,  6.4825;
    13,  6.3453,  30.4596,  6.8079;
    14, -1.7018,  16.3822,  6.8188;
    15,  0.5225,  51.6363, 14.5590;
    16, -9.2769,  32.9703,  9.8068;
    17,  9.0090,  31.1092, 10.2333;
    18,  8.1262,  30.8627,  7.5364;
    19, -2.7479,  28.5140,  6.6155;
    20, -4.0121,  25.6389,  8.2332;
    21,  0.0297,  20.0904,  5.6067
    ];

% 提取各参数列
fc = friction_params(:, 2);  % 库伦摩擦系数
fv = friction_params(:, 3);  % 粘滞摩擦系数
fb = friction_params(:, 4);  % 偏置摩擦系数

F = zeros(21, 1);

for i = 1:21
    F(i) = fc(i) * sign(q(i)) + fv(i) * q(i) + fb(i);
end

end