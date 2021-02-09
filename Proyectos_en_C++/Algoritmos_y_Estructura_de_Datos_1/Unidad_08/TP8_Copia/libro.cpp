
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




//------------------  Funciones sobre Libro   ------------------------


void mostrarLibro(tLibro& librito)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			mostrarCabeceraCarrera(i,j);
			mostrarLista(librito[i][j]);
		}
	}
}


void buscaNomApeEnLibro(tLibro& librito, string fragmento)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			mostrarCabeceraCarrera(i,j);
			buscaNomApeEnLista(librito[i][j], fragmento);
		}
	}
}


void ordenaLibroPorIntercambio(tLibro& librito, int op)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			ordenaListaPorIntercambio(librito[i][j], op);
		}
	}
}


void ejecutarEnLibro(char opcion, tLibro& librito)
{
	string fragmento;
	int carrera, anio, op;
	do
	{
		switch(opcion)
		{
		  case 'a':
		  	system("cls");
		    mostrarLibro(librito);
		    break;
		  case 'b':
		  	cout << "Ingrese al menos un fragmento del nombre o el apellido que busca: ";
		  	getline(cin, fragmento);
		  	cout << endl;
		  	buscaNomApeEnLibro(librito, fragmento);
		    break;
		  case 'c':
		  	system("cls");
		  	estadisticaTotal(librito);
		    break;
		  case 'd':
			cout << endl;
			op = menuOrdenacion();
			ordenaLibroPorIntercambio(librito,op);
	    break;
		    break;
		  case 'e':
		  	system("cls");
		  	carrera = eligeCarrera(); carrera--;
		  	anio = eligeAnio(); anio--;
			do
			{
				op = menuPorCarrera(carrera,anio);
				ejecutarEnLista(op, librito[carrera][anio]);
			}while(op != 9);
		    break;
		}
	} while ((opcion < 'a') && (opcion > 'e'));  // si la opcion es 'f' (fuera de este rango), sale.
}


//--------------------- ESTADISTICA TOTAL  -------------------

void estadisticaTotal(tLibro& librito)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			mostrarCabeceraCarrera(i,j);
			estadistica(librito[i][j]);
		}
	}
}


// ----------------   Manejo de Archivos   ---------------

void leerLibroDeArchivo(string nombreArch, tLibro& librito)
{
	ifstream flujoIn;

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
		int carrera, anio, auxInt;
		string linea;

		while ( ! flujoIn.eof() )
		{		
			getline(flujoIn,linea);        // La primera linea contiene el caracter identificador de la carrera
			carrera = atoi(linea.c_str()); // Lo transformo a entero para poder operar con el

			getline(flujoIn,linea);        // La segunda linea contiene el caracter identificador del anio q cursa
			anio = atoi(linea.c_str());    // Lo transformo a entero para poder operar con el

			getline(flujoIn,linea);
			librito[carrera][anio].elementos[librito[carrera][anio].contador].apellidos = linea ;

			getline(flujoIn,linea);
			librito[carrera][anio].elementos[librito[carrera][anio].contador].nombres = linea ;
			
			getline(flujoIn,linea);
			auxInt = atoi(linea.c_str());
			librito[carrera][anio].elementos[librito[carrera][anio].contador].edad = auxInt ;

			getline(flujoIn,linea);
			auxInt = atoi(linea.c_str());
			librito[carrera][anio].elementos[librito[carrera][anio].contador].dni = auxInt ;

			getline(flujoIn,linea);
			auxInt = atoi(linea.c_str());
			librito[carrera][anio].elementos[librito[carrera][anio].contador].nota = auxInt ;

			librito[carrera][anio].contador++;
	}
		flujoIn.close();		
	}
}


int cuentaAlumnos(tLibro& librito)
{
	int total = 0;

	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			total+= librito[i][j].contador;
		}
	}
	return total;
}


void escribeLibroEnArchivo(string nombreArch, tLibro& librito)
{
	int total = cuentaAlumnos(librito); // Uso este valor como control del fin del archivo.
	int acumula = 0;
	ofstream flujoOut;

	flujoOut.open(nombreArch);

	if (flujoOut.fail()) // comprueba una conexión fallida
	{
		cout << "\n El archivo no se abrió con éxito" << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < cantCarreras; ++i)
		{
			for (int j = 0; j < cantAnios; ++j)
			{
				for (int k = 0; k < librito[i][j].contador; ++k)
				{
					acumula ++; // Aqui voy registrando la cantidad de registros escritos hasta este momento
					flujoOut << i << endl;
					flujoOut << j << endl;
					flujoOut << librito[i][j].elementos[k].apellidos << endl;
					flujoOut << librito[i][j].elementos[k].nombres << endl;
					flujoOut << librito[i][j].elementos[k].edad << endl;
					flujoOut << librito[i][j].elementos[k].dni << endl;
					if (acumula < total)  // Me veo obligado a hacer esto para que no deje un renglon en blanco al final del archivo
					{
						flujoOut << librito[i][j].elementos[k].nota << endl;
					}
					else
					{
						flujoOut << librito[i][j].elementos[k].nota;
					}
				}
			}
		}

	}
	flujoOut.close();
}