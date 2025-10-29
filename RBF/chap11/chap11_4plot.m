close all;

figure(1);
subplot(211);
plot(t,y(:,1),'r',t,y(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('Position tracking');
legend('xd','x1');
subplot(212);
plot(t,cos(t),'r',t,y(:,3),'k:','linewidth',2);
xlabel('time(s)');ylabel('Speed tracking');
legend('dxd','x2');

figure(2);
subplot(211);
plot(t,y(:,2),'r',t,y(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('x1 and its observer value');
legend('x1','x1p');
subplot(212);
plot(t,y(:,3),'r',t,y(:,5),'k:','linewidth',2);
xlabel('time(s)');ylabel('x2 and its observer value');
legend('x2','x2p');

figure(3);
subplot(211);
plot(t,F(:,1),'r',t,F(:,3),'k:','linewidth',2);
xlabel('time(s)');ylabel('fx and estimation');
legend('Practical fx','fx estimation');
subplot(212);
plot(t,F(:,2),'r',t,F(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('gx and estimation');
legend('Practical gx','gx estimation');

figure(4);
plot(t,ut,'r','linewidth',2);
xlabel('time(s)');ylabel('Control input');