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
global c b m kv kp
sizes = simsizes;
sizes.NumContStates  = m;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;
sizes.NumInputs      = 3;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
x0  = zeros(1,m);
str = [];
ts  = [0 0];

m=19;
if m==5
c=1/2*[-2 -1 0 1 2;
       -2 -1 0 1 2];
elseif m==19
c=1/9*[-9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9;
       -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9];
end
b=5;

alfa=3;
kp=alfa^2;
kv=2*alfa;
function sys=mdlDerivatives(t,x,u)
global c b m kv kp
qd=u(1);
dqd=cos(t);
ddqd=-sin(t);

q=u(2);
dq=u(3);

e=q-qd;
de=dq-dqd;

A=[0 1;-kp -kv];
D=10;
B=[0 1/D]';

Q=50*eye(2);
P=lyap(A',Q);
eig(P);

if m==5
th=[x(1) x(2) x(3) x(4) x(5)]';
elseif m==19
th=[x(1) x(2) x(3) x(4) x(5) x(6) x(7) x(8) x(9) x(10) x(11) x(12) x(13) x(14) x(15) x(16) x(17) x(18) x(19)]';
end

xi=[e;de];

h=zeros(m,1);
for j=1:1:m
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b^2));
end
gama=200;

S1=1;
if S1==1       % First adaptive Law
    S=gama*h*xi'*P*B;
elseif S1==2   % Secod adaptive Law with UUB
    k1=0.001;
    S=gama*h*xi'*P*B+k1*gama*norm(xi)*th;
end
S=S';
for i=1:1:m
    sys(i)=S(i);
end

function sys=mdlOutputs(t,x,u)
global c b m kv kp
qd=u(1);
dqd=cos(t);
ddqd=-sin(t);

q=u(2);
dq=u(3);

e=q-qd;
de=dq-dqd;

M=10;

tol1=M*(ddqd-kv*de-kp*e);

xi=[e;de];
h=zeros(m,1);
for j=1:1:m
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b^2));
end

d=-15*dq-30*sign(dq);
f=d;

S=3;
if S==1               %Nominal model based controller
    fn=0;
    tol=tol1;        
elseif S==2           %Modified computed torque controller
    fn=0;
    tol2=-f;
    tol=tol1+tol2;
elseif S==3           %RBF compensated controller
    if m==5
    th=[x(1) x(2) x(3) x(4) x(5)]';
    elseif m==19
    th=[x(1) x(2) x(3) x(4) x(5) x(6) x(7) x(8) x(9) x(10) x(11) x(12) x(13) x(14) x(15) x(16) x(17) x(18) x(19)]';
end
    fn=th'*h;
    tol2=-fn;
    tol=tol1+1*tol2;
end

sys(1)=tol;
sys(2)=f;
sys(3)=fn;