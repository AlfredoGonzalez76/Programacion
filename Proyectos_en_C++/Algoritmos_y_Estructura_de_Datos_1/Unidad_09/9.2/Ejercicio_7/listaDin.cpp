#include <iostream>
#include <iomanip>
#include <string>

#include "listaDin.h"
#include "registroDin.h"

using namespace std;



tListaDin crearListaDin() // Crea una lista de punteros a registros
{
	int N;
	tListaDin listita;

	cout << "Ingrese la cantidad MAXIMA de registros a almacenar: ";
	cin >> N;
	listita.maximo = N;
	cin.ignore();

	listita.elementos = new tRegPtr[N];
	listita.contador = 0;

	return listita;
}


void cargaListaDin(tListaDin& listita)
{
	char rta;
	do
	{
		cout << endl;
		cout << "Desea introducir nuevos registros en la lista? (S/N) ";
		cin >> rta;
		cin.ignore();
		if ((toupper(rta)=='S')&&(listita.contador < listita.maximo))
		{
			listita.elementos[listita.contador] = nuevoRegistro();
			listita.contador++;
		}
	}while((toupper(rta)!='N') && (listita.contador < listita.maximo));
}


void muestraListaDin(tListaDin& listita)
{
	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "El elemento " << i+1 << " de la lista es " << endl;
		muestraRegistroCompleto(listita.elementos[i]);
	}
}


void eliminaListaDin(tListaDin& listita)
{
	for (int i = 0; i < listita.contador; ++i)
	{
		eliminaRegistro(listita.elementos[i]);
	}
	listita.contador = 0;

	delete [] listita.elementos;

}


// ------------- Funciones Sobre Listas ---------------


void maximaNota(tListaDin& listita)
{
	int max = 0, ind;

	if(listita.contador > 0)
	{
		for (int i = 0; i < listita.contador; ++i)
		{
			if(listita.elementos[i]->nota > max)
			{
				max = listita.elementos[i]->nota;
				ind = i;
			}
		}
	}
	else
	{
		cout << "No se han encontrado registros" << endl;
	}

	cout << "El alumno con la nota mas alta es: " << endl;

	muestraRegistroCompleto(listita.elementos[ind]);
}
