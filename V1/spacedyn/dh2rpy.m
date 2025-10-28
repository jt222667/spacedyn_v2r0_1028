function RPY = dh2rpy(DH)
% 输入: DH 参数矩阵 (n x 4)，每行 [a, alpha, d, theta]
% 输出: RPY 欧拉角矩阵 (n x 3)，每行 [roll, pitch, yaw]

n = size(DH,1);        % 关节数
RPY = zeros(n,3);      % 存放每个关节的 RPY

for i = 1:n
    a = DH(i,1);
    alpha = DH(i,2);
    d = DH(i,3);
    theta = DH(i,4);

    % 标准 DH 变换矩阵
   
    R = cz(theta)*cx(alpha);

    % 提取 RPY (Z-Y-X 顺序, yaw-pitch-roll)
    rpy = dc2rpy(R);
    RPY(i,:) = rpy;
end
end
