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
global node c_M c_C c_G b ce
node=7;
c_M=zeros(2,node);
c_G=zeros(2,node);
c_C=zeros(4,node);

c_M=[0.25 0.5 0.75 1 1.25 1.5 1.75;
     0.25 0.5 0.75 1 1.25 1.5 1.75];
c_G=[0.25 0.5 0.75 1 1.25 1.5 1.75;
     0.25 0.5 0.75 1 1.25 1.5 1.75];
c_C=[0.25 0.5 0.75 1 1.25 1.5 1.75;
     0.25 0.5 0.75 1 1.25 1.5 1.75;
     -1.5  -1 -0.5 0 0.5  1.0 1.50;
     -1.5  -1 -0.5 0 0.5  1.0 1.50];
b=10;
ce=15.0;
sizes = simsizes;
sizes.NumContStates  = 10*node;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 5;
sizes.NumInputs      = 10;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys = simsizes(sizes);
x0  = zeros(1,10*node);
str = [];
ts  = [];
function sys=mdlDerivatives(t,x,u)
global node c_M c_C c_G b ce
xd1=u(1);
d_xd1=u(2);
dd_xd1=u(3);
xd2=u(4);
d_xd2=u(5);
dd_xd2=u(6);

x1=u(7);
d_x1=u(8);
x2=u(9);
d_x2=u(10);

xx=[x1;x2];
for j=1:1:node
    h_M11(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
    h_M12(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
    h_M21(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
    h_M22(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
end

for j=1:1:node
    h_G1(j)=exp(-norm(xx-c_G(:,j))^2/(b*b));
    h_G2(j)=exp(-norm(xx-c_G(:,j))^2/(b*b));
end

z=[x1;x2;d_x1;d_x2];
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

e1=xd1-x1;
e2=xd2-x2;
de1=d_xd1-d_x1;
de2=d_xd2-d_x2;
e=[e1;e2];
de=[de1;de2];
Hur=ce*eye(2);
r=de+Hur*e;

dxd=[d_xd1;d_xd2];
dxr=dxd+Hur*e;
ddxd=[dd_xd1;dd_xd2];
ddxr=ddxd+Hur*de;

T_M11=2*eye(node);
T_M12=2*eye(node);
T_M21=2*eye(node);
T_M22=2*eye(node);
for i=1:1:node
    sys(i)=T_M11(i,i)*h_M11(i)*ddxr(1)*r(1);
    sys(i+node)=T_M12(i,i)*h_M12(i)*ddxr(2)*r(1);
    sys(i+node*2)=T_M21(i,i)*h_M21(i)*ddxr(1)*r(2);
    sys(i+node*3)=T_M22(i,i)*h_M22(i)*ddxr(2)*r(2);
end

W_G1=[x(node*4+1:node*5)]';
W_G2=[x(node*5+1:node*6)]';
T_G1=5*eye(node);
T_G2=5*eye(node);
for i=1:1:node
    sys(i+node*4)=T_G1(i,i)*h_G1(i)*r(1);
    sys(i+node*5)=T_G2(i,i)*h_G2(i)*r(2);
end

W_C11=[x(node*6+1:node*7)]';
W_C12=[x(node*7+1:node*8)]';
W_C21=[x(node*8+1:node*9)]';
W_C22=[x(node*9+1:node*10)]';

T_C11=0.5*eye(node);
T_C12=0.5*eye(node);
T_C21=0.5*eye(node);
T_C22=0.5*eye(node);

for i=1:1:node
    sys(i+node*6)=T_C11(i,i)*h_C11(i)*dxr(1)*r(1);
    sys(i+node*7)=T_C12(i,i)*h_C12(i)*ddxr(2)*r(1);
    sys(i+node*8)=T_C21(i,i)*h_C21(i)*dxr(1)*r(2);
    sys(i+node*9)=T_C22(i,i)*h_C22(i)*ddxr(2)*r(2);
end

function sys=mdlOutputs(t,x,u)
global node c_M c_C c_G b ce
xd1=u(1);
d_xd1=u(2);
dd_xd1=u(3);
xd2=u(4);
d_xd2=u(5);
dd_xd2=u(6);

x1=u(7);
d_x1=u(8);
x2=u(9);
d_x2=u(10);

xx=[x1;x2];
for j=1:1:node
    h_M11(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
    h_M12(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
    h_M21(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
    h_M22(j)=exp(-norm(xx-c_M(:,j))^2/(b*b));
end

for j=1:1:node
    h_G1(j)=exp(-norm(xx-c_G(:,j))^2/(b*b));
    h_G2(j)=exp(-norm(xx-c_G(:,j))^2/(b*b));
 end

z=[x1;x2;d_x1;d_x2];
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

MSNN_g=[W_M11*h_M11' W_M12*h_M12';
        W_M21*h_M21' W_M22*h_M22'];
norm_Mp=norm(MSNN_g);

W_G1=[x(node*4+1:node*5)]';
W_G2=[x(node*5+1:node*6)]';

GSNN_g=[W_G1*h_G1';
        W_G2*h_G2'];
norm_Gp=norm(GSNN_g);
    
W_C11=[x(node*6+1:node*7)]';
W_C12=[x(node*7+1:node*8)]';
W_C21=[x(node*8+1:node*9)]';
W_C22=[x(node*9+1:node*10)]';

CDNN_g=[W_C11*h_C11' W_C12*h_C12';
        W_C21*h_C21' W_C22*h_C22'];
norm_Cp=norm(CDNN_g);

e1=xd1-x1;
e2=xd2-x2;
de1=d_xd1-d_x1;
de2=d_xd2-d_x2;
e=[e1;e2];
de=[de1;de2];
Hur=ce*eye(2);
r=de+Hur*e;

dxd=[d_xd1;d_xd2];
dxr=dxd+Hur*e;
ddxd=[dd_xd1;dd_xd2];
ddxr=ddxd+Hur*de;

Ks=0.5;
K=30*eye(2);
Fx=MSNN_g*ddxr+CDNN_g*dxr+GSNN_g+K*r+Ks*sign(r);

sys(1)=Fx(1);
sys(2)=Fx(2);
sys(3)=norm_Mp;
sys(4)=norm_Cp;
sys(5)=norm_Gp;