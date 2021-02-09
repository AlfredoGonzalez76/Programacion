#include <iostream>
using namespace std;

/* Escriba una función nombrada cambio() que tenga un parámetro
 en número entero en pesos y devuelva el valor en dólares. */

void cambio(int pesos, int &dolares, int cotizac, int &vuelto);

int main()
{
	int p, c, d = 0 ,v = 0;
	cout << "Ingrese un monto en pesos para transformar a dolares: ";
	cin >> p;

	cout << "Ingrese la cotizacion del dolar: ";
	cin >> c;

	cambio(p, d, c, v);

	cout << "Con " << p << " pesos usted puede comprar " << d << " dolares y le sobran " << v << " pesos." << endl;

	return 0;
}

void cambio(int pesos, int &dolares, int cotizac, int &vuelto)
{
	dolares = pesos / cotizac;
	vuelto = pesos % cotizac;
}