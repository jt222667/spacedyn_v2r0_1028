function [sys,x0,str,ts] = obser(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u);
case 3,
    sys=mdlOutputs(t,x,u);
case {1,2,4,9}
    sys=[];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
global c b
sizes = simsizes;
sizes.NumContStates  = 21;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 4;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0=zeros(1,21);
str=[];
ts=[];
c1=6/3*[-3 -2 -1 0 1 2 3];
c2=8/3*[-3 -2 -1 0 1 2 3];
c=[c1;c2];
b=15;
function sys=mdlDerivatives(t,x,u)
global c b
y=u(1);
ut=u(2);
x1p=u(3);
x2p=u(4);
xp=[x1p x2p]';
yp=x1p;
ye=y-yp;

h=zeros(7,1);
for j=1:1:7
    h(j)=exp(-norm(xp-c(:,j))^2/(2*b^2));
end
h_bar=x(15:1:21);

F1=150000*eye(7);
F2=150000*eye(7);

k1=0.01;k2=0.01;
W1=[x(1) x(2) x(3) x(4) x(5) x(6) x(7)];
W2=[x(8) x(9) x(10) x(11) x(12) x(13) x(14)];

dW1=F1*h_bar*ye-k1*F1*abs(ye)*W1';
dW2=F2*h_bar*ye*ut-k2*F2*abs(ye)*W2';
for i=1:1:7
    sys(i)=dW1(i);
    sys(i+7)=dW2(i);
end
for i=15:1:21
    sys(i)=h(i-14)-0.5*x(i);
end

function sys=mdlOutputs(t,x,u)
global c b
W1=[x(1) x(2) x(3) x(4) x(5) x(6) x(7)];
W2=[x(8) x(9) x(10) x(11) x(12) x(13) x(14)];
h_bar=x(15:1:21);

fxp=W1*h_bar;
gxp=W2*h_bar;

sys(1)=fxp;
sys(2)=gxp;