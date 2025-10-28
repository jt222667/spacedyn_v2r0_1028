%% ===================== test_1023_time_test.m =====================
clear; clc;

disp('=== 初始化单臂系统 ===');
test_1023_system_init_single();

disp('=== 生成关节轨迹 ===');
t = 1;
T = 2;
q0 = zeros(7, 1);
qf = [pi/6; -pi/4; pi/3; -pi/6; pi/4; -pi/3; pi/6];
[qd, dqd, ddqd] = quintic_trajectory(t ,T ,q0, qf);

disp('=== 计算动力学矩阵 ===');
time1 = tic;
[M, C, G] = test_1023_calculate_dynamics_single(qd, dqd);
total_time = toc(time1);  % 获取总耗时
disp(['test_1023_calculate_dynamics_single 总耗时：', num2str(total_time), ' 秒']);

disp('=== 仿真完成 ===');
