:: Borro el directorio de binarios si ya existiera
IF EXIST .\build RMDIR /S /Q .\build

:: Creo los directorios para el binario y las bibliotecas
MD .\build

:: Compilo el Binario
g++ -Wall -std=c++11 -c Animal.cpp
g++ -Wall -std=c++11 -c Oviparo.cpp
g++ -Wall -std=c++11 -c Mamifero.cpp
g++ -Wall -std=c++11 -c Cocodrilo.cpp
g++ -Wall -std=c++11 -c Ganso.cpp
g++ -Wall -std=c++11 -c Pelicano.cpp
g++ -Wall -std=c++11 -c Murcielago.cpp
g++ -Wall -std=c++11 -c Ballena.cpp
g++ -Wall -std=c++11 -c LoboMarino.cpp 
g++ -Wall -std=c++11 -c main.cpp 

g++ Animal.o Oviparo.o Mamifero.o Cocodrilo.o Ganso.o Pelicano.o Murcielago.o Ballena.o LoboMarino.o main.o  -o  .\build\main.exe

:: Limpio los códigos objeto
::DEL .\*.o