#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string nif, producto;
	int unidades;
	double precio;
	char aux;

	fstream archivo;									   // Declara una variable de tipo fstream

	archivo.open("C://TestCpp//TestLectura2.txt");         // Conecta la variable con el archivo de texto y lo Abre.

	archivo >> nif;
	archivo >> unidades;
	archivo >> precio;
	archivo.get(aux); 									   // Salta el espacio en blanco
	getline(archivo, producto);

	// Con las proximas 4 filas vemos por pantalla el resultado de lo efectuado.
	cout << nif <<endl;
	cout << unidades << endl;
	cout << precio << endl;
	cout << producto << endl;

	archivo.close();                                       // Cierre


	return 0;
}
