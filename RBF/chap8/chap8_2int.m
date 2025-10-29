clear all;
close all;

Gama1=0.5;Gama2=10;Gama3=5;

a1=1;a1M=1;
a3=1;a3M=1;

r=0.010;
epc=0.01;
M2=1;
M3=1;

c1=3*a1M/2+r
c2=3/2+a1M/2+r
c3=a3M/2+1/2+r


temp1=a1M/2+M2^2/(2*epc)+r;
tol2=1/temp1

temp3=1/2+M3^2/(2*epc)+r;
tol3=1/temp3


xite1=2*r/Gama1
xite2=2*r/Gama2
xite3=2*r/Gama3