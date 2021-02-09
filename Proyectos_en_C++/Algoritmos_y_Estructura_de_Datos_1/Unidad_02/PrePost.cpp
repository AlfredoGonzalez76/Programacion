#include <iostream>
using namespace std;

int main()
{
	int a = 1, b = 1;

	cout << "Ahora 'a' vale " << ++a << endl;
	cout << "Ahora 'b' vale " << b++ << endl;
	cout << "Verifiquemos ahora el valor de 'b': " << b << endl;
	return 0;
}