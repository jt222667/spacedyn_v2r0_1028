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
global hidden2 c2 b2;
sizes = simsizes;
sizes.NumContStates  = 9;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      =4;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);

x0=0*(1:9);
str=[];
ts=[-1 0];
hidden2=9;b2=10;c2=2.01;
function sys=mdlDerivatives(t,x,u)
global hidden2 c2 b2;
x1=u(1);
x2=u(2);
x2d=u(3);
x2_bar=u(4);

S2=x2-x2d;
tol2=0.01;
dx2d=(x2_bar-x2d)/tol2;

xx=[x1;x2];

d2=[-9 -7 -5 -3 0 3 5 7 9;
    -9 -7 -5 -3 0 3 5 7 9];

for i=1:hidden2
    kexi2(i)=exp(-((norm(xx-d2(:,i)))^2)/(2*b2^2));
end
fai2=kexi2';

eta2=0.002;
gama2=30*eye(9);

dth2=gama2*fai2*S2-gama2*eta2*x;
for i=1:hidden2
    sys(i)=dth2(i);
end

function sys=mdlOutputs(t,x,u)
global hidden2 c2 b2;
x1=u(1);
x2=u(2);
x2d=u(3);
x2_bar=u(4);

rou2=0.1;epc=0.01;

S2=x2-x2d;
tol2=0.0198;
dx2d=(x2_bar-x2d)/tol2;

xx=[x1;x2];
d2=[-9 -7 -5 -3 0 3 5 7 9;
    -9 -7 -5 -3 0 3 5 7 9];

for i=1:hidden2
    kesi2(i)=exp(-((norm(xx-d2(:,i)))^2)/(2*b2^2));
end
fai2=kesi2';

th2=x;

sys(1)=-th2'*fai2-rou2^2*S2/(2*epc)+dx2d-c2*S2; %x3_bar
sys(2)=th2'*fai2;   %f2