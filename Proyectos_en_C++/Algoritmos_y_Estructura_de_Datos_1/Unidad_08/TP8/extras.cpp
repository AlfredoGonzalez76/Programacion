#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

#include "extras.h"
using namespace std;

// ---------------------   Funciones Extra   --------------------------

string mayuscula(string cadena)
{
	for (int i = 0; i < cadena.length(); ++i)
	{
		cadena[i] = toupper(cadena[i]);
	}
	return cadena;
}


bool In(string fragmento, string palabra)
{
	bool esta = false;
	int i = 0, j = 0, aciertos = 0;

	while((i < fragmento.length()) && (j < palabra.length()) && (aciertos < fragmento.length()))
	{
		if(fragmento[i] == palabra[j])
		{
			i++;
			j++;
			aciertos++;
		}
		else
		{
			i = 0;
			aciertos = 0;
			j++;
		}
	}
	esta = (aciertos == fragmento.length());

	return esta;
}


void intercambio(int& a, int& b)
{
	int aux;

	aux = a;
	a = b;
	b = aux;
}