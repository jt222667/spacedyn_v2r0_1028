function dx=Plant(t,x,flag,para)
dx=zeros(2,1);

tol=para;

M=10;
d=-15*x(2)-30*sign(x(2));

dx(1)=x(2);
dx(2)=1/M*(tol+d);