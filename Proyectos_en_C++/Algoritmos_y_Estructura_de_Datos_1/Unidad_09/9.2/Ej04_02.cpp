#include <iostream>
#include <ctype.h> // para toupper

using namespace std;

/*
Pedir una cadena de caracteres (string) al usuario, e indicar
cuantas veces aparece la vocal a,e,i,o,u; en la cadena de caracteres.
NOTA: Usar punteros 
*/


typedef int tCuentaVoc[5];



string ingresaFrase();

void cuentaVocales(string frase);



int main()
{
	string palabra = ingresaFrase();

	cuentaVocales(palabra);

	return 0;
}

string ingresaFrase()
{
	string frase;

	cout << "Ingrese una frase: " << endl;
	getline(cin, frase);

	return frase;
}

void cuentaVocales(string frase)
{
	tCuentaVoc vec = {};
	string* punt = &frase;

	for (int i = 0; i < frase.length(); ++i)
	{
//		switch(toupper(*punt))
		switch(toupper(punt->at(i)))
		{
			case 'A':
				vec[0]++;
			break;

			case 'E':
				vec[1]++;
			break;

			case 'I':
				vec[2]++;
			break;

			case 'O':
				vec[3]++;
			break;

			case 'U':
				vec[4]++;
			break;
		}
	}
	cout << endl;
	cout << "La frase '" << frase << "' tiene: " << endl;
	cout << vec[0] << " letras 'A'" << endl;
	cout << vec[1] << " letras 'E'" << endl;
	cout << vec[2] << " letras 'I'" << endl;
	cout << vec[3] << " letras 'O'" << endl;
	cout << vec[4] << " letras 'U'" << endl;
}
