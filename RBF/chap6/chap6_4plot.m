close all;

figure(1);
subplot(211);
plot(t,qd(:,1),'r',t,q(:,1),'k:','linewidth',2);
xlabel('time(s)');ylabel('Position tracking for link 1');
legend('ideal position for link 1','position tracking for link 1');
subplot(212);
plot(t,qd(:,4),'r',t,q(:,3),'k:','linewidth',2);
xlabel('time(s)');ylabel('Position tracking for link 2');
legend('ideal position for link 2','position tracking for link 2');

figure(2);
subplot(211);
plot(t,qd(:,2),'r',t,q(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking for link 1');
legend('ideal speed for link 1','speed tracking for link 1');
subplot(212);
plot(t,qd(:,5),'r',t,q(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking for link 2');
legend('ideal speed for link 2','speed tracking for link 2');

figure(3);
subplot(211);
plot(t,tol1(:,1),'k','linewidth',2);
xlabel('time(s)');ylabel('control input of link 1');
subplot(212);
plot(t,tol2(:,1),'k','linewidth',2);
xlabel('time(s)');ylabel('control input of link 2');

figure(4);
plot(t,f(:,1),'r',t,f(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('f and fn');
legend('ideal fx','estimation of fx');