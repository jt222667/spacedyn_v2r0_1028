function [sys,x0,str,ts]=mycode_plant(t,x,u,flag)

switch flag
    case 0
        [sys,x0,str,ts]=mdlInitializeSizes;
    case 3
        sys=mdlOutputs(t,x,u);
    case {2,4,9}
        sys = [];
    otherwise
        error(['Unhandled flag = ',num2str(flag)]);
end

function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumOutputs     = 21;
sizes.NumInputs      = 63;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [0 0];

function sys=mdlOutputs(t,x,u)

tau  = u(1:21);
qr   = u(22:42);
dqr  = u(43:63);

[M, C, G, F] = calculate_dynamics_mex(qr, dqr);

M = 1.3 * M;
C = 1.3 * C;
G = 1.3 * G;

% F = 1.1 * F;

qdd = M \ (tau - C - G  - F );

sys(:) = qdd;
