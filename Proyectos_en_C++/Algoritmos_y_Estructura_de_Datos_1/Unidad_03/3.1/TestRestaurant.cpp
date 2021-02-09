#include <iostream>
using namespace std;


int eligeMesa();

int main()
{
	typedef enum { Juan, Vanesa, Martin, Maria } tMozo;

	int mesa;

	mesa = eligeMesa();

	tMozo mozo = tMozo((mesa-1)/6);  // De este modo asigna equitativamente las mesas a los mozos

	cout << "La mesa elegida fue la numero " << mesa << endl;

	cout << "El mozo elegido es: " << mozo << endl;

	return 0;
}

int eligeMesa()
{
	int op;
	cout << "Ingrese un nro. de mesa ( 1 - 24 ): ";
	do
	{
		cin >> op;
	}
	while ( (op < 1) || (op > 24) );
}