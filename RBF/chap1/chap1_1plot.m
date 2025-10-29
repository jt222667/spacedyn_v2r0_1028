close all;

figure(1);
plot(t,y(:,1),'r',t,y(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('position signal');
legend('ideal position signal','position tracking');

figure(2);
plot(t,p(:,3),'r',t,p(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('estimation value');
legend('True value,m','estimation value');