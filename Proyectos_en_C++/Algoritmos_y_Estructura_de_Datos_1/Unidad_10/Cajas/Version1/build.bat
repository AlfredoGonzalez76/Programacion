:: Borro el directorio de binarios si ya existiera
IF EXIST .\build RMDIR /S /Q .\build

:: Creo los directorios para el binario y las bibliotecas
MD .\build

:: Compilo el Binario
g++ -Wall -std=c++11 -c Caja.cpp
g++ -Wall -std=c++11 -c main.cpp 

g++ Caja.o main.o  -o  .\build\main.exe

:: Limpio los códigos objeto
DEL .\*.o