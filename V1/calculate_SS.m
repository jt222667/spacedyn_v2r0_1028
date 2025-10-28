function SS = calculate_SS(LP)
LP.BB = [ ...
    0  1  2  3  4  5  6,  ...
    0  8  9  10 11 12 13, ...
    0 15 16 17 18 19 20  ];
SS=zeros(21,21);

for i = 1:21
    for j=1:21
        if i==LP.BB(j)
            SS(i,j)=1;
        elseif i==j
            SS(i,j)=-1;
        else
            SS(i,j)=0;
        end
    end
end

