close all;

figure(1);
subplot(211);
plot(t,x(:,1),'r',t,x(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('Position tracking');
legend('ideal position','position tracking');
subplot(212);
plot(t,cos(t),'r',t,x(:,3),'k:','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking');
legend('ideal speed','speed tracking');

figure(2);
plot(t,f(:,1),'r',t,f(:,2),'b','linewidth',2);
xlabel('time(s)');ylabel('f and fn');
legend('Practical uncertainties','Estimation uncertainties');