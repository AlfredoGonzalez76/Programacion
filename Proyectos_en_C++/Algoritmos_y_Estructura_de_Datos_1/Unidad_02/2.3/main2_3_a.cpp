#include <iostream>
using namespace std;

/* Realice un programa que lea de la entrada estándar los siguientes datos de una persona:
Edad: dato de tipo entero. Sexo: dato de tipo carácter. Altura en metros: dato de tipo real.
Tras leer los datos, el programa debe mostrarlos en la salida estándar.*/

int main()
{
	int edad;
	char sexo;
	float altura;

	cout << "Ingrese los siguientes datos: " << endl;
	cout << "Edad: ";
	cin >> edad;
	cout << "Sexo (F/M): ";
	cin >> sexo;
	cout << "Altura: ";
	cin >> altura;

	cout << "La persona tiene " << edad << " anios, sexo " << sexo << " y altura " << altura << " m." << endl;

	return 0;
}