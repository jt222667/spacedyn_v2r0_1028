% ------------------ 辅助函数：向量饱和 ------------------
function y = sat_vec(x, hval)
% 对向量 x 做逐元素饱和： |x_i| <= hval -> x_i, else -> hval*sign(x_i)
y = x;
idx = abs(x) > hval;
y(idx) = hval .* sign(x(idx));
end

