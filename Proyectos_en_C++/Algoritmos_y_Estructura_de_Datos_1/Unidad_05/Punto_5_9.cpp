#include <iostream>
#include <iomanip>
using namespace std;

/*
ACLARACION: está claro que lo ideal aquí sería realizar una función diferente
para cada
*/
const int Dimension = 50;
typedef int tArray[Dimension];
typedef struct {
   tArray elementos;
   int contador;
} tLista;

tLista lista;


void mostrarLista(tLista& listita);

void rellenarHasta(tLista& listita, int tope);

void insertar(tLista& listita, int elemento, int posicion);

void borrar(tLista& listita, int posicion);


int main()
{
	int pos = 8;
	int numero = -5;
	int cotaSup = 20;

	/* Lleno en la lista tantos lugares como dice 'contador' */
	rellenarHasta(lista, cotaSup);
	mostrarLista(lista);


	/* Ahora inserto un elemento en la posicion 'pos' */
	insertar(lista, numero, pos);
	mostrarLista(lista);

	/* Ahora borro el elemento en la posicion 'pos' */
	borrar(lista, pos);
	mostrarLista(lista);


	return 0;
}


void mostrarLista(tLista& listita)
{
	cout << "\n La lista acutal es:" << endl;
	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "|" << setw(3) << listita.elementos[i] ;
	}
	cout << endl;
}


void rellenarHasta(tLista& listita, int tope)
/* Relleno la lista con una formula cualquiera solo para tener algunos elementos */
{
	for (int i = 0; i < tope; ++i)
	{
		listita.elementos[i] = 2*i;
		listita.contador++;
	}

}



void insertar(tLista& listita, int elemento, int posicion)
/* Inserta 'elemento' en el lugar 'posicion' de listita, actualiza el contador */
{
	int aux;

	if ((posicion < Dimension) && (posicion < listita.contador))
	{
		for (int i = listita.contador; i > posicion; i--)
		{
			listita.elementos[i] = listita.elementos[i-1];
		}
		listita.elementos[posicion] = elemento;
		listita.contador++;
	}
	else if((posicion < Dimension) && (posicion >= listita.contador))
	{
		listita.elementos[posicion] = elemento;
		listita.contador = posicion + 1;
	}
	else
	{
		cout << "Posicion fuera del rango de la lista." << endl;
	}
}

void borrar(tLista& listita, int posicion)
{
	if (posicion < listita.contador)
	{
		for (int i = posicion; i < listita.contador; ++i)
		{
			listita.elementos[i] = listita.elementos[i+1];
		}
		listita.contador--;
	}
}