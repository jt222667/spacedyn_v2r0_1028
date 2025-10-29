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
sizes.NumContStates  = 3;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      = 1;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
x0  = [1;0;0];
str = [];
ts  = [0 0];
function sys=mdlDerivatives(t,x,u)
Vt=200;g=9.8;Lop=-0.1;Lap=1;Ma=0.1;Mq=-0.02;Md=1;
Del1=0.01*sin(2*t);
Del2=0.1*cos(2*t);
Del3=0.05*sin(t)*cos(2*t);

ut=u(1);
sys(1)=-g/Vt*cos(pi*x(1)/180)+Lop+Lap*x(2)+Del1;      
sys(2)=g/Vt*cos(pi*x(1)/180)-Lop-Lap*x(2)+x(3)+Del2;
sys(3)=Ma*x(2)+Mq*x(3)+Md*ut+Del3;
%角状态变量均以degree为单位，cos()函数中化为弧度计算
function sys=mdlOutputs(t,x,u)
sys(1)=x(1);
sys(2)=x(2);
sys(3)=x(3);