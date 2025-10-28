%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The SpaceDyn, a MATLAB toolbox for Space and Mobile Robots.
% (C)1998 The Space Robotics Lab. directed by Kazuya Yoshida,
% Tohoku University, Japan.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    version 1 // Oct 4, 1999, Last modification by K.Yoshida
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%	DC2RPY	Direction Cosine matrix to roll/pitch/yaw angles
%
%	[A B C] = DC2RPY(C) returns a vector of RPY angles
%	from the direction cosine matrix C.
%
%    DC2RPY    方向余弦矩阵转滚转/俯仰/偏航角
%
%    [A B C] = DC2RPY(C) 返回方向余弦矩阵 C 对应的 RPY 角向量
%

function rpy = dc2rpy(C)

rpy = zeros(3,1);
if abs(C(2,1)) < eps && abs(C(1,1)) < eps

    rpy(3) = 0;
    rpy(2) = atan2( C(3,1) , C(1,1) );
    rpy(1) = atan2( C(2,3) , C(2,2) );
    fprintf('!\n')
else

    rpy(3) = atan2( -C(2,1) , C(1,1) );
    c3 = cos(rpy(3));
    s3 = sin(rpy(3));
    rpy(2) = atan2( C(3,1) , c3*C(1,1)-s3*C(2,1) );
    rpy(1) = atan2( -C(3,2) , C(3,3) );

end


%%%EOF
