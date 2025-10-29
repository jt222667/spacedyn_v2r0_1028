function [sys,x0,str,ts]=obser(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u);
case 3,
    sys=mdlOutputs(t,x,u);
case {2, 4, 9 }
    sys = [];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 2;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 4;
sizes.NumInputs      = 1;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 0;
sys=simsizes(sizes);
x0=[0.2 0];
str=[];
ts=[];
function sys=mdlDerivatives(t,x,u)
m=1;l=1;M=0.5;g=9.8;
fx=-0.5*m*g*l*sin(x(1))/M;
gx=1/M;

sys(1)=x(2);
sys(2)=fx+gx*u;
function sys=mdlOutputs(t,x,u)
m=1;l=1;M=0.5;g=9.8;
fx=-0.5*m*g*l*sin(x(1))/M;
gx=1/M;

y=x(1);
sys(1)=y;
sys(2)=x(2);
sys(3)=fx;
sys(4)=gx;