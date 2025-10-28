close all; clc;

%% ---------- 设置要展示的关节 ----------
F=1;
if F==1
    show_joints = [1,2,3,4,5,6,7];  % 可自定义要展示的关节
elseif F==2
    show_joints = [8,9,10,11,12,13,14];  
elseif F==3
    show_joints = [15,16,17,18,19,20,21];  
end
n_show = numel(show_joints);

%% ---------- 统一绘图参数 ----------
fontSize = 12;   % 字体大小
lineWidth = 2;   % 曲线粗细

%% ---------- 位置跟踪 ----------
figure(1);
for idx = 1:n_show
    j = show_joints(idx);
    subplot(n_show,1,idx);
    
    h1 = plot(t, eval(sprintf('x%d(:,1)', j)), 'r', 'LineWidth', lineWidth); hold on;
    h2 = plot(t, eval(sprintf('x%d(:,2)', j)), 'b', 'LineWidth', lineWidth); hold off;
    
    xlabel('时间(s)', 'FontSize', fontSize, 'FontWeight', 'bold');
    ylabel(sprintf('关节%d轨迹', j), 'FontSize', fontSize, 'FontWeight', 'bold');
    
    set(gca, 'FontSize', fontSize, 'FontWeight', 'bold'); % 加粗坐标轴刻度
    
    if idx == 1
        legend([h1,h2], {'输入轨迹','实际轨迹'}, ...
               'FontSize', fontSize, 'FontWeight', 'bold', 'Location', 'best');
    end
end

%% ---------- 跟踪误差(rad) ----------
figure(2); 
hold on; grid on;
colors = 'bgrcmyk';  % 循环颜色
for idx = 1:n_show
    j = show_joints(idx);
    c = colors(mod(idx-1,length(colors))+1);
    
    plot(t, eval(sprintf('x%d(:,1)-x%d(:,2)', j, j)), c, 'LineWidth', lineWidth);
end
xlabel('时间(s)', 'FontSize', fontSize, 'FontWeight', 'bold');
ylabel('跟踪误差(弧度/rad)', 'FontSize', fontSize, 'FontWeight', 'bold');
legend(arrayfun(@(j) sprintf('x%d', j), show_joints, 'UniformOutput', false));
set(gca, 'FontSize', fontSize, 'FontWeight', 'bold'); % 坐标轴加粗
hold off;

%% ---------- 力矩绘图 ----------
figure(3);
for idx = 1:n_show
    j = show_joints(idx);
    subplot(n_show,1,idx);
    
    plot(t, tau(:,j), 'r', 'LineWidth', lineWidth);
    
    xlabel('时间(s)', 'FontSize', fontSize, 'FontWeight', 'bold');
    ylabel(sprintf('力矩%d', j), 'FontSize', fontSize, 'FontWeight', 'bold');
    
    set(gca, 'FontSize', fontSize, 'FontWeight', 'bold'); % 坐标轴加粗
end
