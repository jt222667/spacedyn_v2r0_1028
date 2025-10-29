close all;
abc=t*0.+1;
figure(1);
subplot(211);
plot(t,y(:,2),'b',t,y(:,1),'r:','linewidth',2);
xlabel('ʱ��/sec');ylabel('λ�ø��� /Rad');
legend('x_1','x_1_d');
subplot(212);
plot(t,y(:,2)-y(:,1),'r','linewidth',2);
xlabel('ʱ��/sec');ylabel('������� /Rad');

%%%%%%%%%%%%%%%%%%%
figure(2);
plot(t,ut(:,1),'r','linewidth',2);
xlabel('ʱ��/sec');ylabel('�������� /N.m');
%%%%%%%%%%%%%%%%
figure(3);
subplot(211);
plot(t,a1(:,1),'r',t,0.025*abc,':','linewidth',2);
xlabel('ʱ��/sec');ylabel('����1/a_1����');
legend('����ֵ','ʵ��ֵ');
subplot(212);
plot(t,a2(:,1),'r',t,abc,':','linewidth',2);
xlabel('ʱ��/sec');ylabel('����1/a_2����');
legend('����ֵ','ʵ��ֵ');
figure(4);
subplot(211);
plot(t,f1(:,1),'r',t,-1/8*sin(x1(:,1))-x1(:,1),'--','linewidth',2);
xlabel('ʱ��/sec');ylabel('����1/a_1��f_1����');
legend('����ֵ','ʵ��ֵ');
subplot(212);
plot(t,f2(:,1),'r',t,-40*(x3(:,1)-x1(:,1)),'--','linewidth',2);
xlabel('ʱ��/sec');ylabel('����1/a_2��f_2����');
legend('����ֵ','ʵ��ֵ');