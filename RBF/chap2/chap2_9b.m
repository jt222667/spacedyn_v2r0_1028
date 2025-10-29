%Online RBF Etimation for Plant
clear all;
load wfile b c W NS;

ts=0.001;
u_1=0;y_1=0;
fx_1=0;
h=zeros(7,1);
for k=1:1:NS
    times(k)=k; 
    u(k)=sin(k*ts);
    
    fx(k)=0.5*y_1*(1-y_1)/(1+exp(-0.25*y_1));
    y(k)=fx_1+u_1;
   
    x=[u(k),y(k)];
for j=1:1:7
    h(j)=exp(-norm(x'-c(:,j))^2/(2*b^2));  %Hidden Layer
end
yp(k)=W*h;    %Output Layer

u_1=u(k);y_1=y(k);
fx_1=fx(k);
end
figure(1);
plot(times,y,'r',times,yp,'b-.','linewidth',2);
xlabel('times');ylabel('y and yp');