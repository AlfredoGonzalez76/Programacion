function A = SB(Ntm,wm,matm)
% Calcula la Biomasa Desovante
% Datos:
% Ntm: vector (fila) de estado del �ltimo tiempo tm
% wm: vector (fila) pesos medios de hembras maduras por edad
% matm: proporci�n de hembras maduras por edad
    A = sum(wm.*matm.*Ntm);
end