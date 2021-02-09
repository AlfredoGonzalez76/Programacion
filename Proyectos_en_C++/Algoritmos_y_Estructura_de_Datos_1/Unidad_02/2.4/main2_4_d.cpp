#include <iostream>
using namespace std;

/*Hacer un programa en C++ que pida números hasta que el usuario
introduzca 99, luego mostrar los números y el promedio. */

main()
{
	double valActual = 0, acumulado = 0;
	int contador = 0;
	cout << "Se promediaran los numeros que ingrese siempre que sean distintos de 99: " << endl;

	while ( valActual != 99 )
	{
		contador++;
		cout << "Ingrese el numero "<< contador << ": ";
		cin >> valActual ;
		acumulado = acumulado + valActual ;
	}
	if ( contador == 1 )
	{
		cout << "No se ingreso ningun numero distinto de 99." << endl;
	}
	else
	{
		cout << "El promedio de los numeros ingresados es: " << (acumulado - 99)/(contador - 1)<< endl;
	}

	return 0;
}