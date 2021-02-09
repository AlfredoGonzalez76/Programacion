#include <iostream>
using namespace std;

int main()
{
	char letra;

	cout << "Ingrese el sexo (F/M): ";
	cin >> letra;
	if ((letra == 'm')||(letra == 'M'))
	{
		cout << "SE TRATA DE UNA MUJER" << endl;
	}
	else
	{
		cout << "SE TRATA DE UN HOMBRE" << endl;
	}
	return 0;
}