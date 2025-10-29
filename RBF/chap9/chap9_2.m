%Discrete RBF control for Motor
clear all;
close all;
ts=0.001;  %Sampling time

node=5;  %Number of neural nets in hidden layer
gama=100;

c=0.5*[-2 -1 0 1 2;
       -2 -1 0 1 2];
b=1.5*ones(5,1);
h=zeros(node,1);

alfa=3;
kp=alfa^2;
kv=2*alfa;
q_1=0;dq_1=0;tol_1=0;

xk=[0 0];
w_1=0.1*ones(node,1);

A=[0   1;
  -kp -kv];
B=[0;1];
Q=[50 0;
   0 50];
P=lyap(A',Q);
eig(P);
k1=0.001;
for k=1:1:10000
time(k)=k*ts;

qd(k)=sin(k*ts);
dqd(k)=cos(k*ts);
ddqd(k)=-sin(k*ts);

tSpan=[0 ts];
para=tol_1;            %D/A
[t,xx]=ode45('chap9_2plant',tSpan,xk,[],para);   %Plant
xk=xx(length(xx),:);   %A/D

q(k)=xk(1); 
%dq(k)=xk(2);
dq(k)=(q(k)-q_1)/ts;
ddq(k)=(dq(k)-dq_1)/ts;

e(k)=q(k)-qd(k);
de(k)=dq(k)-dqd(k); 

xi=[e(k);de(k)];
for i=1:1:node
    S=2;
    if S==1
     w(i,1)=w_1(i,1)+ts*(gama*h(i)*xi'*P*B+k1*gama*norm(xi)*w_1(i,1)); %Adaptive law
    elseif S==2  
        k1=ts*(gama*h(i)*xi'*P*B+k1*gama*norm(xi)*w_1(i,1));
        k2=ts*(gama*h(i)*xi'*P*B+k1*gama*norm(xi)*(w_1(i,1)+1/3*k1));
        k3=ts*(gama*h(i)*xi'*P*B+k1*gama*norm(xi)*(w_1(i,1)+1/6*k1+1/6*k2));
        k4=ts*(gama*h(i)*xi'*P*B+k1*gama*norm(xi)*(w_1(i,1)+1/8*k1+3/8*k3));
        k5=ts*(gama*h(i)*xi'*P*B+k1*gama*norm(xi)*(w_1(i,1)+1/2*k1-3/2*k3+2*k4));
        w(i,1)=w_1(i,1)+1/6*(k1+4*k4+k5);
    end
end
h=zeros(5,1);
for j=1:1:5
    h(j)=exp(-norm(xi-c(:,j))^2/(2*b(j)*b(j)));
end
fn(k)=w'*h;
M=10;

tol1(k)=M*(ddqd(k)-kv*de(k)-kp*e(k));

d(k)=-15*dq(k)-30*sign(dq(k));
f(k)=d(k);

F=3;
if F==1               %No compensation
    fn(k)=0;
    tol(k)=tol1(k);        
elseif F==2           %Modified computed torque controller
    fn(k)=0;
    tol2(k)=-f(k);
    tol(k)=tol1(k)+tol2(k);
elseif F==3           %RBF compensated controller
    tol2(k)=-fn(k);
    tol(k)=tol1(k)+1*tol2(k);
end
q_1=q(k);
dq_1=dq(k);
w_1=w;
tol_1=tol(k);
end
figure(1);
subplot(211);
plot(time,qd,'r',time,q,'k:','linewidth',2);
xlabel('time(s)');ylabel('Position tracking');
legend('ideal position','position tracking');
subplot(212);
plot(time,dqd,'r',time,dq,'k:','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking');
legend('ideal speed','speed tracking');

figure(2);
plot(time,tol,'r','linewidth',2);
xlabel('time(s)'),ylabel('Control input of single link');
if F==2|F==3
    figure(3);
    plot(time,f,'r',time,fn,'k:','linewidth',2);
    xlabel('time(s)'),ylabel('f and fn');
    legend('Practical uncertainties','Estimation uncertainties');
end