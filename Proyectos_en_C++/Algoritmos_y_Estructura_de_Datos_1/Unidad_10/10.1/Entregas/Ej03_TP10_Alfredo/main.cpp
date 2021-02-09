#include "Rectangulo.h"

#include <iostream>
#include <stdlib.h>  // para system("pause")

using namespace std;

int main()
{
	Rectangulo rectangulo;
	float auxReal;

	cout << "Vamos a calcular el area y perimetro de un Rectangulo." << endl;
	cout << "\nIngrese la altura del Rectangulo: ";
	cin >> auxReal;
	cin.ignore();
	rectangulo.SetAltura(auxReal);

	cout << "\nIngrese la base del Rectangulo: ";
	cin >> auxReal;
	cin.ignore();
	rectangulo.SetBase(auxReal);
	
	cout << "\nEl area del Rectangulo es: " << rectangulo.area() << endl;

	cout << "\nEl perimetro del Rectangulo es: " << rectangulo.perimetro() << endl;

	system("pause");

	return 0;
}
