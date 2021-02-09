:: Borro el directorio de binarios si ya existiera
IF EXIST .\build RMDIR /S /Q .\build

:: Creo los directorios para el binario y las bibliotecas
MD .\build

:: Compilo el Binario
g++ -Wall -std=c++11 -c Figura.cpp
g++ -Wall -std=c++11 -c Circulo.cpp
g++ -Wall -std=c++11 -c Rectangulo.cpp
g++ -Wall -std=c++11 -c Triangulo.cpp
g++ -Wall -std=c++11 -c main.cpp 

g++ Figura.o Circulo.o Rectangulo.o Triangulo.o main.o  -o  .\build\main.exe

:: Limpio los códigos objeto
::DEL .\*.o