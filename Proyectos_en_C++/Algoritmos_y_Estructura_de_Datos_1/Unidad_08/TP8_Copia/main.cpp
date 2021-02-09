#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>

#include "menus.h"
#include "registro.h"
#include "lista.h"
#include "libro.h"

using namespace std;

//------------------------  Principal  ---------------------------

int main()
{
	string nombreArchivo = "Alumnos.txt";
//	tLista lista;
	tLibro libro;
	char opcion;

// Aquí va a tener que preguntar si el archivo nombreArchivo existe. Caso contrario lo creará y lo cerrará.

	leerLibroDeArchivo(nombreArchivo, libro);

	system("cls");

	do
	{
		opcion = menuPrincipal();
		ejecutarEnLibro(opcion, libro);
	}while(opcion != 'f');

	escribeLibroEnArchivo(nombreArchivo, libro);

	return 0;
}