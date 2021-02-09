#include "Clases.h"

#include <stdlib.h>  // para system("pause")

#include <iostream>
#include <string>
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
			cout << "6) Dar vida a un Lobo Marino." << endl << endl;
			cout << "Seleccione la opcion deseada: " ;
			cin >> op ;
			cin.ignore();
			cout << endl;
		} while ((op != '1') && (op != '2') && (op != '3') && (op != '4') && (op != '5') && (op != '6'));
		switch (op)
		{
			case '1':
				animal[i] = new Cocodrilo("Cocodrilo",21);
			break;
			case '2':
				animal[i] = new Ganso("Ganso",22);
			break;
			case '3':
				animal[i] = new Pelicano("Pelicano",23);
			break;
			case '4':
				animal[i] = new Murcielago("Murcielago",24);
			break;
			case '5':
				animal[i] = new Ballena("Ballena",25);
			break;
			case '6':
				animal[i] = new LoboMarino("Lobo Marino",26);
			break;
		}
		animal[i] -> Comer();
		animal[i] -> Dormir();

		if (animal[i] -> ponerHuevos())
		{
			cout << "Se trata de un Oviparo" << endl;
		}
		else
		{
			cout << "Se trata de un Mamifero" << endl;
		}

	}
	for (int i = 0; i < MAX; ++i)
	{
		delete animal[i];
	}

	system("pause");

	return 0;
}