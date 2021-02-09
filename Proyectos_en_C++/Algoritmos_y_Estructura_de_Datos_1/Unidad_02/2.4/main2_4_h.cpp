#include <iostream>
using namespace std;

/* Hacer un programa en C++ que pida números mientras no se escriba un número negativo.
El programa terminará escribiendo la suma de los números introducidos. */

main()
{
	double valActual, acumulado = 0;
	cout << "Se sumaran todos los numeros que ingrese siempre que no sean negativos." << endl;

	do
	{
		cout << "Ingrese un numero: ";
		cin >> valActual ;
		acumulado = acumulado + valActual ;
	}
	while ( valActual >= 0 );
	if ( acumulado < 0 )
	{
		cout << "Solo se ingreso un numero negativo." << endl;
	}
	else
	{
		cout << "La suma de los numeros no negativos ingresados es: " << acumulado - valActual << endl;
	}

	return 0;
}