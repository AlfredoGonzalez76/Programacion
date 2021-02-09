#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	char a;
	int i, op;

	do
	{
		system("cls");
		cout << "1 - Codigo a ASCII" << endl;
		cout << "2 - ASCII a Codigo" << endl;
		cout << "3 - Salir" << endl;
		cout << endl;
		cout << "Elija una opcion: ";

		cin >> op;

		if (op == 1)
		{
			cout << "Introduzca el codigo ASCII: ";
			cin >> i;
			a = i;
			cout << "El caracter es: " << a << endl;
		}

		if (op == 2)
		{
			cout << "Introduzca el caracter:" ;
			cin >> a;
			i = a;
			cout << "El codigo ASCII es: " << i << endl;
		}
		system("pause");
	}while(op != 3);

	return 0;
}