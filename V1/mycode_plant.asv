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

LP = init_LP_1027_mex;
SV = init_SV_1027_mex;

[M, C, G] = calculate_dynamics(qr, dqr, LP, SV);

M=10000*M;

F = calculate_joint_friction_mex(dqr);

F = 1.3 * F;

qdd = M \ (tau - C - G  - F );

sys(:) = qdd;
