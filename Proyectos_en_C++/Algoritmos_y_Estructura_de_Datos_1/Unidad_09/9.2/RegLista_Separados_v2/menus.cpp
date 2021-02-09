#include <iostream>
#include <iomanip>

#include "menus.h"
using namespace std;


int menuPrincipal()
{
	char op;

	cout << "--------------------------------------------" << endl;
	cout << '|' << "               MENU PRINCIPAL             " << '|' << endl;
	cout << "--------------------------------------------" << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (a) Mostrar Listado TOTAL de Alumnos     " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (b) Buscar un Alumno en el Listado TOTAL " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (c) Ver Estadisticas de TODOS los cursos " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (d) Ordenar Listas de TODOS los cursos   " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (e) Trabajar por carrera y por anio      " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (f) Grabar Datos y Salir                 " << '|' << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 'a') && (op > 'f') );
	cout << endl;

	return op;
}


int menuPorCarrera(int carrera, int anio)
{
	int op;
	mostrarCabeceraCarrera(carrera, anio);
	cout << "---------------------------------------------------------------------" << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 1. Mostrar Listado de Alumnos " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 2. Ingresar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 3. Buscar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 4. Modificar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 5. Eliminar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 6. Ordenar Registros " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 7. Listado con Datos completos " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 8. Ver Estadisticas " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 9. Volver al Menu Principal " << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 1) && (op > 9) );

	cout << endl;
	return op;
}


void mostrarCabeceraCarrera(int carrera, int anio)
{
    cout << "---------------------------------------------------------------------" << endl ;
	switch(carrera)
	{
	  case 0:
	     cout << '|' << "       Tecnicatura Superior en Analisis de Sistemas       | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 1:
	     cout << '|' << "            Tecnicatura Superior en Logistica             | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 2:
	     cout << '|' << " Tecnicatura Superior en Industria Textil e Indumentaria  | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 3:
	     cout << '|' << "             Tecnicatura Superior en Turismo              | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 4:
	     cout << '|' << "        Tecnicatura Superior en Gestion Ambiental         | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 5:
	     cout << '|' << "       Tecnicatura Superior en Emergencias Medicas        | Anio " << (anio + 1) << " |" << endl ;
	    break;
	}
    cout << "---------------------------------------------------------------------" << endl ;

}


int eligeCarrera()
{
	int op;

	cout << "---------------------------------------------------------" << endl ;
	cout << "|  1  |  Tecnicatura Superior en Analisis de Sistemas   |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  2  |  Tecnicatura Superior en Logistica              |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  3  |  Tecnicatura Superior en Industria Textil       |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  4  |  Tecnicatura Superior en Turismo                |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  5  |  Tecnicatura Superior en Gestion Ambiental      |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  6  |  Tecnicatura Superior en Emergencias Medicas    |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 1) && (op > 6) );
	cout << endl;

	return op;
}


int eligeAnio()
{
	int op;

	cout << "------------------------------" << endl ;
	cout << "|  1  |  Primer Anio         |" << endl ;
	cout << "------------------------------" << endl ;
	cout << "|  2  |  Segundo Anio        |" << endl ;
	cout << "------------------------------" << endl ;
	cout << "|  3  |  Tercer Anio         |" << endl ;
	cout << "------------------------------" << endl ;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 1) && (op > 3) );
	cout << endl;

	return op;
}


int menuOrdenacion()
{
	int op;
	cout << "---------------------------------------------------------------------" << endl ;
	cout << setw(68) << setiosflags(ios::left) << "| 1. Orden Ascendente por Apellidos" << '|' << endl;
	cout << setw(68) << setiosflags(ios::left) << "| 2. Orden Descendente por Apellidos" << '|' << endl;
	cout << setw(68) << setiosflags(ios::left) << "| 3. Orden Ascendente por Nombres" << '|' << endl;
	cout << setw(68) << setiosflags(ios::left) << "| 4. Orden Descendente por Nombres" << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl ;
	cout << setiosflags(ios::left) << endl;
	cout << " Digite aqui su opcion: ";
	cin >> op;
	cin.ignore();
	cout << endl;

	return op;
}


