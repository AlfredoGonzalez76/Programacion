function B = SBV(a,b,apM,bit);
% Calcula la Biomasa Desovante Virgen en cualquiera de los tres casos
switch bit
    case 1
        B = (a/apM)-b;
    case 2
        B = (1/b)*log(a/apM);
    case 3
        B = a/apM;
end
end