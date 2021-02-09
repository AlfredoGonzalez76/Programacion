function B = ModeloG(r,C,B0)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%      MODELO GLOBAL DE BIOMASA      %%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Par�metro: r
% Variables Utilizadas:
% C : captura desde el a�o 1987 (inclusive) al 2001 (inclusive)
% B0 : Biomasa inicial
B = zeros(length(C)+1,1);
B(1) = B0;
for t = 1:length(C)
    B(t+1)= B(t) + r * B(t) - C(t);
end
end