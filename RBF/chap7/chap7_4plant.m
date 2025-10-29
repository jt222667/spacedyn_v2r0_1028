function [sys,x0,str,ts]=s_function(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u);
case 3,
    sys=mdlOutputs(t,x,u);
case {2, 4, 9 }
    sys = [];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
global J Mx Cx Gx l1 l2
l1=1;l2=1;
sizes = simsizes;
sizes.NumContStates  = 4;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 9;
sizes.NumInputs      = 2;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys=simsizes(sizes);
x0=[1 0 1 0];
str=[];
ts=[];
J=0;Mx=0;Cx=0;Gx=0;
function sys=mdlDerivatives(t,x,u)
global J Mx Cx Gx l1 l2

P=[1.66 0.42 0.63 3.75 1.25];
g=9.8;
L=[l1^2 l2^2 l1*l2 l1 l2];
if t<4.0     %Simulate time-varying load
    pl=0;
else 
    pl=0.5;
end
Mm=P+pl*L;
Q=(x(1)^2+x(3)^2-l1^2-l2^2)/(2*l1*l2);
q2=acos(Q);
dq2=-1/sqrt(1-Q^2);

A=x(3)/x(1);
p1=atan(A);
d_p1=1/(1+A^2);

B=sqrt(x(1)^2+x(3)^2+l1^2-l2^2)/(2*l1*sqrt(x(1)^2+x(3)^2));
p2=acos(B);
d_p2=-1/sqrt(1-B^2);

if q2>0
    q1=p1-p2;
    dq1=d_p1-d_p2;
else
    q1=p1+p2;
    dq1=d_p1+d_p2;
end
J=[-sin(q1)-sin(q1+q2) -sin(q1+q2);
    cos(q1)+cos(q1+q2) cos(q1+q2)];
d_J=[-dq1*cos(q1)-(dq1+dq2)*cos(q1+q2) -(dq1+dq2)*cos(q1+q2);
    -dq1*sin(q1)-(dq1+dq2)*sin(q1+q2) -(dq1+dq2)*sin(q1+q2)];
m1=Mm(1);m2=Mm(2);m3=Mm(3);m4=Mm(4);m5=Mm(5);

M=[m1+m2+2*m3*cos(q2) m2+m3*cos(q2);
   m2+m3*cos(q2) m2];
C=[-m3*dq2*sin(q2) -m3*(dq1+dq2)*sin(q2);
   m3*dq1*sin(q2)  0];
G=[m4*g*cos(q1)+m5*g*cos(q1+q2);
   m5*g*cos(q1+q2)];

Mx=(inv(J))'*M*inv(J);
Cx=(inv(J))'*(C-M*inv(J)*d_J)*inv(J);
Gx=(inv(J))'*G;

Fx=u(1:2);
dx=[x(2);x(4)];

ddx=inv(Mx)*(Fx-Cx*dx-Gx);   %ddx

sys(1)=x(2);
sys(2)=ddx(1);
sys(3)=x(4);
sys(4)=ddx(2);
function sys=mdlOutputs(t,x,u)
global J Mx Cx Gx l1 l2
norm_M=norm(Mx);
norm_C=norm(Cx);
norm_G=norm(Gx);
Fx=u(1:2);

sys(1)=x(1);
sys(2)=x(2);
sys(3)=x(3);
sys(4)=x(4);
sys(5)=norm_M;
sys(6)=norm_C;
sys(7)=norm_G;
sys(8:9)=J'*Fx;  %Practical control input