#include <iostream>
#include <ctype.h> // para toupper

using namespace std;

// Rellenar un arreglo con n números, posteriormente utilizando punteros determinar el menor elemento del vector. 

const int CANTIDAD = 100;

typedef int tArray[CANTIDAD];

typedef struct {
	tArray elementos;
	int cont;
} tLista;

typedef int* tIntPtr;

tLista lista;

// ----------- Declaracion de Funciones -------------

void encuentraMenor(tLista& listita);

void rellena(tLista& listita);

// ---------------  PRINCIPAL  ---------------

int main()
{

	rellena(lista);

	encuentraMenor(lista);

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



void encuentraMenor(tLista& listita)
{
	tIntPtr punt;
	int ind = 0;
	int menor, ubicacion;

	punt = listita.elementos;  // Esto es xq el nombre del array es un puntero al primer elemento

	if (listita.cont > 0)
	{
		menor = *punt; // Comienzo tomando el primer elemento como el menor
		ind++;
		punt++;
	}
	else
	{
		cout << "La lista esta vacia." << endl;
	}

	while(ind < listita.cont)
	{
		if(*punt < menor)
		{
			menor = *punt;
			ubicacion = ind + 1;
		}
		punt++;
		ind++;
	}
	cout << "El menor elemento de la lista es el " << menor << " y su ubicacion es el lugar " << ubicacion << endl;
}