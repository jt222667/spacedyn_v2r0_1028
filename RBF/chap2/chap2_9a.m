%RBF Training for a Plant
clear all;
close all;

ts=0.001;
xite=0.50;
alfa=0.05;

u_1=0;y_1=0;
fx_1=0;

W=0.1*ones(1,7);
W_1=W;
W_2=W_1;
h=zeros(7,1);

c1=[-3 -2 -1 0 1 2 3];
c2=[-3 -2 -1 0 1 2 3];
c=[c1;c2];

b=1.5;    %bj

NS=3000;
for s=1:1:NS   %Samples  
u(s)=sin(s*ts);

fx(s)=0.5*y_1*(1-y_1)/(1+exp(-0.25*y_1));
y(s)=fx_1+u_1;
   
u_1=u(s);
y_1=y(s);
fx_1=fx(s);
end
k=0;

for k=1:1:500
k=k+1;   
times(k)=k;

for s=1:1:NS   %Samples
    x=[u(s),y(s)];
for j=1:1:7
    h(j)=exp(-norm(x'-c(:,j))^2/(2*b^2));  %Hidden Layer
end
yl(s)=W*h;    %Output Layer

el=0.5*(y(s)-yl(s))^2;    %Output error

es(s)=el;

E=0;
if s==NS
   for s=1:1:NS
       E=E+es(s);
   end
end
error=y(s)-yl(s);
dW=xite*h'*error;

W=W_1+dW+alfa*(W_1-W_2);

W_2=W_1;W_1=W;
end   %End of for
Ek(k)=E;
end   %End of while
figure(1);
plot(times,Ek,'r','linewidth',2);
xlabel('k');ylabel('Error index change');
save wfile b c W NS;