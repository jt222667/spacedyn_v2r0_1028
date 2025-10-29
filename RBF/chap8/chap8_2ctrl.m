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
global hidden3 c3 b3;
sizes = simsizes;
sizes.NumContStates  = 10;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      =5;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);

x0=0*(1:10);
str=[];
ts=[-1 0];
hidden3=9;b3=10;c3=1.01;
function sys=mdlDerivatives(t,x,u)
global hidden3 c3 b3;
x1d=u(1);
x3d=u(2);
x3_bar=u(3);
x2=u(4);
x3=u(5);

rou3=0.05;epc=0.01;

tol3=0.01;
S3=x3-x3d;
dx3d=(x3_bar-x3d)/tol3;

xx=[x2;x3];

d3=[-9 -7 -5 -3 0 3 5 7 9;
    -9 -7 -5 -3 0 3 5 7 9];

for i=1:hidden3
    kesi3(i)=exp(-((norm(xx-d3(:,i)))^2)/(2*b3^2));
end
fai3=[kesi3,rou3^2*S3/(2*epc)-dx3d+c3*S3]';
eta3=0.001;

gama3=20*eye(10);

dth3=gama3*S3*fai3-gama3*eta3*x;
for i=1:hidden3+1
    sys(i)=dth3(i);
end

function sys=mdlOutputs(t,x,u)
global hidden3 c3 b3;
x1d=u(1);
x3d=u(2);
x3_bar=u(3);
x2=u(4);
x3=u(5);

rou3=0.05;epc=0.01;

tol3=0.0198;
S3=x3-x3d;
dx3d=(x3_bar-x3d)/tol3;

xx=[x2;x3];
d3=[-9 -7 -5 -3 0 3 5 7 9;
    -9 -7 -5 -3 0 3 5 7 9];

for i=1:hidden3
    kesi3(i)=exp(-((norm(xx-d3(:,i)))^2)/(2*b3^2));
end
fai3=[kesi3,rou3^2*S3/(2*epc)-dx3d+c3*S3]';

th3=x;
th3_w=x(1:9);

sys(1)=x(10);         %1/a3
sys(2)=th3_w'*kesi3'; %to approximate 1/a3*f3
sys(3)=-th3'*fai3;    %u