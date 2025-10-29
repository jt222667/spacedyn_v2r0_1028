function dx=Plant(t,x,flag,para)
%%%%%%%%%%%%%% x(1)=q1; x(2)=dq1; x(3)=q2; x(4)=dq2;%%%%%%%%%%%%
dx=zeros(4,1);

p=[2.9 0.76 0.87 3.04 0.87];
g=9.8;

M0=[p(1)+p(2)+2*p(3)*cos(x(3)) p(2)+p(3)*cos(x(3));
    p(2)+p(3)*cos(x(3)) p(2)];
C0=[-p(3)*x(4)*sin(x(3)) -p(3)*(x(2)+x(4))*sin(x(3));
     p(3)*x(2)*sin(x(3))  0];
G0=[p(4)*g*cos(x(1))+p(5)*g*cos(x(1)+x(3));
    p(5)*g*cos(x(1)+x(3))];

tol=para(1:2);
dq=[x(2);x(4)];

ddq=inv(M0)*(tol'-C0*dq-G0);
%%%%%%% dx(1)=dq1; dx(2)=ddq1; dx(3)=dq2; dx(4)=ddq2;%%%%%%%%%%%%%
dx(1)=x(2);
dx(2)=ddq(1);
dx(3)=x(4);
dx(4)=ddq(2);