close all;

figure(1);
subplot(211);
plot(t,xp(:,1),'r',t,xp(:,5),'k:','linewidth',2);
xlabel('time(s)');ylabel('x1 and its observer value');
legend('Practical x1','x1 estimation');
subplot(212);
plot(t,xp(:,2),'r',t,xp(:,6),'k:','linewidth',2);
xlabel('time(s)');ylabel('x2 and its observer value');
legend('Practical x2','x2 estimation');

figure(2);
subplot(211);
plot(t,F(:,1),'r',t,F(:,3),'k:','linewidth',2);
xlabel('time(s)');ylabel('fx and estimation');
legend('Practical fx','fx estimation');
subplot(212);
plot(t,F(:,2),'r',t,F(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('gx and estimation');
legend('Practical gx','gx estimation');