#include <iostream>
#include <string>
using namespace std;


bool In(string fragmento, string palabra);

string mayuscula(string cadena);


int main()
{
	string fragmento, palabra;

	palabra = "Lucas Dominguez";

	fragmento = "Min";

	if (In(mayuscula(fragmento), mayuscula(palabra)))
	{
		cout << "Exito" << endl;
	}
	else
	{
		cout << "Todavia Falta" << endl;
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


