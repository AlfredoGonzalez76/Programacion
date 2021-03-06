#include "Clases.h"

#include <stdlib.h>  // para system("pause")

#include <iostream>
using namespace std;

const int MAX = 5;

int main()
{
	Animal* animal[MAX] = {};  // Array de punteros nulos a la clase base
	char op;

	for (int i = 0; i < MAX; ++i)
	{
		do
		{
			cout << endl;
			cout << "1) Dar vida a un Cocodrilo." << endl;
			cout << "2) Dar vida a un Ganso." << endl;
			cout << "3) Dar vida a un Pelicano." << endl;
			cout << "4) Dar vida a un Murcielago." << endl;
			cout << "5) Dar vida a una Ballena." << endl;
			cout << "6) Dar vida a un Lobo Marino." << endl;
			cout << "Seleccione la opcion deseada: " ;
			cin >> op ;
			cin.ignore();
			cout << endl;
		} while ((op != '1') && (op != '2') && (op != '3') && (op != '4') && (op != '5') && (op != '6'));
		switch (op)
		{
			case '1':
				animal[i] = new Cocodrilo;
			break;
			case '2':
				animal[i] = new Ganso;
			break;
			case '3':
				animal[i] = new Pelicano;
			break;
			case '4':
				animal[i] = new Murcielago;
			break;
			case '5':
				animal[i] = new Ballena;
			break;
			case '6':
				animal[i] = new LoboMarino;
			break;
		}
		animal[i] -> Comer();
		animal[i] -> Dormir();
/*
		if ((op == '1') || (op == '2') || (op == '3'))
		{
			animal[i] -> ponerHuevos();
		}
		else
		{
			animal[i] -> Amamantar();
		}
*/
	}

	for (int i = 0; i < MAX; ++i)
	{
		delete animal[i];
	}

	system("pause");


	return 0;
}