function [pos, vel, acc] = quintic_trajectory(t, T, q0, qf) %#codegen
if t <= 0
    pos = q0; vel = 0; acc = 0;
    return;
end
if t >= T
    pos = qf; vel = 0; acc = 0;
    return;
end
% 仅在 0..T 区间使用标准五次多项式
a0 = q0;
a1 = 0;
a2 = 0;
a3 = (10*(qf-q0))/T^3;
a4 = (-15*(qf-q0))/T^4;
a5 = (6*(qf-q0))/T^5;
pos = a0 + a1*t + a2*t^2 + a3*t^3 + a4*t^4 + a5*t^5;
vel = a1 + 2*a2*t + 3*a3*t^2 + 4*a4*t^3 + 5*a5*t^4;
acc = 2*a2 + 6*a3*t + 12*a4*t^2 + 20*a5*t^3;

end