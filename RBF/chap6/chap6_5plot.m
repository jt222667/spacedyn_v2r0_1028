close all;

figure(1);
subplot(211);
plot(t,yd(:,1),'r',t,y(:,1),'k:','linewidth',2);
xlabel('time(s)');ylabel('position signal');
legend('ideal position signal','position tracking');
subplot(212);
plot(t,yd(:,2),'r',t,y(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking');
legend('ideal speed signal','speed tracking');

figure(2);
subplot(211);
plot(t,yd(:,1)-y(:,1),'k','linewidth',2);
xlabel('time(s)');ylabel('position signal error');
legend('position tracking error');
subplot(212);
plot(t,yd(:,2)-y(:,2),'k','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking error');
legend('speed tracking error');

figure(3);
plot(t,y(:,3),'r',t,u(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('F and Estimated F');
legend('Practical Friction','Estimated Friction');