#include <iostream>
#include <iomanip>

using namespace std;

/*  Escribe un programa que lea del teclado una frase y a continuación visualice las
palabras de la frase en columna, seguida cada una del número de letras que la componen.  */

const int Dimension = 5000;

typedef string tStringArray[Dimension];
typedef int tLongitud[Dimension];

typedef struct {
   tStringArray palabra;
   tLongitud longitud;
   int contador;
} tLista;

tLista cuentaPalabras(string frase);

void muestraLista(tLista& listita);


int main()
{
	tLista lista;
	string frase;

	cout << "Ingrese una frase: ";
	getline(cin,frase);
	frase += ' ';

	lista = cuentaPalabras(frase);

	muestraLista(lista);

	return 0;
}


tLista cuentaPalabras(string frase)
{
	tLista listita;
	int inicioPal = 0, finPal = 0;
	bool comienzo = false;
	listita.contador = 0;

	for (int i = 0; i < frase.length(); ++i)
	{
		if (frase[i] != ' ' && !comienzo)
		{
			comienzo = true;
			inicioPal = i;
			finPal = i;
		}
		else if (frase[i] != ' ' && comienzo)
		{
			finPal = i;
		}
		else if ((frase[i] = ' ') && comienzo)
		{
			comienzo = false;

			listita.palabra[listita.contador] = frase.substr(inicioPal,finPal-inicioPal+1);  // Encuentra la palabra mas larga de la linea

			listita.longitud[listita.contador] = listita.palabra[listita.contador].length();

			listita.contador++;

		}
		else if (frase[i] == ' ' && !comienzo)
		{
		}
	}

	return listita;
}


void muestraLista(tLista& listita)
{
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl ;
	cout << '|' << "                            RESULTADOS                             " << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "|                         Palabra                        | Longitud |" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "| " << setw(55) <<setiosflags(ios::left) << listita.palabra[i] << "|    " << setw(6) << listita.longitud[i] << '|' << endl;
	}
	cout << "---------------------------------------------------------------------" << endl;

}