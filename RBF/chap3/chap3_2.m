%Model Reference Aapative RBF Control
clear all;
close all;
    
u_1=0;
y_1=0;
ym_1=0;

x=[0,0,0]';
c=[-3 -2 -1 0 1 2 3;
   -3 -2 -1 0 1 2 3;
   -3 -2 -1 0 1 2 3];
b=2;
w=rands(1,7);

xite=0.35;
alfa=0.05;
h=[0,0,0,0,0,0,0]';
 
c_1=c;c_2=c;
b_1=b;b_2=b;
w_1=w;w_2=w;

ts=0.001;
for k=1:1:3000
time(k)=k*ts;

yd(k)=0.50*sin(2*pi*k*ts);
ym(k)=0.6*ym_1+yd(k);

y(k)=(-0.1*y_1+u_1)/(1+y_1^2);  %Nonlinear plant

for j=1:1:7
    h(j)=exp(-norm(x-c(:,j))^2/(2*b^2));
end
u(k)=w*h;
      
ec(k)=ym(k)-y(k);
dyu(k)=sign((y(k)-y_1)/(u(k)-u_1));

d_w=0*w;
for j=1:1:7
    d_w(j)=xite*ec(k)*h(j)*dyu(k);
end
w=w_1+d_w+alfa*(w_1-w_2);
%Return of parameters   
u_1=u(k);
y_1=y(k);
ym_1=ym(k);
    
x(1)=yd(k);
x(2)=ec(k);
x(3)=y(k);   
   
w_2=w_1;w_1=w;
end
figure(1);
plot(time,ym,'r',time,y,'k:','linewidth',2);
xlabel('time(s)');ylabel('ym,y');
legend('Ideal position signal','Tracking position signal');
figure(2);
plot(time,u,'r','linewidth',2);
xlabel('time(s)');ylabel('Control input');