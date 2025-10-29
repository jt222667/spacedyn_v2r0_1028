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
global node c_M c_C c_G b
node=5;
c_M=[-1 -0.5 0 0.5 1;    
     -1 -0.5 0 0.5 1];
c_G=[-1 -0.5 0 0.5 1;    
     -1 -0.5 0 0.5 1];
c_C=[-1 -0.5 0 0.5 1;
     -1 -0.5 0 0.5 1;
     -1 -0.5 0 0.5 1; 
     -1 -0.5 0 0.5 1];
b=10;
sizes = simsizes;
sizes.NumContStates  = 10*node;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 5;
sizes.NumInputs      = 15;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = zeros(1,10*node);
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global node c_M c_C c_G b
qd1=u(1);
d_qd1=u(2);
dd_qd1=u(3);
qd2=u(4);
d_qd2=u(5);
dd_qd2=u(6);

q1=u(7);
d_q1=u(8);
q2=u(9);
d_q2=u(10);

q=[q1;q2];
for j=1:1:node
    h_M11(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
    h_M12(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
    h_M21(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
    h_M22(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
end

for j=1:1:node
    h_G1(j)=exp(-norm(q-c_G(:,j))^2/(b*b));
    h_G2(j)=exp(-norm(q-c_G(:,j))^2/(b*b));
end

z=[q1;q2;d_q1;d_q2];
for j=1:1:node
    h_C11(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
    h_C12(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
    h_C21(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
    h_C22(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
end

W_M11=[x(1:node)]';
W_M12=[x(node+1:node*2)]';
W_M21=[x(node*2+1:node*3)]';
W_M22=[x(node*3+1:node*4)]';

T_M11=5*eye(node);
T_M12=5*eye(node);
T_M21=5*eye(node);
T_M22=5*eye(node);

e1=qd1-q1;
e2=qd2-q2;
de1=d_qd1-d_q1;
de2=d_qd2-d_q2;
e=[e1;e2];
de=[de1;de2];
Fai=5*eye(2);
r=de+Fai*e;

dqd=[d_qd1;d_qd2];
dqr=dqd+Fai*e;
ddqd=[dd_qd1;dd_qd2];
ddqr=ddqd+Fai*de;

for i=1:1:node
    sys(i)=T_M11(i,i)*h_M11(i)*ddqr(1)*r(1);
    sys(i+node)=T_M12(i,i)*h_M12(i)*ddqr(2)*r(1);
    sys(i+node*2)=T_M21(i,i)*h_M21(i)*ddqr(1)*r(2);
    sys(i+node*3)=T_M22(i,i)*h_M22(i)*ddqr(2)*r(2);
end

W_G1=[x(node*4+1:node*5)]';
W_G2=[x(node*5+1:node*6)]';
T_G1=10*eye(node);
T_G2=10*eye(node);
for i=1:1:node
    sys(i+node*4)=T_G1(i,i)*h_G1(i)*r(1);
    sys(i+node*5)=T_G2(i,i)*h_G2(i)*r(2);
end

W_C11=[x(node*6+1:node*7)]';
W_C12=[x(node*7+1:node*8)]';
W_C21=[x(node*8+1:node*9)]';
W_C22=[x(node*9+1:node*10)]';

T_C11=10*eye(node);
T_C12=10*eye(node);
T_C21=10*eye(node);
T_C22=10*eye(node);

for i=1:1:node
    sys(i+node*6)=T_C11(i,i)*h_C11(i)*dqr(1)*r(1);
    sys(i+node*7)=T_C12(i,i)*h_C12(i)*ddqr(2)*r(1);
    sys(i+node*8)=T_C21(i,i)*h_C21(i)*dqr(1)*r(2);
    sys(i+node*9)=T_C22(i,i)*h_C22(i)*ddqr(2)*r(2);
end

function sys=mdlOutputs(t,x,u)
global node c_M c_C c_G b
qd1=u(1);
d_qd1=u(2);
dd_qd1=u(3);
qd2=u(4);
d_qd2=u(5);
dd_qd2=u(6);

q1=u(7);
d_q1=u(8);
q2=u(9);
d_q2=u(10);

q=[q1;q2];
for j=1:1:node
    h_M11(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
    h_M12(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
    h_M21(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
    h_M22(j)=exp(-norm(q-c_M(:,j))^2/(b*b));
end

for j=1:1:node
    h_G1(j)=exp(-norm(q-c_G(:,j))^2/(b*b));
    h_G2(j)=exp(-norm(q-c_G(:,j))^2/(b*b));
 end

z=[q1;q2;d_q1;d_q2];
for j=1:1:node
    h_C11(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
    h_C12(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
    h_C21(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
    h_C22(j)=exp(-norm(z-c_C(:,j))^2/(b*b));
end

W_M11=[x(1:node)]';
W_M12=[x(node+1:node*2)]';
W_M21=[x(node*2+1:node*3)]';
W_M22=[x(node*3+1:node*4)]';

MSNN=[W_M11*h_M11' W_M12*h_M12';
      W_M21*h_M21' W_M22*h_M22'];
Mm=norm(MSNN);

W_G1=[x(node*4+1:node*5)]';
W_G2=[x(node*5+1:node*6)]';

GSNN=[W_G1*h_G1';
      W_G2*h_G2'];
Gm=norm(GSNN);
    
W_C11=[x(node*6+1:node*7)]';
W_C12=[x(node*7+1:node*8)]';
W_C21=[x(node*8+1:node*9)]';
W_C22=[x(node*9+1:node*10)]';
CDNN=[W_C11*h_C11' W_C12*h_C12';
      W_C21*h_C21' W_C22*h_C22'];
Cm=norm(CDNN);

e1=qd1-q1;
e2=qd2-q2;
de1=d_qd1-d_q1;
de2=d_qd2-d_q2;
e=[e1;e2];
de=[de1;de2];
Fai=5*eye(2);
r=de+Fai*e;

dqd=[d_qd1;d_qd2];
dqr=dqd+Fai*e;
ddqd=[dd_qd1;dd_qd2];
ddqr=ddqd+Fai*de;

tolm=MSNN*ddqr+CDNN*dqr+GSNN;

Kr=0.10;
tolr=Kr*sign(r);

Kp=100*eye(2);
Ki=100*eye(2);

I=[u(14);u(15)];
tol=tolm+Kp*r+Ki*I+tolr;

sys(1)=tol(1);
sys(2)=tol(2);
sys(3)=Gm;
sys(4)=Mm;
sys(5)=Cm;