close all;

figure(1);
subplot(211);
plot(t,x(:,1),'r',t,x(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('position tracking');
legend('Ideal position signal','Position signal tracking');
subplot(212);
plot(t,x(:,2),'r',t,x(:,5),'k:','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking');
legend('Ideal speed signal','Speed signal tracking');

figure(2);
plot(t,tol(:,1),'k','linewidth',2);
xlabel('time(s)');ylabel('Contro input');
legend('Control input');

figure(3);
subplot(311);
plot(t,P(:,1),'r',t,P(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('M and MSNN');
legend('Ideal M','Estimated M');
subplot(312);
plot(t,P(:,2),'r',t,P(:,5),'k:','linewidth',2);
xlabel('time(s)');ylabel('C and CDNN');
legend('Ideal C','Estimated C');
subplot(313);
plot(t,P(:,3),'r',t,P(:,6),'k:','linewidth',2);
xlabel('time(s)');ylabel('G and GSNN');
legend('Ideal G','Estimated G');