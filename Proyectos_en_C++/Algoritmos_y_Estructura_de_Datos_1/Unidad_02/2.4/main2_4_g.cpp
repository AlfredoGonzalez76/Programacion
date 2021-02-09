#include <iostream>
using namespace std;

/* Hacer un programa en C++ que pida dos números enteros. El programa pedirá de nuevo el segundo
número mientras no sea mayor que el primero. El programa terminará escribiendo los dos números. */

int main()
{
	double num1, num2;

	cout << "Solicitaremos que ingrese dos numeros. Y solicitaremos nuevamente el 2do. hasta que supere al primero." << endl;

	cout << "Ingrese el primer numero: ";
	cin >> num1;

	do
	{
		cout << "Ingrese el segundo numero: ";
		cin >> num2;
	}
	while ( num2 <= num1 );

	cout << "Los numeros ingresados fueron " << num1 << " y " << num2 << endl;

	return 0;
}