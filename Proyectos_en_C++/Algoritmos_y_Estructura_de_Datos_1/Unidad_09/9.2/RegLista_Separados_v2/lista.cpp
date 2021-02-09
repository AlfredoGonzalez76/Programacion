#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>

#include "extras.h"
#include "menus.h"
#include "registro.h"
#include "lista.h"

using namespace std;



//------------------  Funciones sobre Listas   ------------------------


void mostrarLista(tLista& listita)
{
	cout << "---------------------------------------------------------------------" << endl ;
	cout << '|' << setw(55) << setiosflags(ios::left) << " Apellidos y Nombres  " << " |" << 
	setw(10) << setiosflags(ios::left) << " Registro" << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl ;

	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "| " << setw(55) <<setiosflags(ios::left) << listita.elementos[i].apellidos + ", " + listita.elementos[i].nombres << "|     " <<
		setw(5) << setiosflags(ios::left) << i << '|' << endl;
	}

	cout << "---------------------------------------------------------------------" << endl ;
	cout << endl;
}


void mostrarListaConNotas(tLista& listita)
{
	cout << "\n La lista acutal es:" << endl;
	cout << "------------------------------" << endl ;
	for (int i = 0; i < listita.contador; ++i)
	{
		muestraRegistroCompleto(listita.elementos[i]);
		cout << "| Registro:  " << setw(55) << setiosflags(ios::right) << i << '|' << endl;
		cout << setiosflags(ios::left) << "---------------------------------------------------------------------" << endl ;

	}
	cout << endl;
}


void agregaRegistro(tLista& listita)
{

	listita.elementos[listita.contador] = cargaRegistro();

	listita.contador++;
}


void eliminaRegistro(tLista& listita, int posicion)
{
	if (posicion < listita.contador)
	{
		for (int i = posicion; i < listita.contador; ++i)
		{
			listita.elementos[i] = listita.elementos[i+1];
		}
		listita.contador--;
	}
	else
	{
		cout << "El Registro ingresado no existe." << endl;
	}
}


void buscaNomApeEnLista(tLista& listita, string fragmento)
{

	for (int i = 0; i < listita.contador; ++i)
	{
		if(In(mayuscula(fragmento),mayuscula(listita.elementos[i].nombres)) || In(mayuscula(fragmento),mayuscula(listita.elementos[i].apellidos)))
		{
			muestraRegistroCompleto(listita.elementos[i]);
			cout << "| Registro:  " << setw(55) << setiosflags(ios::right) << i << '|' << endl;
			cout << setiosflags(ios::left) << "---------------------------------------------------------------------" << endl ;
		}

	}

}


void ordenaListaPorIntercambio(tLista& listita, int op)
{
	for (int i = 0; i < (listita.contador - 1); ++i)
	{
		for (int j = i+1; j < listita.contador; ++j)
		{
			switch(op)
			{
				case 1:
					if((listita.elementos[i].apellidos > listita.elementos[j].apellidos) || ((listita.elementos[i].apellidos == listita.elementos[j].apellidos) && (listita.elementos[i].nombres > listita.elementos[j].nombres)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
				case 2:
					if((listita.elementos[i].apellidos < listita.elementos[j].apellidos) || ((listita.elementos[i].apellidos == listita.elementos[j].apellidos) && (listita.elementos[i].nombres < listita.elementos[j].nombres)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
				case 3:
					if((listita.elementos[i].nombres > listita.elementos[j].nombres) || ((listita.elementos[i].nombres == listita.elementos[j].nombres) && (listita.elementos[i].apellidos > listita.elementos[j].apellidos)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
				case 4:
					if((listita.elementos[i].nombres < listita.elementos[j].nombres) || ((listita.elementos[i].nombres == listita.elementos[j].nombres) && (listita.elementos[i].apellidos < listita.elementos[j].apellidos)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
			}
		}
	}
}


void ejecutarEnLista(int opcion, tLista& listita)
{
  	int op, pos;
  	string fragmento;
	switch(opcion) {
	  case 1:
	     mostrarLista(listita);
	    break;
	  case 2:
	    agregaRegistro(listita);
	    break;
	  case 3:
	  	cout << "Ingrese al menos un fragmento del nombre o el apellido que busca: ";
	  	getline(cin, fragmento);
	  	cout << endl;
	  	buscaNomApeEnLista(listita, fragmento);
	    break;
	  case 4:
	    cout << "Ingrese el numero de Registro a Modificar: ";
	    cin >> pos;
	    cin.ignore();
	    cout << endl;
	    	if (pos < listita.contador)
			{
			    modificaRegistro(listita.elementos[pos]);
			}
			else
			{
				cout << "El Registro ingresado no existe." << endl;
			}

	    break;
	  case 5:
	    cout << "Ingrese el numero de Registro a Eliminar: ";
	    cin >> pos;
	    cin.ignore();
	    cout << endl;
	    eliminaRegistro(listita, pos);
	    break;
	  case 6:
	  	cout << endl;
	  	op = menuOrdenacion();
	  	ordenaListaPorIntercambio(listita,op);
	    break;
	  case 7:
	  	cout << endl;
	  	mostrarListaConNotas(listita);
	    break;
	  case 8:
	  	cout << endl;
	  	estadistica(listita);
	    break;
	}	
	cout << endl;
}


// ---------------   Funciones Estadisticas sobre Listas   -----------------


void estadistica(tLista& listita)
{
	cout << "---------------------------------------------------------------------" << endl ;
	cout << '|' << "                            ESTADISTICA                            " << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl;

	if(listita.contador > 0)
	{
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Media:            " << '|' << setw(6) << fixed << setprecision(2) << media(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Varianza:         " << '|' << setw(6) << fixed << setprecision(2) << varianza(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Desvio Estandard: " << '|' << setw(6) << fixed << setprecision(2) << desvio(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Nota Maxima:      " << "| " << setw(5) << maxima(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Nota Minima:      " << "| " << setw(5) << minima(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Moda:             " << "| " << setw(5) << moda(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Mediana:          " << "| " << setw(5) << medianaPorBurbuja(listita) << '|' << endl;
	}
	else
	{
		cout << '|' << "                             SIN DATOS                             " << '|' << endl;
	}

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
}


double media(tLista& listita)
{
	double acumula = 0;
	if(listita.contador > 0)
	{
		for (int i = 0; i < listita.contador; ++i)
		{
			acumula = acumula + listita.elementos[i].nota;
		}
	}
	else
	{
		cout << "No se han encontrado registros" << endl;
	}
	return (acumula/listita.contador);
}


double varianza(tLista& listita)
{
	double med = media(listita);
	double sigma2 = 0;

	for (int i = 0; i < listita.contador; ++i)
	{
		sigma2 = sigma2 + ((listita.elementos[i].nota - med)*(listita.elementos[i].nota - med));
	}
	return sigma2;
}


double desvio(tLista& listita)
{
	return sqrt(varianza(listita));
}


int maxima(tLista& listita)
{
	int max = 0;

	if(listita.contador > 0)
	{
		for (int i = 0; i < listita.contador; ++i)
		{
			if(listita.elementos[i].nota > max)
			{
				max = listita.elementos[i].nota;
			}
		}
	}
	else
	{
		cout << "No se han encontrado registros" << endl;
	}

	return max;
}


int minima(tLista& listita)
{
	int min = 10;

	if(listita.contador > 0)
	{
		for (int i = 0; i < listita.contador; ++i)
		{
			if(listita.elementos[i].nota < min)
			{
				min = listita.elementos[i].nota;
			}
		}
	}
	else
	{
		cout << "No se han encontrado registros" << endl;
	}

	return min;
}


int moda(tLista& listita)
{
	int notas[11] = {};
	int max = 0, cant = 0;
	for (int i = 0; i < listita.contador; ++i)
	{
		notas[listita.elementos[i].nota]++;
	}
	for (int j = 0; j < 11; ++j)
	{
		if(notas[j] > max)
		{
			cant = notas[j]; // Lo que encuentra es el maximo de las cantidades de cada nota
			max = j;
		}
	}
	return max;
}


int* copiaNotas(tLista& listita)
{
	static int notas[Dimension] = {};
	for (int i = 0; i < listita.contador; ++i)
	{
		notas[i] = listita.elementos[i].nota;
	}
	return notas;
}


double medianaPorBurbuja(tLista& listita)
{
	double median;
	bool ordenado = false;
	int* notas = copiaNotas(listita);

	for (int j = (listita.contador - 1); ((j > 0) && !ordenado); j--)
	{
		ordenado = true;
		for (int k = 0; k < j; ++k)
		{
			if(notas[k] > notas[k+1] )
			{
				intercambio(notas[k], notas[k+1]);
				ordenado = false;
			}
		}
	}
	if((listita.contador % 2) == 0 )
	{
		median = 0.5*(notas[listita.contador/2] + notas[(listita.contador/2)-1]);
	}
	else
	{
		median =notas[listita.contador/2];
	}

	return median;
}

