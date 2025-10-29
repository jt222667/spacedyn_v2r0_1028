function [sys,x0,str,ts] = Robust_RBF(t,x,u,flag)
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
global c b alfa
c=0.5*[-3 -2 -1 0 1 2 3;
       -3 -2 -1 0 1 2 3;
       -3 -2 -1 0 1 2 3;
       -3 -2 -1 0 1 2 3];
b=10*ones(7,1);
alfa=20;

sizes = simsizes;
sizes.NumContStates  = 14;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 4;
sizes.NumInputs      = 8;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = [zeros(14,1)];
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global c b alfa

qd1=u(1);qd2=u(2);
dqd1=cos(t);dqd2=cos(t);
dqd=[dqd1 dqd2]';
ddqd1=-sin(t);ddqd2=-sin(t);
ddqd=[ddqd1 ddqd2]';

q1=u(3);dq1=u(4);
q2=u(5);dq2=u(6);

e1=q1-qd1;
e2=q2-qd2;
e=[e1 e2]';
de1=dq1-dqd1;
de2=dq2-dqd2;
de=[de1 de2]';
x2=de+alfa*e;

xi=[e1;e2;de1;de2];
%xi=[q1;dq1;q2;dq2];
h=zeros(7,1);
for j=1:1:7
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b(j)*b(j)));
end

% Adaptive Law
xite=1500;
S=-xite*x2*h';
for i=1:1:7
    sys(i)=S(1,i);
    sys(i+7)=S(2,i);    
end
function sys=mdlOutputs(t,x,u)
global c b alfa

qd1=u(1);qd2=u(2);
dqd1=cos(t);dqd2=cos(t);
dqd=[dqd1 dqd2]';
ddqd1=-sin(t);ddqd2=-sin(t);
ddqd=[ddqd1 ddqd2]';

q1=u(3);dq1=u(4);
q2=u(5);dq2=u(6);

e1=q1-qd1;
e2=q2-qd2;
e=[e1 e2]';
de1=dq1-dqd1;
de2=dq2-dqd2;
de=[de1 de2]';

r1=1;r2=0.8;
m1=1;m2=1.5;

M11=(m1+m2)*r1^2+m2*r2^2+2*m2*r1*r2*cos(x(3));
M22=m2*r2^2;
M21=m2*r2^2+m2*r1*r2*cos(x(3));
M12=M21;
M=[M11 M12;M21 M22];

V12=m2*r1*sin(x(3));
V=[-V12*x(4) -V12*(x(2)+x(4));V12*x(1) 0];
g1=(m1+m2)*r1*cos(x(3))+m2*r2*cos(x(1)+x(3));
g2=m2*r2*cos(x(1)+x(3));
G=[g1;g2];

w=M*alfa*de+V*alfa*e;
Gama=0.050;

xi=[e1;e2;de1;de2];
%xi=[q1;dq1;q2;dq2];
h=zeros(7,1);
for j=1:1:5
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b(j)*b(j)));
end
Wf=[x(1) x(2) x(3) x(4) x(5) x(6) x(7);
    x(8) x(9) x(10) x(11) x(12) x(13) x(14)]';

S=2;
if S==1    %Without RBF compensation
    ut=-e-w-0.5*1/Gama^2*(de+alfa*e);  
elseif S==2   %Without RBF compensation
    x2=de+alfa*e;
    ut=-w+Wf'*h-0.5*1/Gama^2*x2-0.5*x2;
end    
T=ut+M*ddqd+V*dqd+G;

NN=Wf'*h;

sys(1)=T(1);
sys(2)=T(2);
sys(3)=NN(1);
sys(4)=NN(2);