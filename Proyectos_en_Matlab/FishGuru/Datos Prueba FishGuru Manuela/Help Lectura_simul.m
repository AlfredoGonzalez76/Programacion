%% HELP PARA LECTURA DE ARCHIVOS GENERADOS CON LA SIMULACION MC

% Datos basicos
fileID = fopen('InfoBasica_simul.txt');
D = textscan(fileID, '%d', 'CommentStyle','!','delimiter', '\n');
fclose(fileID);
D = cell2mat(D);

NSIM = D(1,1);   %Numero total de simulaciones
k = D(2,1);      %Numero de edades
t0 = D(3,1);     %Anio inicial - Periodo Diagnostico
tm = D(4,1);     %Anio final - Periodo Diagnostico 

% Vectores F del ultimo anio simulados
SIMFtm = zeros(NSIM,k);
fileID = fopen('Ftm_simul.txt');
formatSpec =  repmat('%.15f',1,k);
D = textscan(fileID, formatSpec, 'CommentStyle','!','delimiter', ',');
fclose(fileID);
SIMFtm = cell2mat(D);

% Vectores N del ultimo anio simulados
SIMNtm = zeros(NSIM,k);
fileID = fopen('Ntm_simul.txt');
formatSpec =  repmat('%8.8f',1,k);
D = textscan(fileID, formatSpec, 'CommentStyle','!','delimiter', ',');
fclose(fileID);
SIMNtm = cell2mat(D);

% Vectores p (prob.sup.) del ultimo anio simulados
SIMptm = zeros(NSIM,k);
fileID = fopen('ptm_simul.txt');
formatSpec =  repmat('%.15f',1,k);
D = textscan(fileID, formatSpec, 'CommentStyle','!','delimiter', ',');
fclose(fileID);
SIMptm = cell2mat(D);

% Vectores g (gamma) del ultimo anio simulados
SIMgtm = zeros(NSIM,k);
fileID = fopen('gtm_simul.txt');
formatSpec =  repmat('%.15f',1,k);
D = textscan(fileID, formatSpec, 'CommentStyle','!','delimiter', ',');
fclose(fileID);
SIMgtm = cell2mat(D);

% Queda todo para trabajar con las matrices:
% SIMFtm
% SIMNtm
% SIMptm
% SIMgtm
% Ejemplo, quiero el vector N(tm) de la simulacion 140: >> SIMNtm(140,:)