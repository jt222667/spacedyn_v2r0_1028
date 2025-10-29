%Discrete RBF control for two-link manipulators
clear all;
close all;

T=0.001;  %Sampling time
xk=[0 0 0 0];

tol1_1=0;
tol2_1=0;
ei=0;

node=5;
c_M=[-1 -0.5 0 0.5 1;    
     -1 -0.5 0 0.5 1];
c_C=[-1 -0.5 0 0.5 1;
     -1 -0.5 0 0.5 1;
     -1 -0.5 0 0.5 1;
     -1 -0.5 0 0.5 1];
c_G=[-1 -0.5 0 0.5 1;    
     -1 -0.5 0 0.5 1];
b=10;

W_M11_1=zeros(node,1);W_M12_1=zeros(node,1);
W_M21_1=zeros(node,1);W_M22_1=zeros(node,1);

W_C11_1=zeros(node,1);W_C12_1=zeros(node,1);
W_C21_1=zeros(node,1);W_C22_1=zeros(node,1);

W_G1_1=zeros(node,1);W_G2_1=zeros(node,1);

Hur=[5 0;0 5];
for k=1:1:5000
if mod(k,200)==1
   k
end
time(k) = k*T;

qd1(k)=sin(2*pi*k*T);
qd2(k)=sin(2*pi*k*T);
dqd1(k)=2*pi*cos(2*pi*k*T);
dqd2(k)=2*pi*cos(2*pi*k*T);
ddqd1(k)=-(2*pi)^2*sin(2*pi*k*T);
ddqd2(k)=-(2*pi)^2*sin(2*pi*k*T);
    
para=[tol1_1 tol2_1];        %D/A
tSpan=[0 T];

[t,xx]=ode45('chap9_3plant',tSpan,xk,[],para);  %A/D speed
xk = xx(length(xx),:);   %A/D position
q1(k)=xk(1); 
dq1(k)=xk(2); 
q2(k)=xk(3); 
dq2(k)=xk(4); 

q=[q1(k);q2(k)];
z=[q1(k);q2(k);dq1(k);dq2(k)];

e1(k)=qd1(k)-q1(k);
de1(k)=dqd1(k)-dq1(k); 
e2(k)=qd2(k)-q2(k);
de2(k)=dqd2(k)-dq2(k); 

e=[e1(k);e2(k)];
de=[de1(k);de2(k)];

r=de+Hur*e;
dqd=[dqd1(k);dqd2(k)];
dqr=dqd+Hur*e;
ddqd=[ddqd1(k);ddqd2(k)];
ddqr=ddqd+Hur*de;
for j=1:1:node
    h_M11(j)=exp(-norm(q-c_M(:,j))^2/(b^2));
    h_M21(j)=exp(-norm(q-c_M(:,j))^2/(b^2));
    h_M12(j)=exp(-norm(q-c_M(:,j))^2/(b^2));
    h_M22(j)=exp(-norm(q-c_M(:,j))^2/(b^2));
end
for j=1:1:node
    h_C11(j)=exp(-norm(z-c_C(:,j))^2/(b^2));
    h_C21(j)=exp(-norm(z-c_C(:,j))^2/(b^2));
    h_C12(j)=exp(-norm(z-c_C(:,j))^2/(b^2));
    h_C22(j)=exp(-norm(z-c_C(:,j))^2/(b^2));
end
for j=1:1:node
    h_G1(j)=exp(-norm(q-c_G(:,j))^2/(b^2));
    h_G2(j)=exp(-norm(q-c_G(:,j))^2/(b^2));
end

T_M11=5*eye(node);
T_M21=5*eye(node);
T_M12=5*eye(node);
T_M22=5*eye(node);
T_C11=10*eye(node);
T_C21=10*eye(node);
T_C12=10*eye(node);
T_C22=10*eye(node);
T_G1=5*eye(node);
T_G2=5*eye(node);

for i=1:1:node
    W_M11(i,1)=W_M11_1(i,1)+T*T_M11(i,i)*h_M11(i)*ddqr(1)*r(1);
    W_M21(i,1)=W_M21_1(i,1)+T*T_M21(i,i)*h_M21(i)*ddqr(1)*r(2);
    W_M12(i,1)=W_M12_1(i,1)+T*T_M12(i,i)*h_M12(i)*ddqr(2)*r(1);
    W_M22(i,1)=W_M22_1(i,1)+T*T_M22(i,i)*h_M22(i)*ddqr(2)*r(2);
    
    W_C11(i,1)=W_C11_1(i,1)+T*T_C11(i,i)*h_C11(i)*dqr(1)*r(1);
    W_C21(i,1)=W_C21_1(i,1)+T*T_C21(i,i)*h_C21(i)*dqr(1)*r(2);
    W_C12(i,1)=W_C12_1(i,1)+T*T_C12(i,i)*h_C12(i)*ddqr(2)*r(1);
    W_C22(i,1)=W_C22_1(i,1)+T*T_C22(i,i)*h_C22(i)*ddqr(2)*r(2);
    
    W_G1=W_G1_1+T*T_G1(i,i)*h_G1(i)*r(1);
    W_G2=W_G2_1+T*T_G2(i,i)*h_G2(i)*r(2);
end
MSNN_g=[W_M11'*h_M11' W_M12'*h_M12';
        W_M21'*h_M21' W_M22'*h_M22'];
GSNN_g=[W_G1'*h_G1';
        W_G2'*h_G2'];
CDNN_g=[W_C11'*h_C11' W_C12'*h_C12';
        W_C21'*h_C21' W_C22'*h_C22'];
    
tol_m=MSNN_g*ddqr+CDNN_g*dqr+GSNN_g;

Kp=[20 0;0 20];
Ki=[20 0;0 20];
Kr=[1.5 0;0 1.5];

Kp=[100 0;0 100];
Ki=[100 0;0 100];
Kr=[0.1 0;0 0.1];

ei=ei+e*T;
tol=tol_m+Kp*r+Kr*sign(r)+Ki*ei;
tol1(k)=tol(1);
tol2(k)=tol(2);

W_M11_1=W_M11;
W_M21_1=W_M21;
W_M12_1=W_M12;
W_M22_1=W_M22;
W_C11_1=W_C11;
W_C21_1=W_C21;
W_C12_1=W_C12;
W_C22_1=W_C22;
W_G1_1=W_G1;
W_G2_1=W_G2;

tol1_1=tol1(k);
tol2_1=tol2(k);
end
figure(1);
subplot(211);
plot(time,qd1,'r',time,q1,'k:','linewidth',2);
xlabel('time(s)'),ylabel('Position tracking of link 1');
legend('ideal position','position tracking');
subplot(212);
plot(time,qd2,'r',time,q2,'k:','linewidth',2);
xlabel('time(s)'),ylabel('Position tracking of link 2');
legend('ideal position','position tracking');
figure(2);
subplot(211);
plot(time,dqd1,'r',time,dq1,'k:','linewidth',2);
xlabel('time(s)'),ylabel('Speed tracking of link 1');
legend('ideal speed','speed tracking');
subplot(212);
plot(time,dqd2,'r',time,dq2,'k:','linewidth',2);
xlabel('time(s)'),ylabel('Speed tracking of link 2');
legend('ideal speed','speed tracking');
figure(3);
subplot(211);
plot(time,tol1,'r','linewidth',2);
xlabel('time(s)'),ylabel('Control input of link 1');
subplot(212);
plot(time,tol2,'r','linewidth',2);
xlabel('time(s)'),ylabel('Control input of link 2');