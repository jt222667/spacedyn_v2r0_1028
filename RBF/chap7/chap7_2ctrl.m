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
global node c_M c_C c_G b Fai
node=7;
c_M=[-1.5 -1 -0.5 0 0.5 1 1.5];
c_G=[-1.5 -1 -0.5 0 0.5 1 1.5];
c_C=[-1.5 -1 -0.5 0 0.5 1 1.5;
     -1.5 -1 -0.5 0 0.5 1 1.5];
b=20;

Fai=5;

sizes = simsizes;
sizes.NumContStates  = 3*node;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 4;
sizes.NumInputs      = 9;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = zeros(1,3*node);
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global node c_M c_C c_G b Fai
qd=u(1);
dqd=u(2);
ddqd=u(3);

q=u(4);
dq=u(5);

for j=1:1:node
    h_M(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
end
for j=1:1:node
    h_G(j)=exp(-norm(q-c_G(:,j))^2/(b*b));
end

z=[q;dq];
for j=1:1:node
    h_C(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
end
e=qd-q;
de=dqd-dq;
r=de+Fai*e;
dqr=dqd+Fai*e;
ddqr=ddqd+Fai*de;

T_M=100;
for i=1:1:node
    sys(i)=T_M*h_M(i)*ddqr*r;
end
T_C=100;
for i=1:1:node
    sys(2*node+i)=T_C*h_C(i)*dqr*r;
end
T_G=100;
for i=1:1:node
    sys(node+1)=T_G*h_G(i)*r;
end

function sys=mdlOutputs(t,x,u)
global node c_M c_C c_G b Fai
qd=u(1);
dqd=u(2);
ddqd=u(3);

q=u(4);
dq=u(5);

for j=1:1:node
    h_M(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
end

for j=1:1:node
    h_G(j)=exp(-norm(q-c_G(:,j))^2/(b*b));
end

z=[q;dq];
for j=1:1:node
    h_C(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
end

W_M=x(1:node)';
MSNN=W_M*h_M';
W_C=x(2*node+1:3*node)';
CDNN=W_C*h_C';
W_G=x(node+1:2*node)';
GSNN=W_G*h_G';
    
e=qd-q;
de=dqd-dq;

r=de+Fai*e;

dqr=dqd+Fai*e;
ddqr=ddqd+Fai*de;

tolm=MSNN*ddqr+CDNN*dqr+GSNN;

Kr=0.10;
tolr=Kr*sign(r);

Kp=15;
Ki=15;

I=u(9);
tol=tolm+Kp*r+Ki*I+tolr;

sys(1)=tol(1);
sys(2)=MSNN;
sys(3)=CDNN;
sys(4)=GSNN;