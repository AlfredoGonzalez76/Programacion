%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%                         EJERCICIO 0                             %%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Se realizan aqu� todos los pasos necesarios para hacer una evaluaci�n.

load('C.mat')
load('CPUEmed.mat')
load('VCPUEm.mat')
B0 = 225600;

%%%%%           Minimizo la suma de cuadrados:           %%%%%
[r,SC] = fminsearch(@(r) SumaCuad(r,C,B0,CPUEmed,VCPUEm),0.15);

%%%        As�, la biomasa estimada ser�:        %%%
Best = ModeloG(r,C,B0)';

%%%%% Defino la funci�n S2 que es la suma de cuadrados con x variable %%%%%
S2 = @(x) SumaCuad(x,C,B0,CPUEmed,VCPUEm);

%%%%%%             Calculo la derivada segunda de S2:                %%%%%%
d = derivada2(S2,r);

%%%%%     Luego, la (matriz de co-) Varianza del r estimado ser�:     %%%%%
Vr = 2/d;

%%% Dado que 'matriz de covarianza' es asint�ticamente normal, simulo un
%%% n�mero grande 'n' de 'r�plicas' de 'r' con distrib. normal de media
%%% 'r' y varianza 'Vr'.

n = 500000;
%randn('seed',931316785)
rest = r + sqrt(Vr).*randn(n,1);

% En cada fila de la matriz 'Simula' habr� una realizaci�n del modelo
% cada una con una r�plica 'rest' de 'r'.
Simula = zeros(n,length(C)+1);

for J=1:n
    Simula(J,:) = ModeloG(rest(J),C,B0)';
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   ESTADISTICA   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

for K=1:(length(C)+1)
    media(K) = mean(Simula(:,K));
    percentiles(:,K) = prctile(Simula(:,K),[5,50,95]); %%  5%, mediana (50%) y 95%
%   moda(K) = mode(Simula(:,K));
    varianza(K) = sum((Simula(:,K)-mean(Simula(:,K))).^2)/n;
end

%hold on;
%subplot(1,2,1);
figure(gcf)
figure(1)
hold on;
plot(percentiles(1,:),'r');
plot(percentiles(2,:),'g');
plot(percentiles(3,:),'r');
plot(media,'b');
plot(Best,'s-m');
xlabel('tiempo (a�os)')
ylabel('Biomasa (tons)')
% plot(moda,'g');
legend('percentil 5','mediana','percentil 95','media','biomasa estimada MV')
title('Estad�stica')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%     Riesgo     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 'Cre': Vector Captura de reemplazo del �ltimo a�o(length(C)+1). Cre = r*B
% Para calcular distintos riesgos, pruebo diferentes capturas comenzando por 
% 'Cmult' captura m�nima del �ltimo a�o (la m�s baja considerada), subiendo
% hasta 'CMult': Captura M�xima para el �ltimo a�o(la m�s alta considerada)
% 'Cpos' vector de capturas posibles: va de 'Cult' a 'CMult' con paso 'paso'

Cmult = 0;
CMult = 20000;
cant = 20;
paso = (CMult-Cmult)/cant;
Cpos = Cmult:paso:CMult;
Cre = r*Simula(:,16);
Riesgo = zeros(1,cant+1);
for J = 1:(cant+1)
    Riesgo(J) = sum(Cpos(J)>Cre)/n;
end
%subplot(1,2,2);
figure(gcf)
figure(2)
hold on;
plot(Cpos,Riesgo);
MR = [Cpos;Riesgo];
plot(Cpos,1,'r');
plot(Cpos,0.1,'b');
axis ([0 CMult 0 1.01]);
xlabel('Capturas Ult. a�o (tons.)');
ylabel('Riesgo');
title('An�lisis de Riesgo');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
