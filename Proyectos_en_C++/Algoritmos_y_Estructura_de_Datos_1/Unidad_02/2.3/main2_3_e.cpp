#include <iostream>
using namespace std;

int main()
{
	double m, b, x, x1, x2, y1, y2;
	char rta;

	cout << "Vamos a dar la ecuacion de una recta dados dos puntos de la misma." << endl;
	cout << "Ingrese la coordenada x del primer punto: ";
	cin >> x1;
	cout << "Ingrese la coordenada y del primer punto: ";
	cin >> y1;
	cout << "Ingrese la coordenada x del segundo punto: ";
	cin >> x2;
	cout << "Ingrese la coordenada x del segundo punto: ";
	cin >> y2;
	if (x1 == x2)
	{
		cout << "La ecuacion de la recta es:  x = " << x1 << endl;
	}
	else
	{
		m = (y2 - y1)/(x2 - x1);
		b = y1 - m * x1;
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
	}
	return 0;
}