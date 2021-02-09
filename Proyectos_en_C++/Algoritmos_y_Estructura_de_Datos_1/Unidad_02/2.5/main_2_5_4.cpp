#include <iostream>
using namespace std;

#include <cmath>

/* Escriba un programa en C++ que devuelva la parte fraccionaria de
cualquier número  introducido por el usuario. Por ejemplo, si se
introduce el número 256.879, debería desplegarse el número 0.879. */


double funMantisa(double x);

int main()
{
	double a;

	cout << "Ingrese un numero real al que calcularemos su mantisa: ";
	cin >> a;

	cout << "La mantisa de " << a << " es: " << funMantisa(a) << endl;

	return 0;
}

double funMantisa(double x)
{
	double c;
	c = x - floor(x);
	int ind = 1;
	return c;
}