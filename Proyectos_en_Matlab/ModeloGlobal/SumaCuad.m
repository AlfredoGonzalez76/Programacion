function S2=SumaCuad(r,C,B0,I,VarI)
% Parámetro: r
% Variables Utilizadas:
% C : captura desde el año 1987 (inclusive) al 2001 (inclusive)
% B0 : Biomasa inicial
% I = CPUEmed = CPUE media desde 1994 (inclusive) al 2001 (inclusive)
% En los años en que no haya datos de CPUE media, colocaremos en CPUEmed un
% valor negativo
% VarI = VCPUEm = Varianza de CPUE media de 1994(incluido) a 2001(incluido)
ind = I >=0; % así, en los años en que hay índices, ind guarda un 1 y guara 0 en los que no hay
Bmed = zeros(length(C),1);
B = ModeloG(r,C,B0);
for h=1:length(C)
    Bmed(h) = 0.5*(B(h)+B(h+1));
end
qest = sum(I.*Bmed.*ind./VarI)/sum(Bmed.*Bmed.*ind./VarI);
S2 = sum((I-qest.*Bmed.*ind).^2./(VarI));
end