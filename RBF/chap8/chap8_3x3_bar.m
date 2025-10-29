function [sys,x0,str,ts]=s_function(t,x,u,flag)
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
sizes.NumContStates  = 8;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      = 4;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=0*(1:8);
str=[];
ts=[-1 0];
function sys=mdlDerivatives(t,x,u)
x1=u(1);
x2=u(2);
x2d=u(3);
x2_bar=u(4);

delta1=0.1;epc=0.01;c2=65;

S2=x2-x2d;
tol2=0.0138;
dx2d=(x2_bar-x2d)/tol2;

hidden1=7;
d1=[-3 -2 -1 0 1 2 3];
b1=1;
for i=1:hidden1
    h1(i)=exp(-((x1-d1(i))^2)/(2*b1^2));
end
fai1=[h1,delta1^2*S2/(2*epc)-dx2d+c2*S2]';

gama1=diag([3,3,3,3,3,3,3,0.001]);

xite1=0.008;

dth1=gama1*fai1*S2-gama1*xite1*x;
for i=1:hidden1+1    
    sys(i)=dth1(i);
end
function sys=mdlOutputs(t,x,u)
x1=u(1);
x2=u(2);
x2d=u(3);
x2_bar=u(4);

delta1=0.1;epc=0.01;c2=65;

S2=x2-x2d;
tol2=0.01;
dx2d=(x2_bar-x2d)/tol2;

hidden1=7;
d1=[-3 -2 -1 0 1 2 3];
b1=1;
for i=1:hidden1
    h1(i)=exp(-((x1-d1(i))^2)/(2*b1^2));
end
fai1=[h1,delta1^2*S2/(2*epc)-dx2d+c2*S2]';

th1=[x(1) x(2) x(3) x(4) x(5) x(6) x(7) x(8)];
th1_w=[x(1) x(2) x(3) x(4) x(5) x(6) x(7)];

sys(1)=-th1*fai1;  %x3_bar
sys(2)=x(8);      %a1
sys(3)=th1_w*h1';  %f1