function [sys,x0,str,ts] = chap1_1input(t,x,u,flag)
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
global M
M=2;
sizes = simsizes;
sizes.NumContStates  = 2;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      = 0;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = [0.5,0];
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global M
if M==1
r=0;
elseif M==2
r=sin(4*t);
end

nmn1=10;
nmn2=25;
sys(1)=x(2);
sys(2)=-nmn1*x(2)-nmn2*x(1)+nmn2*r;
function sys=mdlOutputs(t,x,u)
global M
if M==1
r=0;
elseif M==2
r=sin(4*t);
end

nmn1=10;
nmn2=25;

xm=x(1);
dxm=x(2);
ddxm=-nmn1*x(2)-nmn2*x(1)+nmn2*r;

sys(1)=xm;
sys(2)=dxm;
sys(3)=ddxm;