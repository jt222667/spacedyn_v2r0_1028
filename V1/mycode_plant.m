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

LP = single_init_2_mex;
SV = init_SV_1027_mex;

[M, C, G] = calculate_dynamics(qr, dqr, LP, SV);
F = calculate_joint_friction_mex(dqr);

M=1*M;
C=1*C;
G=1*G;
F = 1.3 * F;

qdd = M \ (tau - C - G  - F );

sys(:) = qdd;
