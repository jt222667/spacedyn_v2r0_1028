function [M,C,G] = calculate_dynamics(q, dq)
%% 初始化参数
global Gravity LP SV Ez  
Ez      = [0; 0; 1];      
Gravity = [0; 0; 0];     
q = q(:); dq = dq(:);
LP.num_q  = 21;     
SV  = init_SV(LP);
LP.J_type = repmat('R', 1, LP.num_q); 
LP.BB = [ ...
    0  1  2  3  4  5  6,  ... 
    0  8  9  10 11 12 13, ... 
    0 15 16 17 18 19 20  ];    
LP.SS = calculate_SS(LP);
LP.S0 = zeros(1, LP.num_q); LP.S0([1, 8, 15])  = 1;
LP.SE = zeros(1, LP.num_q); LP.SE([7, 14, 21]) = 1;

%% 姿态常量 (RPY角)，计算旋转矩阵SV.AA
LP.Qi = [ ...
     0      0      0;
     pi/2   0      0;
    -pi/2   0      0;
     pi/2   0      0;
    -pi/2   0      0;
     pi/2   0      0;
    -pi/2   0      0;
     0    2*pi/3   0;
     pi/2   0      0;
    -pi/2   0      0;
     pi/2   0      0;
    -pi/2   0      0;
     pi/2   0      0;
    -pi/2   0      0;
     0    4*pi/3   0;
     pi/2   0      0;
    -pi/2   0      0;
     pi/2   0      0;
    -pi/2   0      0;
     pi/2   0      0;
    -pi/2   0      0]';

LP.Qe = zeros(3, LP.num_q); 
SV  = calc_aa(LP, SV);

%% 结构尺寸
P01 = rpy2dc(0, 2*pi/3, 0) * [0; 0; 25];
P02 = rpy2dc(0, 4*pi/3, 0) * [0; 0; 25];

P = [ ...
    0      0      0.2052;
    0      0.1565      0;
    0      0       0.239;
    0      0.0785      0;
    0      0      0.0720;
    0      0.2455      0;
    0      0      0.1530]';

Pc = [ ...
    0     -0.0014 0.1026;
    0      0.1020 0.0016;
    0     -0.0022 0.0599;
    0      0.0371 0.0040;
    0     -0.0016 0.1435;
    0      0.0539 0.0014;
    0      0      0.0458]';

E1 = [0; 0; 0.08];
E2 = [0; 0; 0.25];
E3 = [0; 0; 0.25];

%% LP.cc / c0 / ce
LP.cc = zeros(3, LP.num_q, LP.num_q);
LP.c0 = zeros(3, LP.num_q);
LP.ce = zeros(3, LP.num_q);

LP.c0(:, 1)  = [0; 0; 0.25];
LP.c0(:, 8)  = P01;
LP.c0(:, 15) = P02;

for k = 1:7
    LP.cc(:, k, k) = -Pc(:, k);
    if k < 7
        LP.cc(:, k, k+1) = P(:, k) - Pc(:, k);
    end
end

LP.cc(:, 8:14,  8:14)  = LP.cc(:, 1:7, 1:7);
LP.cc(:, 8:14,  9:15)  = LP.cc(:, 1:7, 2:8);
LP.cc(:, 15:21, 15:21) = LP.cc(:, 1:7, 1:7);
LP.cc(:, 15:21, 16:22) = LP.cc(:, 1:7, 2:8);

LP.ce(:, 7)  =  P(:,7) - Pc(:,7) + E1;
LP.ce(:, 14) =  P(:,7) - Pc(:,7) + E2;
LP.ce(:, 21) =  P(:,7) - Pc(:,7) + E3;

%% 质量与惯量
LP.m0 = 5.7514;
m =3* [0.6926 1.1285 0.4417 0.4549 1.1285 0.6926 0.4863];
LP.m  = [m, m, m];
LP.mass = sum(LP.m) + LP.m0;

I6 = @(xx, yy, zz, xy, yz, xz)[xx -xy -yz; -xy yy -xz; -yz -xz zz];
I  = cat(3, ...
    I6(0.0012, 0, 0, 0.0012, 0, 0.0013), ...
    I6(0.0018, 0, 0, 0.0018, -0.0002, 0.0016), ...
    I6(0.0007, 0, 0, 0.0007, 0, 0.0008), ...
    I6(0.0007, 0, 0, 0.0007, -0.0002, 0.0005), ...
    I6(0.0018, 0, 0, 0.0016, -0.0002, 0.0018), ...
    I6(0.0012, 0, 0, 0.0013, 0, 0.0012), ...
    I6(0.0004, 0, 0, 0.0004, 0, 0.0007));
LP.inertia = zeros(3, 3*LP.num_q);
for k = 1:LP.num_q
    Ik = I(:, :, mod(k-1, 7)+1);
    LP.inertia(:, 3*k-2:3*k) = Ik;
end
LP.inertia0 = I6(0.0347, 0, 0, 0.0519, 0, 0.0347);

%% 位姿计算 SV.RR
SV = calc_pos(LP, SV);

%% (1) 计算 G (qd=0, qdd=0)
SV.q = q;
SV.qd = zeros(LP.num_q,1);
SV.qdd = zeros(LP.num_q,1);
SV = calc_aa(LP,SV);
SV = calc_pos(LP,SV);

Force = r_ne(LP, SV);    
G = Force(7:6+LP.num_q);

%% (2) 计算 M (qd=0，qdd取单位阵的列)
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

%% 计算 C (qdd=0) 
SV.q = q;
SV.qd = dq;
SV.qdd = zeros(LP.num_q,1);
SV = calc_aa(LP,SV);
SV = calc_pos(LP,SV);

Force_c = r_ne(LP,SV);
tau_c = Force_c(7:6+LP.num_q);
C = tau_c - G;

end