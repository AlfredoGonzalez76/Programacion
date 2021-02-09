#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

//--------------  Tipos de datos Introducidos  -----------------

const int Dimension = 50;

typedef struct {
   string nombres;
   string apellidos;
   int edad;
   int dni;
   int notas;
} tEstudiante;


typedef tEstudiante tArray[Dimension];

typedef struct {
   tArray elementos;
   int contador;
} tLista;


// En caso de utilizar archivos de texto la informacion se guardara y leera de la sig. manera:
// un campo por cada línea y cada registro de la lista debajo del anterior.

//------------------  Declaracion de Funciones Propias   ------------------------

int menu();
void leeListaDeArchivo(string nombreArch);
void mostrarListadoConNotas(tLista& listita);


//------------------------  Principal  ---------------------------

int main()
{
	string nombreArchivo = "AyEDI.txt";
	tLista lista;
	int testCifra;
	int testNum, opcion;


	opcion = menu();

	leeListaDeArchivo(nombreArchivo);

//	mostrarListadoConNotas(lista);

	return 0;
}


//----------------- Definicion de Funciones Propias ----------------------

int menu()
{
	int op;
	cout << "--------------------------------" << endl;
	cout<< '|' << "             MENU             " << '|' << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
	cout<< '|' << setw(30) <<setiosflags(ios::left) << "1. Mostrar Listado de Alumnos" << '|' << endl;
	cout<< '|' << setw(30) <<setiosflags(ios::left) << "2. Ingresar un Registro" << '|' << endl;
	cout<< '|' << setw(30) <<setiosflags(ios::left) << "2. Buscar un Registro" << '|' << endl;
	cout<< '|' << setw(30) <<setiosflags(ios::left) << "4. Modificar un Registro" << '|' << endl;
	cout<< '|' << setw(30) <<setiosflags(ios::left) << "5. Eliminar un Registro" << '|' << endl;
	cout<< '|' << setw(30) <<setiosflags(ios::left) << "6. Listado completo con Notas" << '|' << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
	}
	while ((op < 1) && (op > 5) );
	cout << endl;
	return op;
}

void leeListaDeArchivo(string nombreArch)
{
	ifstream flujoIn;
	tLista listaAlumnos;

	flujoIn.open(nombreArch);

	if (flujoIn.fail()) // comprueba una conexión fallida
	{
		cout << "\n El archivo no se abrió con éxito"
			 << "\n Por favor compruebe que el archivo realmente exista."
		<< endl;
		exit(1);
	}
	else
	{
		listaAlumnos.contador = 0;
		string linea;
		int auxInt;
		while ( ! flujoIn.eof() )
		{		
			getline(flujoIn,linea);
			listaAlumnos.elementos[listaAlumnos.contador].nombres  = linea ;
			cout << linea << ' ';

			getline(flujoIn,linea);
//			listaAlumnos.elementos[listaAlumnos.contador].apellidos  = linea ;
			cout << linea << endl;
			
			getline(flujoIn,linea);
//			listaAlumnos.elementos[listaAlumnos.contador].edad  = auxInt ;
			cout << linea << endl;

			getline(flujoIn,linea);
//			listaAlumnos.elementos[listaAlumnos.contador].dni  = auxInt ;
			cout << linea << endl;

			getline(flujoIn,linea);
			auxInt = atoi(linea.c_str());
			listaAlumnos.elementos[listaAlumnos.contador].notas = auxInt;
			cout << "Nota: " << listaAlumnos.elementos[listaAlumnos.contador].notas << endl;

			cout << endl;

			listaAlumnos.contador++;

		}
		cout << "Cantidad de registos: " << listaAlumnos.contador << endl;
		cout << endl;

		flujoIn.close();		
	}
}


/*
tLista& leeListaDeArchivo(string nombreArch)
{
	ifstream flujoIn;
	tLista listaAlumnos;

	flujoIn.open(nombreArch);

	if (flujoIn.fail()) // comprueba una conexión fallida
	{
		cout << "\n El archivo no se abrió con éxito"
			 << "\n Por favor compruebe que el archivo realmente exista."
		<< endl;
		exit(1);
	}
	else
	{
		int cont = 0;
		string linea;
		int auxInt;
		int auxNota;
		while ( ! flujoIn.eof() )
		{		
			getline(flujoIn,linea);
			listaAlumnos.elementos[cont].nombres  << linea ;

			getline(flujoIn,linea);
			listaAlumnos.elementos[cont].apellidos  << linea ;
			
			getline(flujoIn,auxInt);
			listaAlumnos.elementos[cont].edad  << auxInt ;

			getline(flujoIn,auxInt);
			listaAlumnos.elementos[cont].dni  << auxInt ;

			getline(flujoIn,auxNota);
			listaAlumnos.elementos[cont].notas  << auxNota ;

			listaAlumnos.contador++;
	}
		flujoIn.close();		
	}

	return listaAlumnos;
}

void mostrarListadoConNotas(tLista& listita)
{
	cout << "\n La lista acutal es:" << endl;
	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "Nombres: " << setw(30) <<setiosflags(ios::right) << listita.elementos[i].nombres << endl ;
		cout << "Apellidos: " << setw(30) <<setiosflags(ios::right) << listita.elementos[i].apellidos << endl ;
		cout << "Edad: " << setw(30) <<setiosflags(ios::right) << listita.elementos[i].edad << endl ;
		cout << "DNI: " << setw(30) <<setiosflags(ios::right) << listita.elementos[i].dni << endl ;
		cout << "Nota: " << setw(30) <<setiosflags(ios::right) << listita.elementos[i].notas << endl ;
		cout << "------------------------------" << endl ;
	}
	cout << endl;
}
*/

/*

ingresaRegistro()
{

}

escribeRegistro()
{

}

escribeListaEnArchivo()
{

} */