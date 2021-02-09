#include <iostream>
using namespace std;
#include <string>


int main()
{
	string nombre;

	cout << "Ingrese su nombre completo: ";
//	cin >> nombre;
	getline(cin, nombre);
	cout << "Su nombre es: " << nombre << endl;
	return 0;
}