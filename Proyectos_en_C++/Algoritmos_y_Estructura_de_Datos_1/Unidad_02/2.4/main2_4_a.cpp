#include <iostream>
using namespace std;

/* Hacer un programa en C++ para un bazar que tiene una promo de descuento para vender al mayor,
esta dependerá del número de Productos que se compren. Si son más de diez, se les dará un 12% de
descuento sobre el total de la compra; si el número de productos es mayor de veinte pero menor de
treinta, se le otorga un 25% de descuento; y si son más treinta productos de le otorgará un 40%
de descuento. El precio de cada producto es de  $80. */

main()
{
	int cantidad;
	double precioTot, precioUnit = 80;

	cout << "Ingrese la cantidad de productos que desea comprar: ";
	cin >> cantidad;
	precioTot = precioUnit * cantidad;

	if (( cantidad > 10 ) && ( cantidad <=20 ))
	{
		precioTot = precioTot * 0.88;
	}
	else if (( cantidad > 20 ) && ( cantidad < 30 ))
	{
		precioTot = precioTot * 0.75;
	}
	else if ( cantidad > 30 )
	{
		precioTot = precioTot * 0.6;
	}

	cout << "El total a pagar es: " << precioTot << endl;

	return 0;
}