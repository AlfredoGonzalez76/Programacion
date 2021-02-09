#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string nif, producto;
	char caracter;
	int unidades;
	double precio;
	char aux;

	fstream archivo;

	archivo.open("C://TestCpp//TestLectura2.txt");         // Apertura

	archivo >> nif >> unidades >> precio;

	cout << nif <<endl;
	cout << unidades << endl;
	cout << precio << endl;

	archivo.get(caracter);
	getline(archivo, producto);
	cout << producto << endl;

	archivo.close(); // Cierre


	return 0;
}
