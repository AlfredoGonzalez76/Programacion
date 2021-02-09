#include "Caja.h"

#include <iostream>
#include <stdlib.h>  // para system("pause")

using namespace std;


int main()
{
	Caja unaCaja(0.57, 0.25, 0.55);

	cout << "Volumen de la caja: " << unaCaja.Volumen() << " metros cubicos." << endl;

	system("pause");

	return 0;
}