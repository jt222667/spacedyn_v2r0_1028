%System (6) Analysis
clear all;
close all;

A=[0 1;0 0];
K1=400;K2=800;
K=[K1 K2]';
b=[0 1]';
C=[1 0]';

%For dot(x)=Ax+Bu,y=Cx, see >help ss2tf
A=A-K*C';
B=b;C=C';D=0;
[num,den]=ss2tf(A,B,C,D);   

H=tf(num,den)  %Plant
pole(H)

L=tf(1,[1 3])  %Low filter

sys=series(H,inv(L))