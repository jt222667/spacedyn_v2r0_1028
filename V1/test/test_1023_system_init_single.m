%% ===================== system_init_single.m =====================
function test_1023_system_init_single()
global Gravity LP SV Ez
Ez      = [0; 0; 1];
Gravity = [0; 0; 0];
LP.num_q = 7;

SV = init_SV(LP);
LP.J_type = repmat('R', 1, LP.num_q);
LP.BB = [0 1 2 3 4 5 6];

LP.SS = calculate_SS(LP);
LP.S0 = zeros(1, LP.num_q); LP.S0(1)  = 1;
LP.SE = zeros(1, LP.num_q); LP.SE(7) = 1;

%% 姿态与几何参数（取原 system_init 前7组）
LP.Qi = [ ...
    0      0      0;
    pi/2   0      0;
    -pi/2  0      0;
    pi/2   0      0;
    -pi/2  0      0;
    pi/2   0      0;
    -pi/2  0      0]';
LP.Qe = zeros(3, LP.num_q);
SV  = calc_aa(LP, SV);

% 结构尺寸
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

LP.cc = zeros(3, LP.num_q, LP.num_q);
LP.c0 = zeros(3, LP.num_q);
LP.ce = zeros(3, LP.num_q);
LP.c0(:,1) = [0;0;0.25];

for k = 1:7
    LP.cc(:,k,k) = -Pc(:,k);
    if k < 7
        LP.cc(:,k,k+1) = P(:,k) - Pc(:,k);
    end
end
LP.ce(:,7) = P(:,7) - Pc(:,7) + [0;0;0.08];

%% 惯量
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
    LP.inertia(:,3*k-2:3*k) = I(:,:,k);
end

LP.m0 = 5.7514;
m = 3 * [0.6926 1.1285 0.4417 0.4549 1.1285 0.6926 0.4863];
LP.m = m;
LP.mass = sum(LP.m) + LP.m0;

SV = calc_pos(LP, SV);
end
