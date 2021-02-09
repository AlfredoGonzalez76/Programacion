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

void escribeFrases(string rutaNom);

void leeFrases(string rutaNom);

int cuentaPalabras(string frase);

int cuentaPalXLinea(string rutaNom);

int main()
{
	ofstream archiSalida;
	string ruta, archiNom;

//	cin >> "Ingrese la ruta de acceso: ";
	ruta = "C://TestCpp//";

//	cin >> "Ingrese el nombre del archivo con el que va a trabajar: ";
	archiNom = "frasesDeBjarme.txt";

	escribeFrases(ruta + archiNom);

	leeFrases(ruta + archiNom);

	cout << "El total de palabras del archivo es: " << cuentaPalXLinea(ruta + archiNom) << endl;

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

void escribeFrases(string rutaNom)
{
	ofstream archiOut;
	string frase;

	archiOut.open(rutaNom);

	cout << "Ingrese una frase de Bjarme Stroustrup: ";
	getline(cin,frase);

	while ( mayuscula(frase) != "FIN" )
	{
		archiOut << frase << endl;
		cout << "Ingrese una frase de Bjarme Stroustrup: ";
		getline(cin,frase);
	}
	archiOut.close();
}

void leeFrases(string rutaNom)
{
	ifstream archiIn;
	string frase;

	archiIn.open(rutaNom);

	while ( ! archiIn.eof() )
	{		
		getline(archiIn,frase);

		cout  << frase << endl;

		cout << endl;
	}
	archiIn.close();
}



int cuentaPalabras(string frase)
{
	string palabra;
	int inicioPal = 0, finPal = 0, cuentaPal = 0;
	bool comienzo = false , final = false;

	for (int i = 0; i < frase.length(); ++i)
	{
		if (frase[i] != ' ' && !comienzo)
		{
			comienzo = true;
			cuentaPal++;
			inicioPal = i;
			finPal = i;
		}
		else if (frase[i] != ' ' && comienzo)
		{
			finPal = i;
		}
		else if (frase[i] = ' ' && comienzo)
		{
			comienzo = false;
			palabra = frase.substr(inicioPal,finPal-inicioPal-1);
			cout << palabra << endl;
		}
		else if (frase[i] == ' ' && !comienzo)
		{
		}
		
	}
	return cuentaPal;
}


int cuentaPalXLinea(string rutaNom)
{
	ifstream archiIn;
	string frase;
	int linea = 0, palabras = 0;

	archiIn.open(rutaNom);

	while ( ! archiIn.eof() )
	{		
		getline(archiIn,frase);

		linea++;

		palabras = palabras + cuentaPalabras(frase);

		cout << "La cantidad de palabras de la linea " << linea << " es " << cuentaPalabras(frase) << endl;
	}
	archiIn.close();

	return palabras;
}