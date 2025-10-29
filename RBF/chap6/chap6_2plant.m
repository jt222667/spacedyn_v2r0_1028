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
sizes.NumContStates  = 4;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 4;
sizes.NumInputs      = 6;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 0;
sys=simsizes(sizes);
x0=[0.6;0.3;0.5;0.5];
str=[];
ts=[];
function sys=mdlDerivatives(t,x,u)
persistent ddx1 ddx2
if t==0
    ddx1=0;
    ddx2=0;
end
qd1=1+0.2*sin(0.5*pi*t);
dqd1=0.2*0.5*pi*cos(0.5*pi*t);
qd2=1-0.2*cos(0.5*pi*t);
dqd2=0.2*0.5*pi*sin(0.5*pi*t);

e1=x(1)-qd1;
e2=x(3)-qd2;
de1=x(2)-dqd1;
de2=x(4)-dqd2;

v=13.33;
q1=8.98;
q2=8.75;
g=9.8;

M0=[v+q1+2*q2*cos(x(3)) q1+q2*cos(x(3));
    q1+q2*cos(x(3)) q1];
C0=[-q2*x(4)*sin(x(3)) -q2*(x(2)+x(4))*sin(x(3));
     q2*x(2)*sin(x(3))  0];
G0=[15*g*cos(x(1))+8.75*g*cos(x(1)+x(3));
   8.75*g*cos(x(1)+x(3))];
d_M=0.2*M0;
d_C=0.2*C0;
d_G=0.2*G0;

d1=2;d2=3;d3=6;
d=[d1+d2*norm([e1,e2])+d3*norm([de1,de2])];
%d=20*sin(2*t);
tol(1)=u(1);
tol(2)=u(2);

dq=[x(2);x(4)];
ddq=[ddx1;ddx2];
f=inv(M0)*(d_M*ddq+d_C*dq+d_G+d);

ddx=inv(M0)*(tol'-C0*dq-G0)+1*f;

sys(1)=x(2);
sys(2)=ddx(1);
sys(3)=x(4);
sys(4)=ddx(2);
ddx1=ddx(1);
ddx2=ddx(2);
function sys=mdlOutputs(t,x,u)
sys(1)=x(1);
sys(2)=x(2);
sys(3)=x(3);
sys(4)=x(4);