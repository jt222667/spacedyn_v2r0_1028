%RBF Training for MIMO
clear all;
close all;

xite=0.10;
alfa=0.05;

W=rands(5,2);
W_1=W;
W_2=W_1;
h=[0,0,0,0,0]';

c=2*[-0.5 -0.25 0 0.25 0.5;
     -0.5 -0.25 0 0.25 0.5;
     -0.5 -0.25 0 0.25 0.5];   %cij
b=10;    %bj

xs=[1,0,0];%Ideal Input
ys=[1,0];  %Ideal Output
OUT=2;
NS=1;

k=0;

E=1.0;
while E>=1e-020
%for k=1:1:1000
k=k+1;   
times(k)=k;

for s=1:1:NS   %MIMO Samples  
x=xs(s,:);

for j=1:1:5
    h(j)=exp(-norm(x'-c(:,j))^2/(2*b^2));  %Hidden Layer
end
yl=W'*h;    %Output Layer

el=0;
y=ys(s,:);
for l=1:1:OUT
   el=el+0.5*(y(l)-yl(l))^2;    %Output error
end
es(s)=el;

E=0;
if s==NS
   for s=1:1:NS
       E=E+es(s);
   end
end
error=y-yl';
dW=xite*h*error;

W=W_1+dW+alfa*(W_1-W_2);

W_2=W_1;W_1=W;
end   %End of for
Ek(k)=E;
end   %End of while
figure(1);
plot(times,Ek,'r','linewidth',2);
xlabel('k');ylabel('Error index change');
save wfile b c W;