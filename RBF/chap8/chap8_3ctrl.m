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
sizes.NumInputs      =7;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=0*(1:8);
str=[];
ts=[-1 0];
function sys=mdlDerivatives(t,x,u)
x1d=u(1);
x4d=u(2);
x4_bar=u(3);
x1=u(4);
x2=u(5);
x3=u(6);
x4=u(7);

delta2=0.1;epc=0.01;c4=5;

tol4= 0.01;
S4=x4-x4d;
dx4d=(x4_bar-x4d)/tol4;

xx=[x1;x3];
hidden2=7;
d2=0.5*[-3 -2 -1 0 1 2 3;
    -3 -2 -1 0 1 2 3];

b2=1;
for i=1:hidden2
    h2(i)=exp(-((norm(xx-d2(:,i)))^2)/(2*b2^2));
end
fai2=[h2,delta2^2*S4/(2*epc)-dx4d+c4*S4]';

gama2=diag([10,10,10,10,10,10,10,0.4]);

xite2=0.00002;

dth2=gama2*S4*fai2-gama2*xite2*x;
for i=1:hidden2+1
    sys(i)=dth2(i);
end

function sys=mdlOutputs(t,x,u)
x1d=u(1);
x4d=u(2);
x4_bar=u(3);
x1=u(4);
x2=u(5);
x3=u(6);
x4=u(7);

delta2=0.1;epc=0.01;c4=5;

tol4= 0.01;
S4=x4-x4d;
dx4d=(x4_bar-x4d)/tol4;

xx=[x1;x3];
hidden2=7;
d2=0.5*[-3 -2 -1 0 1 2 3;
    -3 -2 -1 0 1 2 3];

b2=1;
for i=1:hidden2
    h2(i)=exp(-((norm(xx-d2(:,i)))^2)/(2*b2^2));
end
fai2=[h2,delta2^2*S4/(2*epc)-dx4d+c4*S4]';

th2=[x(1) x(2) x(3) x(4) x(5) x(6) x(7) x(8)];
th2_w=[x(1) x(2) x(3) x(4) x(5) x(6) x(7)];

ut=-th2*fai2;  %Control law

sys(1)=x(8);     %a2
sys(2)=th2_w*h2'; %f2(x1,x3)
sys(3)=ut; 