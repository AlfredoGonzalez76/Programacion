% Archivos de entrada de datos:

% 'SR.csv' (Stock/Recluta)
% 1� l�nea: Descripci�n del contenido del archivo
% 2� l�nea: Descripcion de los datos:
% 3� l�nea: bit de identificaci�n de la funci�n de Reclutamiento, N� de simulaciones
% 4� l�nea en adelante:
% i) Si bit = 1 (B&H) habr�: En col 1, NSIM r�plicas de alfa y en col 2
% NSIM r�plicas de beta.
% ii) Si bit = 2 (Ricker) habr�: En col 1, NSIM r�plicas de alfa y en col 2
% NSIM r�plicas de beta.
% iii) Si bit =3 (cte) habr�: En col 1, NSIM r�plicas del reclutamiento y 
% en col 2 nuevamente NSIM r�plicas del reclutamiento (para mantener el
% formato del archivo igual a las opciones anteriores)

% Todos los demas archivos de entrada de datos poseen el siguiente formato:
% 1� l�nea: Descripci�n del contenido del archivo
% 2� fila 1� columna estar� el n�mero 'k' de edades consideradas 
% 2� fila 2� col estar� 'NSIM': n�mero de simulaciones a leer de cada concepto
% si del archivo se extraen 'm' vectores de datos replicados 'N' veces,
% deber�n guardarse los 'm' vectores 'N x k' uno a continuaci�n del otro.

% 'Ntm.csv' 
% Contiene: NSIM simulaciones de Ntm: vector estado poblacional del �ltimo tiempo

% 'madurez.csv'
% Contiene:
% wm: vector (col) pesos medios de hembras maduras por edad del tiempo tm
% matm: proporci�n de hembras maduras por edad del tiempo tm

% 'SBV.csv'
% 1� fila: Descripcion del archivo
% 2� fila: Descripcion de los datos:
% 3� fila: Bit de identificaci�n: 
% 1 si posee el valor de Biomasa Desovante en estado Virgen o 0 si no lo posee
% Si en (3,1) hay un 1, en (4,1) deber� aparecer el peso en toneladas de la SBV
% Si en (3,1) hay un 0, poner en (4,1) n� de edades y en (4,2) n� simulac.
% As�, desde la fila 5 hasta el final deber� colocar consecutivamente:
% k columnas de Pesos medios de hembras maduras por edad en estado virgen.
% k columnas de Proporci�n de hembras maduras por edad en estado virgen.
% k columnas    de Probabilidad de supervivencia por edad en estado virgen.


%% Vector estado del �ltimo tiempo:
k = csvread('Ntm.csv',2,0,[2 0 2 0]); % En fila 3 col 1 est� el nro de edades
NSIM = csvread('Ntm.csv',2,1,[2 1 2 1]); % En (3,2) est� el nro de r�plicas de los datos;
Ntm = csvread('Ntm.csv',3,0,[3 0 3+NSIM-1 k-1]) % lee desde (4,1) hasta (3+NSIM,k). 
%  Datos para calcular la Biomasa Desovante:
wm = csvread('DatosSB.csv',3,0,[3 0 3+NSIM-1 k-1]); % desde (4,1) lee pesos medios de hemb maduras x edad
matm = csvread('DatosSB.csv',3,k,[3 k 3+NSIM-1 2*k-1]); % desde (4,k+1) lee prop de hemb maduras x edad

% Datos y par�metros de la Funci�n de Reclutamiento:
bit = csvread('SR.csv',2,0,[2 0 2 0]); % D�gito identificador del tipo de func. de reclutam.
%
a = csvread('SR.csv',3,0,[3 0 NSIM+2 0]);
b = csvread('SR.csv',3,1,[3 1 NSIM+2 1]);

%% Tasas instant�neas de mortalidad por pesca por edad del �ltimo tiempo tm
Ftm = csvread('Fs.csv',3,0,[3 0 NSIM+2 k-1]);

% Tasas instant�neas de mortalidad natural por edad del �ltimo tiempo tm
Mtm = csvread('Ms.csv',3,0,[3 0 NSIM+2 k-1]);

%%
lambda = 0.3:0.1:1.3;
% Probabilidad de supervivencia por edad del �ltimo tiempo tm (var�an con lambda)
ptm = zeros(NSIM,k,length(lambda));
gama = zeros(NSIM,k,length(lambda));
for s = 1:length(lambda)
    ptm(:,:,s) = exp(-lambda(s)*Ftm-Mtm);    % exponencial de las entradas de la matriz
    gama(:,:,s) = (lambda(s)*Ftm)./(lambda(s)*Ftm+Mtm);
end

%% Archivo con el valor de SBV o los datos para calcularla:
bitSBV = csvread('SBV.csv',2,0,[2 0 2 0]); % 1 si conoce valor de SBV, 0 caso contrario

if bitSBV == 1
    BDV = csvread('SBV.csv',3,0,[3 0 3 0]);% 3,0 indica que lee desde fila 4, col 1
    unos = ones(NSIM,1);
    BDV = BDV.*unos;         % de este modo replico NSIM veces la BDV.
else
    % Pesos medios de hembras maduras por edad en estado virgen:
    % wmv = csvread(filename,3,0,[3 0 NSIM+2 k-2]); % Primeras k columnas de pesos medios
    wmv = 1.2*wm;
    % Proporci�n de hembras maduras por edad en estado virgen:
    matv = csvread('SBV.csv',3,k,[3 k 3+NSIM-1 2*k-1]); % sigtes k col: prop de hembras mad.
    % Probabilidad de supervivencia por edad en estado virgen:
    % pM = csvread(filename,3,2*(k-1),[3 2*(k-1) NSIM+2 3*(k-1)-1]); % "pM=exp(-M)"
    pM = exp(-Mtm);
    % Pesos medios poblacionales en estado virgen:
    % w = csvread(filename,3,2*(k-1),[3 2*(k-1) NSIM+2 4*(k-1)-1]);
    w = wmv;
    VE = zeros(size(pM));        % Vector Estructura Poblacional
    BDV = zeros(size(pM(:,1)));  % Biomasa Desovante Virgen
    apM = zeros(size(pM(:,1)));  % Su dimensi�n es NSIM x 1
    N1v = zeros(size(pM(:,1)));  % 1� componente del vector estructura virgen
    Nv = zeros(size(pM(:,1)));   % N�mero total de individuos en el estado virgen
    BV = zeros(size(pM(:,1)));   % Biomasa total en el estado virgen
    for J=1:length(pM(:,1))      % Hace esto NSIM veces
        VE(J,:) = VecEstrV(pM(J,:));   % Vector Estructura Poblacional Virgen
        apM(J) = VE(J,1)/sum(wmv(J,:).*matv(J,:).*VE(J,:));
        BDV(J) = SBV(a(J),b(J),apM(J),bit);  % Calcula la biomasa desovante virgen
        N1v(J) = apM(J).* BDV(J);
        Nv(J) = N1v(J)./ VE(J,1);
        BV(J) = Nv(J).*sum(w(J,:).*VE(J,:));
    end
end    
%% Cantidad de tiempos a proyectar y fracci�n de la biomasa desovante virgen
Tmax = csvread('Tiempos-r.csv',2,0,[2 0 2 0]); % En (3,1) est� el nro de tiempos a proyectar
dim = csvread('Tiempos-r.csv',2,1,[2 1 2 1]);  % dimension del vector de r's
r = csvread('Tiempos-r.csv',4,0,[4 0 4 dim-1]); % inicializo vector de r's
%%
st = 'An�lisis de Riesgo' 

R = zeros(dim,Tmax,length(lambda));      % Matriz de Riesgos

for s = 1:length(lambda)
    for m = 1:dim
        N = zeros(NSIM,k,Tmax+1);
        C = zeros(NSIM,k,Tmax);
        N(:,:,1) = Ntm;           % Comenzamos a proyectar con las NSIM r�plicas de Ntm
        BD = zeros(NSIM,Tmax);
        for t = 1:Tmax
            CONT = 0;
            for j=1:NSIM
                BD(j,t) = SB(N(j,:,t),wm(j,:),matm(j,:));
                if BD(j,t) < (r(m)*BDV(j))
                    CONT = CONT + 1;
                    %aux = sprintf('Biomasa Desovante: %f ; Biomasa Virgen: %f ; contador: %f',BD(j,t),BDV(j),CONT); disp(aux);
                    %print(BD(j,t),BDV(j),CONT)
                end
                N(j,:,t+1) = Proyecta(N(j,:,t),ptm(j,:,s),bit,a(j),b(j),BD(j,t));
                C(j,:,t) = gama(j,:,s).*(ones(size(ptm(j,:,s)))-ptm(j,:,s)).*N(j,:,t+1);
            end
            R(m,t,s) = CONT/NSIM;
        end
        figure(gcf);
        figure((s-1)*dim+m); % Hace un gr�fico para cada lambda y cada r
        hold on;
        xlabel('Tiempos Proyectados(a�os)');
        ylabel('Riesgo');
        st1 = num2str(lambda(s));
        st2 = num2str(r(m));
        title({st;strcat('\it{\lambda = }',st1,' y ',' \it{r = }',st2)});
        plot(R(m,:,s),'r');
    end
end