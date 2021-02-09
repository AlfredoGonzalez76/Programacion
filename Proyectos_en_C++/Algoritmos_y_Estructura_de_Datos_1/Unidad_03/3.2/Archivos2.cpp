/*
Resolver y Realizar en c++ 


Crea un programa que vaya leyendo las frases que el usuario teclea y las guarde en un fichero de texto llamado “frasesDeBjarme.txt”. Terminará cuando la frase introducida sea "fin" (esa frase no deberá guardarse en el fichero).


Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla, con cada frase en una línea, con Interlineado.


Para el  Archivo del ejercicio (a) contar la cantidad de palabras que hay x línea, luego mostrar la cantidad total y el promedio de palabras x línea.


Para le archivo de “frasesDeBjarme.txt” indicar cual es la palabra mas Larga.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string mayuscula(string cadena);

void escribeFrases(ofstream &archiOut);

int main()
{
	ofstream archiSalida;
	string ruta, archiNom;

//	cin >> "Ingrese la ruta de acceso: ";
	ruta = "C://TestCpp//";

//	cin >> "Ingrese el nombre del archivo con el que va a trabajar: ";
	archiNom = "frasesDeBjarme.txt";

	archiSalida.open(ruta + archiNom);

	escribeFrases(archiSalida);

	archiSalida.close();

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

void escribeFrases(ofstream &archiOut)
{
	string frase;

	cout << "Ingrese una frase de Bjarme Stroustrup: ";
	getline(cin,frase);

	while ( mayuscula(frase) != "FIN" )
	{
		archiOut << frase << endl;
		cout << "Ingrese una frase de Bjarme Stroustrup: ";
		getline(cin,frase);
	}
}