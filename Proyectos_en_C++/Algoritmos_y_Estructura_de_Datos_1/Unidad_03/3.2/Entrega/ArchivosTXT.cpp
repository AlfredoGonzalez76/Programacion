/*
Resolver y Realizar en c++ 


Crea un programa que vaya leyendo las frases que el usuario teclea y las guarde en un fichero de texto llamado “frasesDeBjarme.txt”. Terminará cuando la frase introducida sea "fin" (esa frase no deberá guardarse en el fichero).


Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla, con cada frase en una línea, con Interlineado.


Para el  Archivo del ejercicio (a) contar la cantidad de palabras que hay x línea, luego mostrar la cantidad total y el promedio de palabras x línea.


Para el archivo de “frasesDeBjarme.txt” indicar cual es la palabra mas Larga.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string mayuscula(string cadena);

void escribeFrases(string rutaNom);

void leeFrases(string rutaNom);

void cuentaPalabras(string frase, string &palabra, int &cuentaPal);

void cuentaPalXLinea(string rutaNom, string &mayorPalabra, int &totalPalabras, int &linea);

int main()
{
//	ofstream archiSalida;
	string ruta, archiNom, mayorPal;
	int totalPalabras = 0, lineas = 0;

//	cin >> "Ingrese la ruta de acceso: ";
	ruta = "C://TestCpp//";

//	cin >> "Ingrese el nombre del archivo con el que va a trabajar: ";
	archiNom = "frasesDeBjarme.txt";

	escribeFrases(ruta + archiNom);

	leeFrases(ruta + archiNom);

	mayorPal = "";

	cuentaPalXLinea(ruta + archiNom, mayorPal, totalPalabras, lineas);

	cout << "El total de palabras del archivo es: " << totalPalabras << endl;

	cout << "La cantidad de lineas de texto (exceptuando el 'fin') es: " << lineas << endl;

	cout << "La palabra mas larga del texto es: " << mayorPal << " y su longitud es " << mayorPal.length() << endl;

	cout << "El promedio de palabras por linea es " << int(totalPalabras)/lineas << endl;

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


void cuentaPalabras(string frase, string &palabra, int &cuentaPal)
{
	int inicioPal = 0, finPal = 0, maxLength = 0;
	bool comienzo = false;

	palabra = "";
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
			if ((finPal-inicioPal+1) > maxLength)
			{
				maxLength = finPal-inicioPal+1;
				palabra = frase.substr(inicioPal,finPal-inicioPal+1);  // Encuentra la palabra mas larga de la linea
			}
		}
		else if (frase[i] == ' ' && !comienzo)
		{
		}
	}
}


void cuentaPalXLinea(string rutaNom, string &mayorPalabra, int &totalPalabras, int &linea)
{
	ifstream archiIn;
	string frase, palabra;
	int cantPal;

	archiIn.open(rutaNom);

	palabra = "";
	mayorPalabra = palabra;

	while ( ! archiIn.eof() )
	{
		cantPal = 0;

		getline(archiIn,frase);

		cuentaPalabras(frase, palabra, cantPal);

		totalPalabras = totalPalabras + cantPal;

		linea++;
		
		cout << "Linea: " << linea << ". Palabra mas larga: " << palabra << ". Longitud de " << '"' << palabra << '"' << ": " << palabra.length() << endl;

		if (palabra.length() > mayorPalabra.length())
		{
			mayorPalabra = palabra;
		}
	}
	--linea;
	archiIn.close();
}