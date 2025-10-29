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
c=[-1 -0.5 0 0.5 1;
   -1 -0.5 0 0.5 1];
b=50*ones(5,1);
alfa=200;

sizes = simsizes;
sizes.NumContStates  = 5;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 4;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = [zeros(5,1)];
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global c b alfa
qd=u(1);
dqd=cos(t);
ddqd=-sin(t);

q=u(2);dq=u(3);

e=q-qd;
de=dq-dqd;
x2=de+alfa*e;

xi=[e;de];
h=zeros(5,1);
for j=1:1:5
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b(j)*b(j)));
end
% Adaptive Law
xite=1000;
S=-xite*x2*h';
for i=1:1:5
    sys(i)=S(i);
end
function sys=mdlOutputs(t,x,u)
global c b alfa
 
qd=u(1);
dqd=cos(t);
ddqd=-sin(t);

q=u(2);dq=u(3);

e=q-qd;
de=dq-dqd;

M=1.0;
w=M*alfa*de;
Gama=0.10;

xi=[e;de];
h=zeros(5,1);
for j=1:1:5
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b(j)*b(j)));
end
Wf=[x(1) x(2) x(3) x(4) x(5)]';

x2=de+alfa*e;
    
S=2;
if S==1      %Without RBF compensation
    ut=-w-0.5*1/Gama^2*x2-0.5*x2;
elseif S==2  %With RBF compensation
    ut=-w+Wf'*h-0.5*1/Gama^2*x2-0.5*x2;
end

T=ut+M*ddqd;

NN=Wf'*h;

sys(1)=T;
sys(2)=NN;