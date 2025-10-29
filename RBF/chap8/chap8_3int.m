clear all;
close all;

x10=0.1;x20=0;x30=0;x40=0;

x1d0=0;
dx1d0=1;

c1=5;
S10=x10-x1d0;

x2_bar0=-c1*S10+dx1d0           %x2_bar
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

x2d0=x2_bar0;   %x2d(0)=x2_bar(0)

S20=x20-x2d0;

x3_bar0=0   %x3_bar
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
x3d0=x3_bar0;  %x3d(0)=x3_bar(0)

tol3=0.01;
dx3d0=(x3_bar0-x3d0)/tol3;

S30=x30-x3d0;
c3=25;
x4_bar0=dx3d0-c3*S30           %x4_bar
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%^
x4d0=x4_bar0;
S40=x40-x4d0;

y20=x2d0-x2_bar0;
y30=x3d0-x3_bar0;
y40=x4d0-x4_bar0;
V0=0.5*(S10^2+S20^2+S30^2+S40^2)+0.5*(y20^2+y30^2+y40^2);
p=V0+0.10;        %p>=V0

display('r is larger than');%r>=Q/(2*p);
Q=1;
Q/(2*p)  

r=4   %c1=1+r

a1M=40;
a2M=1;

c1=1+r        %c1>=1+r
c2=1/2+3/2*a1M+r+0.5   %c2>=1/2++3/2*a1M+r

c3=1+1/2*a1M+r   %c3>=1+1/2*a1M+r
c4=0.5+1/2*a2M+r      %c4>=0.5+1/2*a2M+r

gama1=diag([3,3,3,3,3,3,3,0.001]);
gama2=diag([10,10,10,10,10,10,10,0.4]);

xite0=0.000001;

xite1=2*r*max(eig(inv(gama1)))*xite0
xite2=2*r*max(eig(inv(gama2)))*xite0

M2=1;M3=1;M4=1;
epc=0.01;

temp2=1/2+M2^2/(2*epc)+r;
1/temp2   %tol2<=1/temp2
tol2=0.01

temp3=a1M/2+M3^2/(2*epc)+r;
1/temp3  %tol3<=1/temp3
tol3=0.01
  
temp4=1/2+M4^2/(2*epc)+r;
1/temp4   %tol4<=1/temp4
tol4=0.01