function [sys,x0,str,ts] = spacemodel(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 3,
    sys=mdlOutputs(t,x,u);
case {2,4,9}
    sys=[];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 10;
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
q=[q1;q2];

e1=qd1-q1;
e2=qd2-q2;
de1=dqd1-dq1;
de2=dqd2-dq2;
e=[e1;e2];
de=[de1;de2];
Fai=5*eye(2);
r=de+Fai*e;

sys(1:2)=r;