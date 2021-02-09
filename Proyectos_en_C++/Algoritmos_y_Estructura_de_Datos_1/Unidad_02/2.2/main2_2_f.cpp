#include <iostream>
using namespace std;

int main()
{
	double gradoF;

	cout << "Pasemos de grados Farenheit a Celcius." << endl;
	cout << "Ingrese una temperatura en grados Farenheit: ";
	cin >> gradoF;

	cout << "Eso equivale a: " << (gradoF - 32)*5/9 << " grados Celcius." << endl;

	return 0;
}