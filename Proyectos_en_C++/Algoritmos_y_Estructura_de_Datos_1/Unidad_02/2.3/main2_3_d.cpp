#include <iostream>
using namespace std;

int main()
{
	double m, b, x;
	char rta;

	cout << "Vamos a dar la ecuacion de una recta dada la pendiente y ordenada al origen" << endl;
	cout << "Ingrese la pendiente: ";
	cin >> m;
	cout << "Ingrese la ordenada al origen: ";
	cin >> b;
	cout << "La ecuacion de la recta es:  y = " << m << " x + " << b << endl;

	cout << "Quiere calcular la imagen de algun valor de x? ";
	do
	{
		cin >> rta;
		rta = toupper(rta);
	}
	while ((rta != 'S') && (rta != 'N'));
	if (rta == 'S')
	{
		cout << "Ingrese el valor de x al que le quiere calcular la imagen: ";
		cin >> x;
		cout << "La imagen de " << x << " es " << m*x+b << endl;
	}
	
	return 0;
}