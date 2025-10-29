function [sys,x0,str,ts] = spacemodel(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 3,
    sys=mdlOutputs(t,x,u);
case {1,2,4,9}
    sys=[];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 12;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [];
function sys=mdlOutputs(t,x,u)
qd1=u(1);
dqd1=u(2);
ddqd1=u(3);
qd2=u(4);
dqd2=u(5);
ddqd2=u(6);

q1=u(7);
dq1=u(8);
q2=u(9);
dq2=u(10);
dq=[dq1;dq2];

e1=qd1-q1;
e2=qd2-q2;
de1=dqd1-dq1;
de2=dqd2-dq2;
e=[e1;e2];
de=[de1;de2];
Fai=5*eye(2);
r=de+Fai*e;

dqd=[dqd1;dqd2];
dqr=dqd+Fai*e;
ddqd=[ddqd1;ddqd2];
ddqr=ddqd+Fai*de;

p=[2.9 0.76 0.87 3.04 0.87];
g=9.8;
M=[p(1)+p(2)+2*p(3)*cos(q2) p(2)+p(3)*cos(q2);
   p(2)+p(3)*cos(q2) p(2)];
C=[-p(3)*dq2*sin(q2) -p(3)*(dq1+dq2)*sin(q2);
    p(3)*dq1*sin(q2)  0];
G=[p(4)*g*cos(q1)+p(5)*g*cos(q1+q2);
   p(5)*g*cos(q1+q2)];
M0=0.8*M;
C0=0.8*C;
G0=0.8*G;
tolm=M0*ddqr+C0*dqr+G0;

EM=0.2*M;EC=0.2*C;EG=0.2*G;
E1=EM*ddqr+EC*dqr+EG;
told=20*sign(dq);
E=E1+told;

Kr=15*eye(2);  %Krii>=Ei
tolr=Kr*sign(r);

Kp=100*eye(2);
Ki=100*eye(2);

I=[u(11);u(12)];
tol=tolm+Kp*r+Ki*I+tolr;

sys(1)=tol(1);
sys(2)=tol(2);