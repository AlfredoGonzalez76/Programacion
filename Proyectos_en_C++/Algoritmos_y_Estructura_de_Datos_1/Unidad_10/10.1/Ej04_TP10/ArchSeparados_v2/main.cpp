#include "Persona.h"
#include "Fecha.h"

#include <iostream>
#include <string>
#include <stdlib.h>  // para system("pause")

using namespace std;



int main()
{
	Persona persona;
	Fecha fechaAct, fechaAux, diferencia;
	string auxNom;
	int auxInt;

	cout << "Ingrese el nombre de la persona: ";
	getline(cin, auxNom);
	persona.SetNombre(auxNom);

	cout << "Solicitaremos ahora la fecha de nacimiento:" << endl;

	cout << "\nIngrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	fechaAux.SetDia(auxInt);

	cout << "Ingrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	fechaAux.SetMes(auxInt);
	
	cout << "Ingrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	fechaAux.SetAnno(auxInt);

	persona.SetFechaNac(fechaAux);

	cout << "\nIngrese ahora la fecha actual:" << endl;

	cout << "\nIngrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	fechaAct.SetDia(auxInt);

	cout << "Ingrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	fechaAct.SetMes(auxInt);
	
	cout << "Ingrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	fechaAct.SetAnno(auxInt);

//	diferencia = fechaAux.tiempoTranscurrido(fechaAct);
	diferencia = (persona.GetFechaNac()).tiempoTranscurrido(fechaAct);

	if (diferencia.GetAnno() != -1)
	{
		cout << "\nLa fecha de nacimiento de " << persona.GetNombre() << " es: " 
		<< persona.GetFechaNac().GetDia() << '-' << persona.GetFechaNac().GetMes() << '-' << persona.GetFechaNac().GetAnno() << endl;

		cout << "\nLa fecha actual es: " << fechaAct.GetDia() << '-' << fechaAct.GetMes() << '-' << fechaAct.GetAnno() << endl;


		cout << "\nLa persona tiene aproximadamente " << diferencia.GetAnno() << " anios, " << diferencia.GetMes() << " meses y " << diferencia.GetDia() << " dias.\n" << endl;;

	}
	else
	{
		cout << "La fecha actual es menor a la de nacimiento. Revise los datos." << endl;
	}
	
	system("pause");

	return 0;
}
