%Test RBF
clear all;
load wfile b c W;

%N Samples
x=[0.970,0.001,0.001;
   1.000,0.000,0.000];
NS=2;
h=zeros(5,1);  %hj

for i=1:1:NS
    for j=1:1:5
        h(j)=exp(-norm(x(i,:)'-c(:,j))^2/(2*b^2));  %Hidden Layer
    end
yl(i,:)=W'*h;    %Output Layer
end
yl