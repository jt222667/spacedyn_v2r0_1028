function [sys,x0,str,ts] = obser(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u);
case 3,
    sys=mdlOutputs(t,x,u);
case {1,2,4,9}
    sys=[];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 2;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 4;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0=[0 0];
str=[];
ts=[];
function sys=mdlDerivatives(t,x,u)
K1=400;K2=800;
y=u(1);
ut=u(2);
fxp=u(3);
gxp=u(4);

A=[0 1;0 0];
b=[0 1]';
C=[1 0];
K=[K1 K2]';

ye=y-x(1);
D=1.50;
v=-D*sign(ye);

dx=A*x+b*(fxp+gxp*ut-v)+K*(y-C*x);
sys(1)=dx(1);
sys(2)=dx(2);
function sys=mdlOutputs(t,x,u)
sys(1) = x(1);
sys(2) = x(2);