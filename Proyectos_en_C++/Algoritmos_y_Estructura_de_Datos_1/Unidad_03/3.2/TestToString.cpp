#include <iostream>
#include <string>

using namespace std;


string mayuscula(string cadena);

int main()
{
	string aux, palabra, compuesta;
	int numero;

	palabra = "MasterChef";

	cout << palabra.substr(2,3) << endl; 

	palabra = mayuscula(palabra);

	numero = 8;

	aux = to_string(8);

	compuesta = palabra + aux;

		if (palabra == "MASTERCHEF")
		{
			cout << "Tengo " << compuesta << " anios" << endl;
		}
		else
		{
			cout << "Los string funcionan como arreglos: " << compuesta[6] << endl;
		}

	return 0;
}

string mayuscula(string cadena)
{
	for (int i = 0; i < cadena.length(); ++i)
	{
		cadena[i] = toupper(cadena[i]);
	}
	return cadena;
}