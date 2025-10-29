close all;

figure(1);
subplot(211);
plot(t,y(:,2),'r',t,y(:,1),'b--','linewidth',2);
xlabel('time (sec)');ylabel('{\itx}_1 and {\itx}_1_{\itd} (deg)');
axis([0 30 -10 10])
legend('ideal position signal', 'tracking signal');
subplot(212);
plot(t,y(:,2)-y(:,1),'r','linewidth',2);
xlabel('Time (sec)');ylabel('{\itS}_1 (deg)');

figure(2);
plot(t,ut(:,1),'r','linewidth',2);
xlabel('Time (sec)');ylabel('{\itu} (deg)');

figure(3);
subplot(211);
plot(t,a1(:,1),'r','linewidth',2);
xlabel('Time (sec)');ylabel('Estimation of 1/{\ita}_1');
axis([0 30 0 1.5])
subplot(212);
plot(t,a3(:,1),'r','linewidth',2);
xlabel('Time (sec)');ylabel('Estimation of 1/{\ita}_3');

figure(4);
subplot(211);
plot(t,x2(:,1),'r','linewidth',2);
xlabel('Time (sec)');ylabel('{\itx}_2 (deg)');
subplot(212);
plot(t,x3(:,1),'r','linewidth',2);
xlabel('Time (sec)');ylabel('{\itx}_3 (deg/s)');

figure(5);
plot(t,f1(:,1),'r',t,-9.8/200*cos(x1(:,1)*pi/180)-0.1,'b--','linewidth',2);
xlabel('Time (sec)');ylabel('f_1/a_1');
legend('f_1/a_1', 'estimation of f_1/a_1');

figure(6);
plot(t,f2(:,1),'r',t,9.8/200*cos(x1(:,1)*pi/180)+0.1-x2(:,1),'b--','linewidth',2);
xlabel('Time (sec)');ylabel('f_2');
legend('f_2', 'estimation of f_2');

figure(7);
plot(t,f3(:,1),'r',t,0.1*x2(:,1)-0.02*x3(:,1),'b--','linewidth',2);
xlabel('Time (sec)');ylabel('f_3/a_3');
legend('f_3/a_3', 'estimation of f_3/a_3');