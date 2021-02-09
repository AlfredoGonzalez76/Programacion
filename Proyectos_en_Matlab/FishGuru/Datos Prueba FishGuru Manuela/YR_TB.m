function y = YR_TB(x,F,M,W)
p = exp(-(x.*F)- M);
G = (x.*F)./((x.*F)+ M);
k = length(F);
aux = 1;
sum = 0;
for i=1:k-1,
  sum = sum + G(i)*(1-p(i))*aux*W(i);
  aux = aux*p(i);
end
sum = sum + G(k)*aux*W(k);
y = sum;
end













