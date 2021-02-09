function A = SB(Ntm,wm,matm)
% Calcula la Biomasa Desovante
% Datos:
% Ntm: vector (fila) de estado del último tiempo tm
% wm: vector (fila) pesos medios de hembras maduras por edad
% matm: proporción de hembras maduras por edad
    A = sum(wm.*matm.*Ntm);
end