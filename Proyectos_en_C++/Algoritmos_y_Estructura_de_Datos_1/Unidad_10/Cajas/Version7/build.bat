:: Borro el directorio de binarios si ya existiera
IF EXIST .\build RMDIR /S /Q .\build

:: Creo los directorios para el binario y las bibliotecas
MD .\build

:: Compilo el Binario
g++ -Wall -std=c++11 -c Contenedor.cpp
g++ -Wall -std=c++11 -c Caja.cpp
g++ -Wall -std=c++11 -c Lata.cpp
g++ -Wall -std=c++11 -c CajaBotellas.cpp
g++ -Wall -std=c++11 -c main.cpp 

g++ Contenedor.o Caja.o Lata.o CajaBotellas.o main.o  -o  .\build\main.exe

:: Limpio los códigos objeto
::DEL .\*.o