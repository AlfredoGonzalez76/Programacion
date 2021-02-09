#include <iostream>
using namespace std;

/* La Nota final de un estudiante es el promedio de tres notas:la nota de laboratorio que cuenta un 30% del total,
la nota teórica que cuenta un 60% y la nota de Práctica que cuenta el 10% restante.
Escriba un programa que lea de la entrada estándar las tres notas de un alumno
y escriba en la salida estándar su nota final.*/

int main()
{
	float notaLab, notaTeo, notaPra;

	cout << "A continuacion debera ingresar las notas del alumno" << endl;
	cout << "Ingrese la Nota de Laboratorio: ";
	cin >> notaLab;
	cout << "Ingrese la Nota del Teorico: ";
	cin >> notaTeo;
	cout << "Ingrese la Nota de la Practica: ";
	cin >> notaPra;

	cout << "La nota final del alumno es: " << notaLab * 0.3 + notaTeo * 0.6 + notaPra * 0.1 << endl;

	return 0;
}