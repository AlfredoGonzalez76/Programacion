function [N,S] = Proyecta(Ntm,p,bit,a,b,SBtm)
% Ntm: vector de estado del último tiempo tm
% ptm: p's del último tiempo
% SBtm: Biomasa desovante del último tiempo.

% N = zeros(NSIM,k,Tmax+1);     % N = zeros(Tmax+1,k,NSIM);

k = length(Ntm);    % Lee la cantidad de edades de la especie

S=Ntm;

N = zeros(1,k);        % Inicializo la matriz de N's
for i=1:(k-2)
    N((i+1)) = p(i)*Ntm(i);
end
N(k)=p(k-1)*Ntm(k-1)+p(k)*Ntm(k);
switch bit
    case 1    % Beverton & Holt
        N(1) = (a*SBtm)/(b+SBtm);
    case 2    % Ricker
        N(1) = (a*SBtm)*exp(-b*SBtm);
    case 3    % Reclutamiento constante
        N(1) = a;
end    
end