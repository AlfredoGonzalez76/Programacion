#include <iostream>
using namespace std;

/* Hacer un programa en C++ que pida un número y calcule
la suma desde 1 hasta ese número, en incrementos de uno. */

main()
{
	int contador = 1, cota, suma = 0;
	cout << "Se sumaran los numeros naturales desde 1 hasta el numero que ud. ingrese." << endl;

	cout << "Ingrese el numero hasta el que desea sumar: ";
	cin >> cota;

	while ( contador <= cota )
	{
		suma = suma + contador ;
		contador++;
	}

	cout << "La suma de los primeros " << cota << " numeros naturales es: " << suma << endl;

	return 0;
}