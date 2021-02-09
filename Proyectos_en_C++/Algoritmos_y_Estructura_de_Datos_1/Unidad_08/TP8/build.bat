:: Borro el directorio de binarios si ya existiera
IF EXIST .\build RMDIR /S /Q .\build

:: Creo los directorios para el binario y las bibliotecas
MD .\build

:: Compilo el Binario
g++ -Wall -std=c++11 -c extras.cpp 
g++ -Wall -std=c++11 -c menus.cpp 
g++ -Wall -std=c++11 -c registro.cpp 
g++ -Wall -std=c++11 -c lista.cpp 
g++ -Wall -std=c++11 -c libro.cpp 
g++ -Wall -std=c++11 -c main.cpp 

g++ extras.o menus.o registro.o lista.o libro.o main.o  -o  main.exe

::g++ extras.o menus.o registro.o lista.o libro.o main.o  -o .\build\main.exe

:: Limpio los códigos objeto
DEL .\*.o