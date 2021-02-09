#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream archiFile;   // Declaro una variable de tipo ifstream para lectura de datos desde archivo

	string linea1, linea2, linea3;

	archiFile.open("C://TestCpp//TestLectura1.txt");  // Asocio la variable de tipo ifstream con el archivo fisico

	if (archiFile.is_open())           // Averiguo si el archivo se pudo abrir correctamente
	{
		getline(archiFile,linea1);
		getline(archiFile,linea2);
		getline(archiFile,linea3);
	}

	cout << "LINEA 1: " << linea1 << endl;
	cout << "LINEA 2: " << linea2 << endl;
	cout << "LINEA 3: " << linea3 << endl;

	archiFile.close();           //  Cierro el archivo

	return 0;
}