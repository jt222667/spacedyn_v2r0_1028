% test_quintic_trajectory_v1.m
clear; clc; close all;

% 参数
q0 = 0;         % 起点
qf = pi*ones(1,1);      % 终点
T  = 3;         % 总时间
dt = 0.01;
time = 0:dt:T;

N = numel(time);
pos = zeros(1,N); vel = zeros(1,N); acc = zeros(1,N);friction_forces = zeros(1,N);

for k = 1:N
    tk = time(k);
    % 注意：按你的 ctrl 写法，quintic_trajectory 返回 [pos, vel, acc]
    [pos(k), vel(k), acc(k)] = quintic_trajectory(tk, T, q0, qf);
    friction_forces(k) = -0.3519 * sign(vel(k)) + 9.1074 * vel(k) + 16.2233;
end

% 绘图
figure;
subplot(4,1,1); plot(time, pos,'LineWidth',1.5); grid on;
xlabel('t [s]'); ylabel('pos [rad]'); title('Quintic - position');

subplot(4,1,2); plot(time, vel,'LineWidth',1.5); grid on;
xlabel('t [s]'); ylabel('vel [rad/s]'); title('Quintic - velocity');

subplot(4,1,3); plot(time, acc,'LineWidth',1.5); grid on;
xlabel('t [s]'); ylabel('acc [rad/s^2]'); title('Quintic - acceleration');

subplot(4,1,4); plot(time, friction_forces,'LineWidth',1.5); grid on;
xlabel('t [s]'); ylabel('friction_forces'); title('Quintic - friction_forces');

disp(max(abs(acc)));
disp(max(abs(friction_forces)));
