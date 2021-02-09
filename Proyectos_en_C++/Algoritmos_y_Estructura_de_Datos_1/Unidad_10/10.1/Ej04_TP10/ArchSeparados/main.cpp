#include "Persona.h"

#include <iostream>
#include <string>
#include <stdlib.h>  // para system("pause")

using namespace std;

int main()
{
	Persona persona;
	int auxInt;
	string auxNom;

	cout << "Ingrese el nombre de la persona: ";
	getline(cin, auxNom);
	persona.SetNombre(auxNom);

	cout << "Solicitaremos ahora la fecha de nacimiento:" << endl;

	cout << "Ingrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetDiaNac(auxInt);

	cout << "Ingrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetMesNac(auxInt);
	
	cout << "Ingrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetAnnoNac(auxInt);

	cout << "\nIngrese ahora la fecha actual:" << endl;

	cout << "\nIngrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetDiaAct(auxInt);

	cout << "\nIngrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetMesAct(auxInt);
	
	cout << "\nIngrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetAnnoAct(auxInt);

	if (persona.obtenerEdad() != -1)
	{
		cout << "\nLa fecha de nacimiento de " << persona.GetNombre() << " es: " 
		<< persona.GetDiaNac() << '-' << persona.GetMesNac() << '-' << persona.GetAnnoNac() << endl;

		cout << "\nLa fecha actual es: " << persona.GetDiaAct() << '-' << persona.GetMesAct() << '-' << persona.GetAnnoAct() << endl;

		cout << "\ny tiene " << persona.obtenerEdad() << " annos.\n" << endl;
	}
	else
	{
		cout << "El anno actual es menor al anno de nacimiento. Revise los datos." << endl;
	}
	
	system("pause");

	return 0;
} 