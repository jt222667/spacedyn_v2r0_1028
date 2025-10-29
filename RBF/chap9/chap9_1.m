clear all;
close all;
ts=0.001;       %Sampling time

x_1=0.5;

for k=1:1:10000   %dx=10*sint*x
    t(k)=k*ts;
    k1=ts*10*sin(t(k))*x_1;
    k2=ts*10*sin(t(k))*(x_1+1/3*k1);
    k3=ts*10*sin(t(k))*(x_1+1/6*k1+1/6*k2);
    k4=ts*10*sin(t(k))*(x_1+1/8*k1+3/8*k3);
    k5=ts*10*sin(t(k))*(x_1+1/2*k1-3/2*k3+2*k4);
    x(k)=x_1+1/6*(k1+4*k4+k5);

    x_1=x(k);
end
figure(1);
plot(t,x,'r','linewidth',2);
xlabel('time(s)');ylabel('x');