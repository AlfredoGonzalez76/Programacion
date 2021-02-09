#include <iostream>
using namespace std;

int main()
{
	enum dias
	{
		LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
	};

	typedef enum { Sistemas, Logistica, Textil, EmMedicas, Turismo, Ambiental } tCarrera;

	tCarrera carrera;


	dias dia;

	dia = LUNES;

	cout << dia << endl;

	return 0;
}