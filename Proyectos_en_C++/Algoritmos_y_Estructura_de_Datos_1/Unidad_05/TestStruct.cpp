#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

//--------------  Tipos de datos Introducidos  -----------------

const int Dimension = 50;

typedef struct {
   string nombres;
   string apellidos;
   int edad;
   int dni;
   int nota;
} tEstudiante;


typedef tEstudiante tArray[Dimension];

typedef struct {
   tArray elementos;
   int contador;
} tLista;

tLista cargaLista();
string mayuscula(string cadena);

int main()
{
	tLista lista ;
	ifstream flujoIn;

//	lista = cargaLista();

	flujoIn.open("AyEDI.txt");

	lista.contador = 0;
	string linea;
	int auxInt;
	while ( ! flujoIn.eof() )
	{		
		getline(flujoIn,linea);
		lista.elementos[lista.contador].nombres  = linea ;

		getline(flujoIn,linea);
		lista.elementos[lista.contador].apellidos  = linea ;
		
		getline(flujoIn,linea);
		auxInt = atoi(linea.c_str());
		lista.elementos[lista.contador].edad  = auxInt ;

		getline(flujoIn,linea);
		auxInt = atoi(linea.c_str());
		lista.elementos[lista.contador].dni  = auxInt ;

		getline(flujoIn,linea);
		auxInt = atoi(linea.c_str());
		lista.elementos[lista.contador].nota  = auxInt ;

		lista.contador++;
	}

	for (int i = 0; i < Dimension; ++i)
	{
		cout << "Nombres: " << lista.elementos[i].nombres << endl;
		cout << "Apellidos: " << lista.elementos[i].apellidos << endl;
		cout << "Edad: " << lista.elementos[i].edad << endl;
		cout << "DNI: " << lista.elementos[i].dni << endl;
		cout << "nota: " << lista.elementos[i].nota << endl;
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


tLista cargaLista()
{
	tLista listita;

	for (int i = 0; i < Dimension; ++i)
	{
		listita.elementos[i].nombres = "Juan Carlos";
		listita.elementos[i].apellidos = "Garcia";
		listita.elementos[i].edad = 22;
		listita.elementos[i].dni = 23 + i;
		listita.elementos[i].nota = 9;
	}
	
	return listita;
}


bool In(string fragmento, string palabra)
{
	bool esta = false;
	int i = 0, j = 0, aciertos = 0;

	while((i < fragmento.length()) && (j < palabra.length()) && (aciertos < fragmento.length()))
	{
		if(fragmento[i] == palabra[j])
		{
			i++;
			j++;
			aciertos++;
		}
		else
		{
			i = 0;
			aciertos = 0;
			j++;
		}
	}
	esta = (aciertos == fragmento.length());

	return esta;
}


tLista buscaRegistros(tLista& listita, string fragmento)
{

	for (int i = 0; i < listita.contador; ++i)
	{
		if(In(mayuscula(fragmento),mayuscula(listita.elementos[i].nombres)) || In(mayuscula(fragmento),mayuscula(listita.elementos[i].nombres)))
		{
			
		}

	}

}

void estadistica(tLista listita)
{
	double media, mediana, desvio;
	moda;

	cout << "---------------------------------" << endl;
	cout << '|' << "           ESTADISTICA          " << '|' << endl;
	cout << "---------------------------------" << endl;
	cout << '|' << setw(30) <<setiosflags(ios::left) << " Media: " << '|' << media(listita) << '|' << endl;
	cout << '|' << setw(30) <<setiosflags(ios::left) << " Mediana: " << '|' << mediana(listita) << '|' << endl;
	cout << '|' << setw(30) <<setiosflags(ios::left) << " Moda: " << '|' << moda(listita) << '|' << endl;
	cout << '|' << setw(30) <<setiosflags(ios::left) << " Desvio Estandard " << '|' << desvio(listita) << '|' << endl;
	cout << "--------------------------------" << endl;
}

double media(tLista& listita)
{
	double acumula = 0;
	for (int i = 0; i < listita.contador; ++i)
	{
		acumula = acumula + listita.elementos[i].nota;
	}
	return (acumula/listita.contador);
}

double varianza(tLista& listita)
{
	double med = media(listita);
	double sigma2 = 0;

	for (int i = 0; i < listita.contador; ++i)
	{
		sigma2 = sigma2 + ((listita.elementos[i].nota - med)*(listita.elementos[i].nota - med));
	}
	return sigma2;
}

int maxima(tLista listita)
{
	int max = 0;

	for (int i = 0; i < listita.contador; ++i)
	{
		if(listita.elementos[i].nota > max)
		{
			max = listita.elementos[i].nota;
		}
	}
	return max;
}

double moda(tLista listita)
{
	int notas[11] = {};
	for (int i = 0; i < listita.contador; ++i)
	{
		notas[listita.elementos[i].nota]++;
	}
	
}