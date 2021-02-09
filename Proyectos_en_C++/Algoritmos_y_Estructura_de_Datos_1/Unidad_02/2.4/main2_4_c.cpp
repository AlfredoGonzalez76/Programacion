#include <iostream>
using namespace std;

/*Hacer un programa en C++ para determinar el promedio de
tres notas y determinar si el estudiante aprobó o no.  */
// El codigo solo tiene en cuenta el promedio 

main()
{
	double nota1, nota2, nota3;

	cout << "A continuacion debera ingresar las notas de los alumnos." << endl;
	cout << "Ingrese la Primera nota: ";
	cin >> nota1;
	cout << "Ingrese la Segunda nota: ";
	cin >> nota2;
	cout << "Ingrese la Tercer nota: ";
	cin >> nota3;
	if ( (nota1 + nota2 + nota3 )/3 >= 4 )
	{
		cout << "El alumno aprobo la materia." << endl;
	}
	else
	{
		cout << "El alumno NO aprobo la materia." << endl;
	}

	return 0;
}