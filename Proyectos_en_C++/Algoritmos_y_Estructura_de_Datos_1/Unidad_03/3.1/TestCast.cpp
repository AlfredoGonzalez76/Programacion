#include <iostream>
using namespace std;


int main()
{
	int a, b;

	a = 3;
	b = 2;

	cout << "El valor de 'a/b' es " << int(a) / b << endl; // Notación funcional

	cout << "El valor de 'a/b' es " << int(a / b) << endl; // Notación funcional

	cout << "El valor de 'a' es " << a << endl;

	cout << "El valor de 'b' es " << b << endl;

	cout << "El valor de 'a/b' es " << (int) a / b << endl; // Notación de prefijo

	cout << "El valor de 'a/b' es " << (int) (a / b) << endl; // Notación de prefijo

	return 0;
}