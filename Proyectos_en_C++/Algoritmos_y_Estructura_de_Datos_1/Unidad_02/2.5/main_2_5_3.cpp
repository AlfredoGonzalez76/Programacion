#include <iostream>
using namespace std;

double funPot(double x, int n);

int main()
{
	double a;
	int p;

	cout << "Ingrese un numero real 'a' y un numero natural 'n' y calcularemos la potencia n-esima de a." << endl;
	cout << "Ingrese el valor real (base): ";
	cin >> a;

	cout << "Ingrese el numero natural (exponente): ";
	cin >> p;

	cout << "La potencia " << p << " de " << a << " da como resultado: " << funPot(a,p) << endl;

	return 0;
}

double funPot(double x, int n)
{
	double c;
	c = 1;
	int ind = 1;
	while (ind <= n)
	{
		c = c * x;
		ind++;
	}
	return c;
}