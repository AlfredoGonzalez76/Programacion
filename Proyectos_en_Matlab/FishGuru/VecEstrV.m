function omegav = VecEstrV(pM);
% Se le pasa pM: vector de probabilidades de superviv. en estado virgen y
% devuelve el vector estructura estable de edades en el estado virgen.
omegav = zeros(size(pM));
k = length(pM);
den = zeros(size(pM));
den(1) = 1;
for j=2:(k-1)
    den(j) = pM(j-1)*den(j-1);
end
den(k) = pM(k-1)*den(k-1)/(1-pM(k));
omegav(1) = 1/sum(den);
for j=2:(k-1)
    omegav(j) = pM(j-1)*omegav(j-1);
end
omegav(k) = pM(k-1)*omegav(k-1)/(1-pM(k));
end