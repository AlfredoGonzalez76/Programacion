#include <iostream>
using namespace std;

/*Hacer un programa en C++ que pida números hasta que el usuario
introduzca 99, luego mostrar los números y el promedio. */

main()
{
	double valActual, acumulado = 0;
	int contador = 0;
	cout << "Se promediaran los numeros que ingrese siempre que sean distintos de 99: " << endl;

	do
	{
		cout << "Ingrese un numero: ";
		cin >> valActual ;
		acumulado = acumulado + valActual ;
		contador++;
	}
	while ( valActual != 99 );
	if ( contador == 1 )
	{
		cout << "No se ingreso ningun numero distinto de 99." << endl;
	}
	else
	{
		cout << "El promedio de los numeros ingresados es: " << (acumulado - 99)/(contador - 1) << endl;
	}

	return 0;
}