function [sys,x0,str,ts]=obser(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 3,
    sys=mdlOutputs(t,x,u);
case {2, 4, 9 }
    sys = [];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 1;
sizes.NumInputs      = 6;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys=simsizes(sizes);
x0=[];
str=[];
ts=[];
function sys=mdlOutputs(t,x,u)
x1d=u(1);
dx1d=cos(t);
ddx1d=-sin(t);

fxp=u(2);gxp=u(3);
x1p=u(4);x2p=u(5);
x1=u(6);

K1=400;K2=800;

e=x1p-x1d;
de=x2p-dx1d;
c=20;
xite=0.10;
s=c*e+de;

ye=x1-x1p;
D=0.8;
v=-D*sign(ye);

ut=1/(gxp+0.1)*(-c*(x2p+K1*ye-dx1d)-fxp+v-K2*ye+ddx1d-xite*sign(s));
sys(1)=ut;