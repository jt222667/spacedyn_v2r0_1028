close all;

figure(1);
subplot(211);
plot(t,x(:,1),'r',t,x(:,3),'k:','linewidth',2);
xlabel('time(s)');ylabel('position tracking of x1 axis');
legend('Ideal position of x1','Position tracking of x1');
subplot(212);
plot(t,x(:,2),'r',t,x(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('position tracking of x2 axis');
legend('Ideal position of x2','Position tracking of x2');

figure(2);
subplot(211);
plot(t,dx(:,1),'r',t,dx(:,3),'k:','linewidth',2);
xlabel('time(s)');ylabel('velocity tracking of x1 axis');
legend('Ideal speed of x1','Speed tracking of x1');
subplot(212);
plot(t,dx(:,2),'r',t,dx(:,4),'k:','linewidth',2);
xlabel('time(s)');ylabel('velocity tracking of x2 axis');
legend('Ideal speed of x2','Speed tracking of x2');

figure(3);
plot(t,tol(:,1),'r',t,tol(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('Conrol input tol1 and tol2');
legend('Control input for link 1','Control input for link 2');

figure(4);
subplot(311);
plot(t,M(:,1),'r',t,M(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('M and estimated M');
legend('Ideal norm of Msx','Estimated norm of Mx');
subplot(312);
plot(t,C(:,1),'r',t,C(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('C and estimated C');
legend('Ideal norm of Cx','Estimated norm of Cx');
subplot(313);
plot(t,G(:,1),'r',t,G(:,2),'k:','linewidth',2);
xlabel('time(s)');ylabel('G and estimated G');
legend('Ideal norm of Gx','Estimated norm of Gx');

figure(5);
plot(x(:,1),x(:,2),'r','linewidth',2);
xlabel('x1 axis');ylabel('x2 axis');
hold on;
plot(x(:,3),x(:,4),'k:','linewidth',2);
xlabel('x1 axis');ylabel('x2 axis');
legend('Ideal trajectory','Tracking trajectory');