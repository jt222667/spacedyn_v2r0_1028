% 定义 ψ 轴
psi = linspace(0.1, 200, 5000);  % 避免 ψ=0
N = psi.^2 .* sin(psi);  % B-type Nussbaum 函数

% 计算积分 ∫0^ψ N(τ)dτ （trapz数值积分）
integral_vals = cumtrapz(psi, N);

% 计算 (1/ψ) * ∫0^ψ N(τ)dτ
ratio_vals = integral_vals ./ psi;

% 绘图
figure;
plot(psi, ratio_vals, 'LineWidth', 1.5);
title('(1/ψ) * ∫_0^ψ N(τ) dτ  -- Nussbaum Function Demonstration', 'FontSize', 12);
xlabel('\psi', 'FontSize', 12);
ylabel('(1/\psi) * ∫_0^\psi N(\tau) d\tau', 'FontSize', 12);
grid on;