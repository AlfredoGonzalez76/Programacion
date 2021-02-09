#include <iostream>
using namespace std;

int main()
{
	typedef enum { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO } dias;

	dias dia;

	dia = MARTES;

	int i = double(dia);  // casteo explicito

	cout << "La variable 'dia' vale " << dia << " y la variable 'i' vale " << i << endl;

	return 0;
}