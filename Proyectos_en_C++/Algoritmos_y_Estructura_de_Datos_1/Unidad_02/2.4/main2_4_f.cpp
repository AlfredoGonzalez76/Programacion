#include <iostream>
using namespace std;

/* Hacer un programa en C++ para Calcular la suma de los números pares
e impares comprendidos entre 1 y n (n lo introduce el usuario).  */

main()
{
	int contador = 1, cota, sumaPar = 0 , sumaImpar = 0, pares = 0, impares = 0;
	cout << "Se sumaran los numeros naturales pares e impares desde 1 hasta el numero que ud. ingrese." << endl;

	cout << endl;

	cout << "Ingrese el numero hasta el que desea sumar: ";
	cin >> cota;

	while ( contador <= cota )
	{
		if ((contador % 2) == 1)
		{
			sumaImpar = sumaImpar + contador ;
			impares++;
		}
		else
		{
			sumaPar = sumaPar + contador ;
			pares++;
		}
		
		contador++;
	}

	cout << endl;

	cout << "Entre 1 y " << cota << " hay " << impares << " numeros naturales impares y su suma es: " << sumaImpar << endl;

	cout << endl;

	cout << "Entre 1 y " << cota << " hay " << pares << " numeros naturales pares y su suma es: " << sumaPar << endl;

	cout << endl;

	return 0;
}