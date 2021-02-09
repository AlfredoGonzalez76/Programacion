#include <iostream>
#include <iomanip>
#include <string>
#include "registroDin.h"

using namespace std;


void nuevoRegistro(tRegPtr& registro)
{
	string auxString;
	
	registro = new tRegistro;

	cout << "Ingrese Apellidos del alumno: ";
	getline(cin, registro->apellidos);

	cout << "Ingrese Nombres del alumno: ";
	getline(cin, registro->nombres);

	cout << "Ingrese la Edad del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro->edad = atoi(auxString.c_str());

	cout << "Ingrese DNI del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro->dni = atoi(auxString.c_str());

	cout << "Ingrese la NOTA del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro->nota = atoi(auxString.c_str());

}


void muestraRegistroCompleto(tRegPtr& registro)
{
	cout << "---------------------------------------------------------------------" << endl ;
	cout << "| Apellidos: " << setw(55) << setiosflags(ios::right) << registro->apellidos << '|' << endl;
	cout << "| Nombres:   " << setw(55) << setiosflags(ios::right) << registro->nombres << '|' << endl;
	cout << "| Edad:      " << setw(55) << setiosflags(ios::right) << registro->edad << '|' << endl;
	cout << "| DNI:       " << setw(55) << setiosflags(ios::right) << registro->dni << '|' << endl;
	cout << "| Nota:      " << setw(55) << setiosflags(ios::right) << registro->nota << '|' << endl;
	cout << setiosflags(ios::left) << "---------------------------------------------------------------------" << endl ;
}

void modificaRegistro(tRegPtr& registro)
{
	int opcion;
	string auxString;

	do
	{
		muestraRegistroCompleto(registro);

		cout << " Presione: " << endl;
		cout << " 1) Para modificar Apellidos" << endl;
		cout << " 2) Para modificar Nombres " << endl;
		cout << " 3) Para modificar edad" << endl;
		cout << " 4) Para modificar DNI" << endl;
		cout << " 5) Para modificar nota" << endl;
		cout << " 6) Para terminar modificacion" << endl;
		cout << endl;
		cout << " Digite aqui su opcion: ";
		cin >> opcion;
		cin.ignore();
		cout << endl;

		switch(opcion)
		{
		  case 1:
		     cout << "Apellidos: ";
		     getline(cin, registro->apellidos);
		     cout << endl;
		    break;
		  case 2:
		     cout << "Nombres: ";
		     getline(cin, registro->nombres);
		     cout << endl;
		    break;
		  case 3:
		  	cout << "Edad: ";
			cin >> auxString;
			cin.ignore();
			registro->edad = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 4:
		  	cout << "DNI: ";
			cin >> auxString;
			cin.ignore();
			registro->dni = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 5:
		  	cout << "Nota: ";
			cin >> auxString;
			cin.ignore();
			registro->nota = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 6:
		  	cout << "Ha terminado de modificar el Registro" << endl;;
		    break;
		  default:
		  	cout << "Opcion incorrecta" << endl;
		  	cout << endl;
		}
	}
	while(opcion != 6);
}


void eliminaRegistro(tRegPtr& registro)
{
	delete registro;
}

/*
void intercambio(tRegPtr& a, tRegPtr& b)
{
	tRegPtr aux;

	aux = a;
	a = b;
	b = aux;
}
*/