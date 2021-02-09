#include <iostream>
using namespace std;


double al_cuadrado(double x);

int main()
{
	double num;

	cout << "Ingrese un numero real para elevar al cuadrado: ";
	cin >> num;

	cout << "El cuadrado de " << num << " es: " << al_cuadrado(num) << endl;

	return 0;
}


double al_cuadrado(double x)
{
	double y;
	y = x*x;
	return y;
}
