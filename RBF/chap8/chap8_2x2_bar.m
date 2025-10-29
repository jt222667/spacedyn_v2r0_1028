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
global hidden1 c1 b1;
sizes = simsizes;
sizes.NumContStates  = 8;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      =1;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=0*(1:8);
str=[];
ts=[-1 0];
hidden1=7;b1=10;c1=1.51;
function sys=mdlDerivatives(t,x,u)
global hidden1 c1 b1;
x1=u(1);
x1d=5*sin(t);
dx1d=5*cos(t);
S1=x1-x1d;

rou1=0.01;epc=0.01;

d1=[-3 -2 -1 0 1 2 3];

for i=1:hidden1
    kexi1(i)=exp(-((x1-d1(i))^2)/(2*b1^2));
end
fai1=[kexi1,rou1^2*S1/(2*epc)-dx1d+c1*S1]';

eta1=0.04;
gama1=0.5*eye(8);

dth1=gama1*fai1*S1-gama1*eta1*x;
for i=1:hidden1+1    
    sys(i)=dth1(i);
end

function sys=mdlOutputs(t,x,u)
global hidden1 c1 b1;
x1=u(1);
x1d=5*sin(t);
dx1d=5*cos(t);
S1=x1-x1d;

rou1=0.01;epc=0.01;

d1=[-3 -2 -1 0 1 2 3];

for i=1:hidden1
    kexi1(i)=exp(-((x1-d1(i))^2)/(2*b1^2));
end
fai1=[kexi1,rou1^2*S1/(2*epc)-dx1d+c1*S1]';

th1=x;
th1_w=x(1:7);  %weight value

sys(1)=-th1'*fai1;   %x2_bar
sys(2)=x(8);        %1/a1
sys(3)=th1_w'*kexi1';%to approximate 1/a1*f1