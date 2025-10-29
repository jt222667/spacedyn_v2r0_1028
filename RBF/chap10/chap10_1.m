%Discrete neural controller
clear all;
close all;
L=9;    %Hidden neural nets


c=[-2 -1.5 -1 -0.5 0 0.5 1 1.5 2;
   -2 -1.5 -1 -0.5 0 0.5 1 1.5 2];
b=2;
w=rand(L,1);   
w_1=w;

u_1=0;
x1_1=0;x1_2=0;
x2_1=0;
z=[0,0]';

Gama=0.01;rou=0.001;    


L*(1+rou)*Gama    %<=1/g1-1/k0
(L+rou)*Gama      %<=1.0

for k=1:1:10000
time(k)=k;
ym(k)=sin(pi/1000*k);

y(k)=x1_1;   %tol=1
e(k)=y(k)-ym(k);

M=2;
if M==1      %Linear model
x1(k)=x2_1;
x2(k)=u_1;
elseif M==2  %Nonlinear model
x1(k)=x2_1;
x2(k)=(x1(k)*x2_1*(x1(k)+2.5))/(1+x1(k)^2+x2_1^2)+u_1+0.1*u_1^3;
end

z(1)=x1(k);z(2)=x2(k);
for j=1:1:L
    h(j)=exp(-norm(z-c(:,j))^2/(2*b^2));
end
w=w_1-Gama*(h'*e(k)+rou*w_1);
wn(k)=norm(w);

u(k)=w'*h';

%u(k)=0.20*(ym(k)-x1(k));  %P control
x1_2=x1_1;
x1_1=x1(k);

x2_1=x2(k);
   
w_1=w;
u_1=u(k);
end
figure(1);
plot(time,ym,'r',time,x1,'k:','linewidth',2);
xlabel('k');ylabel('ym,y');
legend('Ideal position signal','Position tracking');
figure(2);
plot(time,u,'r','linewidth',2);
xlabel('k');ylabel('Control input');
figure(3);
plot(time,wn,'r','linewidth',2);
xlabel('k');ylabel('Weight Norm');