#include <iostream>
using namespace std;


int main()
{
	int etapa;
	int puntaje = 0;

	cout << "Indique hasta que nivel llego el jugador (1-5): ";
	cin >> etapa;

	switch (etapa)
	{
		case 5 :
		{
			puntaje += 500;
		}
		case 4 :
		{
			puntaje += 400;
		}
		case 3 :
		{
			puntaje += 300;
		}
		case 2 :
		{
			puntaje += 200;
		}
		case 1 :
		{
			puntaje += 100;
		}
	}
	cout << "El puntaje acumulado es: " << puntaje << endl;

	return 0;
}