#include "Articulo.h"
#include <iostream>

using namespace std;

int main()
{
	Articulo articulo;
	float costoB;

	cout << "\nIngrese el costo base del articulo: ";
	cin >> costoB;
	cin.ignore();

	articulo.SetCostoBase(costoB);

	cout << "\nEl Precio de Venta por Mayor es: " << articulo.PVPMayor() << endl;

	cout << "\nEl Precio de Venta al Detal es: " << articulo.PVPDetal() << endl;

	return 0;
}