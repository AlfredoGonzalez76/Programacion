#include <iostream>
using namespace std;

double producto(double a, double b);

int main()
{
	double x, y;

	cout << "Se pedira el ingreso por teclado de dos numeros reales" << endl;
	cout << "Ingrese el primer valor: ";
	cin >> x;

	cout << "Ingrese el segundo valor: ";
	cin >> y;

	cout << "El producto de " << x << " y " << y << " da como resultado: " << producto(x,y) << endl;

	return 0;
}

double producto(double a, double b)
{
	double c;
	c= a * b;
	return c;
}