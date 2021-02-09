#include <iostream>
#include <ctype.h> // para toupper

using namespace std;

// Rellenar un array de 10 números, posteriormente utilizando punteros indicar cuales son números pares y su posición en memoria.

const int CANTIDAD = 100;

typedef int tArray[CANTIDAD];

typedef struct {
	tArray elementos;
	int cont;
} tLista;

typedef int* tIntPtr;

tLista lista;

// ----------- Declaracion de Funciones -------------

void buscaPar(tLista& listita);

void rellena(tLista& listita);

// ---------------  PRINCIPAL  ---------------

int main()
{

	rellena(lista);

	buscaPar(lista);

	return 0;
}

// ---------- Implementacion de Funciones -----------


void rellena(tLista& listita)
{
	char rta;

	do
	{
		cout << "Desea introducir datos en la lista? (S/N) ";
		cin >> rta;
		cin.ignore();
		if (toupper(rta)=='S')
		{
			cout << "Ingrese un numero entero: ";
			cin >> listita.elementos[listita.cont];
			cin.ignore();
			listita.cont++;
		}

	}while(toupper(rta)!='N');
}



void buscaPar(tLista& listita)
{
	tIntPtr punt;
	int ind = 0;

	punt = listita.elementos;  // Esto es xq el nombre del array es un puntero al primer elemento

	while(ind < listita.cont)
	{
		if((*punt % 2) == 0)
		{
			cout << "El elemento en el lugar " << ind+1 << " de la lista es par y su posicion en memoria es " << punt << endl;
		}
		punt++;
		ind++;
	}

}