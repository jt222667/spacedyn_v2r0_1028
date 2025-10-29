function [sys,x0,str,ts] = spacemodel(t,x,u,flag)
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
global node c b Fai
node=7;
c=[-1.5 -1 -0.5 0 0.5 1 1.5;
   -1.5 -1 -0.5 0 0.5 1 1.5];
b=10;
Fai=15;

sizes = simsizes;
sizes.NumContStates  = node;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      = 3;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = zeros(1,node);
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global node c b Fai
qd=u(1);
dqd=cos(t);
ddqd=-sin(t);

q=u(2);
dq=u(3);

e=qd-q;
de=dqd-dq;
r=de+Fai*e;

z=[e;de];
for j=1:1:node
    h(j)=exp(-norm(z-c(:,j))^2/(b*b));
end

Gama=100;
for i=1:1:node
sys(i)=Gama*h(i)*r;
end
function sys=mdlOutputs(t,x,u)
global node c b Fai
qd=u(1);
dqd=cos(t);
ddqd=-sin(t);

q=u(2);
dq=u(3);

e=qd-q;
de=dqd-dq;
r=de+Fai*e;

dqr=dqd+Fai*e;
ddqr=ddqd+Fai*de;

z=[e;de];
w=[x(1:node)]';

for j=1:1:node
    h(j)=exp(-norm(z-c(:,j))^2/(b*b));
end

fn=w*h';
Kv=110;

epN=0.20;bd=0.1;
v=-(epN+bd)*sign(r);
tol=fn+Kv*r-v;    

F=15*dq+0.3*sign(dq);
M=10;
f=M*ddqr+F;

fn_norm=norm(fn);
sys(1)=tol;
sys(2)=f;
sys(3)=fn;