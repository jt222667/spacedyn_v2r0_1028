function [sys,x0,str,ts] = spacemodel(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u);
case 3,
    sys=mdlOutputs(t,x,u);
case {2,4,9}
    sys=[];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 6;
sizes.NumInputs      = 0;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [0 0];
function sys=mdlOutputs(t,x,u)
xd1=1+0.2*cos(pi*t);
d_xd1=-0.2*pi*sin(pi*t);
dd_xd1=-0.2*pi*pi*cos(pi*t);
xd2=1+0.2*sin(pi*t);
d_xd2=0.2*pi*cos(pi*t);
dd_xd2=-0.2*pi*pi*sin(pi*t);
sys(1)=xd1;
sys(2)=d_xd1;
sys(3)=dd_xd1;
sys(4)=xd2;
sys(5)=d_xd2;
sys(6)=dd_xd2;