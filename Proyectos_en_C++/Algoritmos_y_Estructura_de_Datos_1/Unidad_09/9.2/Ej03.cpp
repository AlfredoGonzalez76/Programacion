#include <iostream>
#include <ctype.h> // para toupper

using namespace std;

/*
Pedir al usuario N números, almacenarlos en un arreglo dinámico 
posteriormente ordenar los números en orden ascendente y mostrarlos
en pantalla.NOTA: Utilizar cualquier método de ordenamiento.
*/

typedef int* tIntPtr;

// Lista "dinámica": array dinámico (puntero) y contador
typedef struct {
	tIntPtr elementos;
	int contador;
} tLista;



// ----------- Declaracion de Funciones -------------

tLista crearArrayDin();

void muestraArrayDin(tLista& listita);

void ordenaListaPorIntercambio(tLista& listita);

void eliminaArrayDin(tLista& listita);

// ---------------  PRINCIPAL  ---------------

int main()
{
	tLista lista;

	lista = crearArrayDin();

	cout << endl;

	muestraArrayDin(lista);

	cout << endl;

	ordenaListaPorIntercambio(lista);

	cout << endl;

	muestraArrayDin(lista);

	eliminaArrayDin(lista);

	return 0;
}

// ---------- Implementacion de Funciones -----------


tLista crearArrayDin()
{
	int N, i = 0;
	char rta = 'S';
	tLista listita;

	cout << "Ingrese la cantidad de números a almacenar: ";
	cin >> N;
	cin.ignore();

	listita.elementos = new int[N];
	listita.contador = 0;

	do
	{
		cout << endl;
		cout << "Desea introducir datos en la lista? (S/N) ";
		cin >> rta;
		cin.ignore();
		if (toupper(rta)=='S')
		{
			cout << "Ingrese un numero entero: ";
			cin >> listita.elementos[listita.contador];
			cin.ignore();
			listita.contador++;
		}
	}while((toupper(rta)!='N') && (listita.contador < N));

	return listita;
}


void muestraArrayDin(tLista& listita)
{
	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "El elemento " << i+1 << " de la lista es " << listita.elementos[i] << endl;
	}
}




void ordenaListaPorIntercambio(tLista& listita)
{
	tIntPtr aux = new int;

	for (int i = 0; i < (listita.contador - 1); ++i)
	{
		for (int j = i+1; j < listita.contador; ++j)
		{
			if(listita.elementos[i] > listita.elementos[j])
			{
				*aux = listita.elementos[j];
				listita.elementos[j] = listita.elementos[i];
				listita.elementos[i] = *aux;
			}
		}
	}
}


void eliminaArrayDin(tLista& listita)
{
	delete [] listita.elementos;

	listita.contador = 0;

}