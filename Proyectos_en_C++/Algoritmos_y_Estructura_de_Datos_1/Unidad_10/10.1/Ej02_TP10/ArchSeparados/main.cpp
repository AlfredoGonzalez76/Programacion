#include "Alumno.h"

#include <iostream>
#include <string>
#include <stdlib.h>  // para system("pause")

using namespace std;

int main()
{
	Alumno alumno;
	string auxCad;
	float auxNum;

	cout << "Ingrese una cedula de alumno: ";
	getline(cin,auxCad);
	alumno.SetCedula(auxCad);

	cout << "Ingrese el nombre del alumno: ";
	getline(cin,auxCad);
	alumno.SetNombre(auxCad);

	cout << "Ingrese la Nota 1 del alumno (sobre 100): ";
	cin >> auxNum;
	cin.ignore();
	alumno.SetNota1(auxNum);

	cout << "Ingrese la Nota 2 del alumno (sobre 100): ";
	cin >> auxNum;
	cin.ignore();
	alumno.SetNota2(auxNum);

	cout << "Ingrese la Nota 3 del alumno (sobre 100): ";
	cin >> auxNum;
	cin.ignore();
	alumno.SetNota3(auxNum);

	cout << endl;
	cout << "Alumno: " << alumno.GetNombre() << endl;
	cout << "Cedula: " << alumno.GetCedula() << endl;
	cout << "Nota Final: " << alumno.NotaFinal() << endl;
	cout << "Situacion del alumno: " << alumno.AproRepro() << endl;

	system("pause");

	return 0;
}