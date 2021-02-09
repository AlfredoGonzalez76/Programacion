#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	ofstream archivo;									      // Declara una variable de tipo ofstream

	archivo.open("C://TestCpp//TestEscritura.txt");           // Conecta la variable con el archivo de texto y lo Abre.

	archivo << "Primera vez que escribo un archivo en C++" ;  // Escribo un mensaje en el archivo

	archivo.close();                                          // Cierre


	return 0;
}
