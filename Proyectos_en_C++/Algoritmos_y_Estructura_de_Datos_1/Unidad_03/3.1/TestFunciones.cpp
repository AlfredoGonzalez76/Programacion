#include <iostream>
using namespace std;

void cubo(double &x);

int main()
{
	double y;

	cubo(y);

	cout << "El valor de 'y' es: " << y << endl;

	return 0;
}

void cubo(double &x)
{
	double z = 4;

	x = z;
}