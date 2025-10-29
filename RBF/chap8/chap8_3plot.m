close all;
abc=t*0.+1;
figure(1);
subplot(211);
plot(t,y(:,2),'b',t,y(:,1),'r:','linewidth',2);
xlabel('时间/sec');ylabel('位置跟踪 /Rad');
legend('x_1','x_1_d');
subplot(212);
plot(t,y(:,2)-y(:,1),'r','linewidth',2);
xlabel('时间/sec');ylabel('跟踪误差 /Rad');

%%%%%%%%%%%%%%%%%%%
figure(2);
plot(t,ut(:,1),'r','linewidth',2);
xlabel('时间/sec');ylabel('控制力矩 /N.m');
%%%%%%%%%%%%%%%%
figure(3);
subplot(211);
plot(t,a1(:,1),'r',t,0.025*abc,':','linewidth',2);
xlabel('时间/sec');ylabel('参数1/a_1估计');
legend('估计值','实际值');
subplot(212);
plot(t,a2(:,1),'r',t,abc,':','linewidth',2);
xlabel('时间/sec');ylabel('参数1/a_2估计');
legend('估计值','实际值');
figure(4);
subplot(211);
plot(t,f1(:,1),'r',t,-1/8*sin(x1(:,1))-x1(:,1),'--','linewidth',2);
xlabel('时间/sec');ylabel('函数1/a_1·f_1估计');
legend('估计值','实际值');
subplot(212);
plot(t,f2(:,1),'r',t,-40*(x3(:,1)-x1(:,1)),'--','linewidth',2);
xlabel('时间/sec');ylabel('函数1/a_2·f_2估计');
legend('估计值','实际值');