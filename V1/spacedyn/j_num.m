%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%	May 3, 1998, Last modification by K.Yoshida
%   Feb27, 2002, Akiyoshi Irobe
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   J_NUM	Find joint connection from a given End-link to the 0-th link
%
%   J_NUM    根据 SE（末端标记），找到某个末端连杆到基座的关节连接路径。

function  joint = j_num(  LP , num_e )
% SE 为与外力矩相关的一个矩阵   如果为末端杆件 则SE(i)=1;

n = length(LP.SE);
j = 0;

for i = 1 : n
   if LP.SE(i) == 1
      j = j + 1;
      ie(j) = i;      
   end
end
% ie(num_e) = 取第 num_e 个末端连杆的编号
j_number = LP.BB(ie(num_e));
connection = [ie(num_e)];

while (j_number ~= 0);
   
   connection = [j_number connection];
   j_number = LP.BB(j_number);
   
end

joint = connection;

%%
% BB = [0 1 2 3 0 1 2]
% SE = [0 0 0 1 0 1 0]
% ie = [4,6] → 第 1 个末端是 4，第二个末端是 6。
% 
% 如果 num_e=1：
% 
% connection = [4]
% 
% 父节点 = BB(4)=3 → connection=[3 4]
% 
% 父节点 = BB(3)=2 → connection=[2 3 4]
% 
% 父节点 = BB(2)=1 → connection=[1 2 3 4]
% 
% 父节点 = BB(1)=0 → 停止
% 
% 结果 joint = [1 2 3 4]
% 
% 也就是「末端 4」这条链路是从 1→2→3→4。
% 
% 如果 num_e=2：
% 
% 最终会得到 joint = [1 6]，表示「末端 6」在连杆 1 上分支出来。
%%
% 为什么 SE = [0 0 0 1 0 1 0] 而不是 [0 0 0 1 0 0 1]？
% 
% 这里的差别是：
% 
% [0 0 0 1 0 1 0] → 末端是 4 和 6
% 
% [0 0 0 1 0 0 1] → 末端是 4 和 7
% 
% 原因：
% 
% 因为 SE 由用户定义，用来告诉 SpaceDyn 哪些连杆末端需要考虑外力/力矩。
% 
% 如果你只在连杆 4 和连杆 6 上安装了末端执行器（比如抓手、工具），那么就设 SE(4)=1, SE(6)=1。
% 
% 如果换一种物理配置，只在 4 和 7 上有末端，那就设 SE(4)=1, SE(7)=1。
% 
% 也就是说，SE 不是严格自动推出来的“叶子”，而是 你指定的“任务末端”集合。
