//*************************************************************
// ARCHIVO PRINCIPAL (main.cpp)
// Este archivo manipula tipos de datos abstractos de tipo
// Figura, Circulo, Rectangulo y Triangulo
//*************************************************************

#include "Figura.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"

#include <stdlib.h>  // para system("pause")

#include <iostream>
using namespace std;

int main()
{
	Figura* elemento[5] = {};  // Array de punteros nulos a la clase base
	char op;

	for (int i = 0; i < 5; ++i)
	{
		do
		{
			cout << endl;
			cout << "1) Crear Figura." << endl;
			cout << "2) Crear Circulo." << endl;
			cout << "3) Crear Rectangulo." << endl;
			cout << "4) Crear Triangulo." << endl;
			cout << "Pulse la opcion deseada: " ;
			cin >> op ;
			cin.ignore();
			cout << endl;
		} while ((op != '1') && (op != '2') && (op != '3') && (op != '4'));
		switch (op)
		{
			case '1':
				elemento[i] = new Figura;
			break;
			case '2':
				elemento[i] = new Circulo;
			break;
			case '3':
				elemento[i] = new Rectangulo;
			break;
			case '4':
				elemento[i] = new Triangulo;
			break;
		}
		elemento[i] -> dibujar();
		elemento[i] -> borrar();
	}

	for (int i = 0; i < 5; ++i)
	{
		delete elemento[i];
	}

//	delete [] elemento ;

	system("pause");


	return 0;
}