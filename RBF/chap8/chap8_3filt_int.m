clear all;
close all;

x1=0.1;
x1d=0;
dx1d=1;

c1=5;
s1=x1-x1d;

x2_bar=-c1*s1+dx1d           %x2_bar
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

x2d=x2_bar;   %x2d(0)=x2_bar(0)


x3_bar=0   %x3_bar
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
x3d=x3_bar;  %x3d(0)=x3_bar(0)

tol3=0.01;
dx3d=(x3_bar-x3d)/tol3;

x3=0;
s3=x3-x3d;
c3=25;
x4_bar=dx3d-c3*s3           %x4_bar