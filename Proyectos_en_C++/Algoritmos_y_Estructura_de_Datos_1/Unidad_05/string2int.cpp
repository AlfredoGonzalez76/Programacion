#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;


int char2int(char caracter);
int string2int(string word);


int main()
{
	string prueba = "123456";
	int testCifra;
	int testNum;

	testCifra = char2int('2');
	cout << "La cifra es: " << testCifra << endl;

	testNum = string2int("123456");
	cout << "El numero elegido es: " << testNum << endl;

	cout << "El numero elegido es: " << atoi(prueba.c_str()) << endl;

	return 0;
}


int char2int(char caracter)
{
	int numero;

	numero = ((int(caracter)) - (int('0'))) ;

	return numero;
}

/*
int string2int(string word)
{
	int numero = 0, cifra = 0; 

	for (int i = (word.length()-1); i >= 0 ; --i)
	{
		cifra = char2int(word[i])*pow(10,(word.length()-1-i));
		numero = numero + cifra;
	}
	return numero;
}
*/


int string2int(string word)
{
	int numero = 0, cifra = 0; 

	for (int i = 0; i < word.length(); ++i)
	{
		cifra = char2int(word[(word.length()-1-i)]) * pow(10,i);
		cout << "Coeficiente de 10 elevado a la potencia " << i << ": " << cifra << endl;

		numero = numero + cifra ;
		cout << "Hasta ahora se ha formado el numero: " << numero << endl;
		cout << endl;
	}
	return numero;
}