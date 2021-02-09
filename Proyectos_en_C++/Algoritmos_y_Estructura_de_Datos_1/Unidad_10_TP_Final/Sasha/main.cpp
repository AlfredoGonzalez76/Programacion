#include <iostream>
#include <string>
using namespace std;

#include "header.h"

int main()
{
	int menu;

	const int N = 5;
	Animal *puntAnimal[N];
	int cont = 0;

	do
	{
		cout << "Animales en la lista: " << cont << endl;
		cout << endl;
		cout << "1. Ingresar animal a la lista" << endl;
		cout << "2. Dar de comer" << endl;
		cout << "3. Dormir" << endl;
		cout << "4. Reproducirse" << endl;
		cout << endl;
		cout << "0. Salir" << endl;
		cout << endl;
		cout << " -> ";
		cin >> menu;
		cin.ignore();
		cout << endl;

		switch(menu)
		{
			case 1:

			cout << "Escoja el animal a ingresar: " << endl;
			cout << "1. Cocodrilo" << endl;
			cout << "2. Ganso" << endl;
			cout << "3. Pelicano" << endl;
			cout << "4. Murcielago" << endl;
			cout << "5. Ballena" << endl;
			cout << "6. Leon Marino" << endl;
			cout << endl;
			cout << " -> ";
			cin >> menu;
			cin.ignore();
			cout << endl;

			switch(menu)
			{
				case 1:

				if(cont<5)
				{
					puntAnimal[cont] = new Crocodile();
				    puntAnimal[cont] -> setName();
				    puntAnimal[cont] -> setCode(menu);
				    cont++;
				}
				else
				{
					cout << "El arreglo esta lleno." << endl;
				}

				break;
				case 2:

				if(cont<5)
				{
					puntAnimal[cont] = new Goose();
				    puntAnimal[cont] -> setName();
				    puntAnimal[cont] -> setCode(menu);
				    cont++;
				}
				else
				{
					cout << "El arreglo esta lleno." << endl;
				}

				break;
				case 3:

				if(cont<5)
				{
					puntAnimal[cont] = new Pelican();
				    puntAnimal[cont] -> setName();
				    puntAnimal[cont] -> setCode(menu);
				    cont++;
				}
				else
				{
					cout << "El arreglo esta lleno." << endl;
				}

				break;
				case 4:

				if(cont<5)
				{
					puntAnimal[cont] = new Bat();
				    puntAnimal[cont] -> setName();
				    puntAnimal[cont] -> setCode(menu);
				    cont++;
				}
				else
				{
					cout << "El arreglo esta lleno." << endl;
				}

				break;
				case 5:

				if(cont<5)
				{
					puntAnimal[cont] = new Whale();
				    puntAnimal[cont] -> setName();
				    puntAnimal[cont] -> setCode(menu);
				    cont++;
				}
				else
				{
					cout << "El arreglo esta lleno." << endl;
				}

				break;
				case 6:

				if(cont<5)
				{
					puntAnimal[cont] = new SeaLion();
				    puntAnimal[cont] -> setName();
				    puntAnimal[cont] -> setCode(menu);
				    cont++;
				}
				else
				{
					cout << "El arreglo esta lleno." << endl;
				}

				break;
				default:

				cout << "No ingreso una opcion valida. Vuelva a intentar..." << endl;
				cout << endl;
			}

			cout << endl;

			break;
			case 2:

			for(int i = 0; i<cont ; i++)
			{
				cout << "Animal Nro: " << i << endl;
				puntAnimal[i] -> getTipe();
				cout << "Nombre del animal: ";
				puntAnimal[i] -> getName();
				cout << endl;
				puntAnimal[i] -> eat();
				cout << endl;
			}

			break;
			case 3:

			for(int i = 0 ; i<cont ; i++)
			{
				cout << "Animal Nro: " << i << endl;
				puntAnimal[i] -> getTipe();
				cout << "Nombre del animal: ";
				puntAnimal[i] -> getName();
				cout << endl;
				puntAnimal[i] -> sleep();
				cout << endl;
			}

			break;
			case 4:

			for(int i = 0 ; i<cont ; i++)
			{
				puntAnimal[i] -> getName();
				cout << " ";
				puntAnimal[i] -> toBreed();
			}

			break;
			case 0:

			cout << "El programa se esta cerrando..." << endl;
			cin.get();
			for(int i =0; i<N ; i++)
			{
				delete puntAnimal[i];
			}
			
			break;
			default:

			cout << "No ingreso una opcion valida. Vuelva a instentar..." << endl;
		}
	}while(menu!=0);

	return 0;
}
