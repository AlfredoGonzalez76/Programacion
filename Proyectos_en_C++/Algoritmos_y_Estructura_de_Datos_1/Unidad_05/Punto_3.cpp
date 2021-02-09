#include <iostream>
#include <iomanip>
using namespace std;

/*
ACLARACION: está claro que lo ideal aquí sería realizar una función diferente
para cada
*/

const int Dimension = 50;
typedef double tLista[Dimension];
tLista lista;

int contador = 20;


void mostrarLista(tLista& listita, int cont);

void rellenarHasta(tLista& listita, int cont);

void insertar(tLista& listita, double elemento, int posicion, int& cont);

void borrar(tLista& listita, int posicion, int& cont);


int main()
{
	int pos = 8;
	double numero = -5;

	/* Lleno en la lista tantos lugares como dice 'contador' */
	rellenarHasta(lista, contador);
	mostrarLista(lista, contador);


	/* Ahora inserto un elemento en la posicion 'pos' */
	insertar(lista, numero, pos, contador);
	mostrarLista(lista, contador);

	/* Ahora borro el elemento en la posicion 'pos' */
	borrar(lista, pos, contador);
	mostrarLista(lista, contador);


	return 0;
}


void mostrarLista(tLista& listita, int cont)
{
	cout << "\n La lista acutal es:" << endl;
	for (int i = 0; i < cont; ++i)
	{
		cout << "|" << setw(3) << listita[i] ;
	}
	cout << endl;
}


void rellenarHasta(tLista& listita, int cont)
/* Relleno la lista con una formula cualquiera solo para tener algunos elementos */
{
	for (int i = 0; i < cont; ++i)
	{
		listita[i] = 2*i;
	}

}



void insertar(tLista& listita, double elemento, int posicion, int& cont)
/* Inserta 'elemento' en el lugar 'posicion' de listita, actualiza el contador 'cont' */
{
	double aux;

	if ((posicion < Dimension) && (posicion < cont))
	{
		for (int i = cont; i > posicion; i--)
		{
			listita[i] = listita[i-1];
		}
		listita[posicion] = elemento;
		cont++;
	}
	else if((posicion < Dimension) && (posicion >= cont))
	{
		listita[posicion] = elemento;
		cont = posicion + 1;
	}
	else
	{
		cout << "Posicion fuera del rango de la lista." << endl;
	}
}

void borrar(tLista& listita, int posicion, int& cont)
{
	if (posicion < contador)
	{
		for (int i = posicion; i < cont; ++i)
		{
			listita[i] = listita[i+1];
		}
		cont--;
	}
}