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
global node c b lambd epc
lambd=5;
epc=0.25;
node=9;
sizes = simsizes;
sizes.NumContStates  = node;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 1;
sizes.NumInputs      = 3;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = zeros(1,9);
c= [-2 -1.5 -1 -0.5 0 0.5 1 1.5 2;
    -2 -1.5 -1 -0.5 0 0.5 1 1.5 2;
    -2 -1.5 -1 -0.5 0 0.5 1 1.5 2;
    -2 -1.5 -1 -0.5 0 0.5 1 1.5 2;
    -2 -1.5 -1 -0.5 0 0.5 1 1.5 2];
b=5;
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global node c b lambd epc
yd=sin(t);
dyd=cos(t);
ddyd=-sin(t);
x1=u(2);
x2=u(3);
e=x1-yd;
de=x2-dyd;

s=lambd*e+de;
v=-ddyd+lambd*de;
xi=[x1;x2;s;s/epc;v];

h=zeros(9,1);
for j=1:1:9
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b^2));
end

rou=0.005;
Gama=500*eye(node);
W=[x(1) x(2) x(3) x(4) x(5) x(6) x(7) x(8) x(9)]';
S=-Gama*(h*s+rou*W);

for i=1:1:node
    sys(i)=S(i);
end
function sys=mdlOutputs(t,x,u)
global node c b lambd epc
yd=sin(t);
dyd=cos(t);
ddyd=-sin(t);
x1=u(2);
x2=u(3);
e=x1-yd;
de=x2-dyd;
s=lambd*e+de;
v=-ddyd+lambd*de;

xi=[x1;x2;s;s/epc;v];

W=[x(1) x(2) x(3) x(4) x(5) x(6) x(7) x(8) x(9)]';
h=zeros(9,1);
for j=1:1:9
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b^2));
end
betaU=150;
ut=1/betaU*W'*h;

sys(1)=ut;