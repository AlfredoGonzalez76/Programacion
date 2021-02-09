#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;


// (Se recomienda utilizar Funciones, Tipos definidos x el usuario y Enumeradores)
/* Una empresa de viaje nos pide que realicemos un programa para tomar reservas en
avión, las mismas pueden ser clase Primera, Bussiness y económica, además del DNI,
apellido y nombre, aeropuerto origen y destino.
Código Aeropuerto:
1. Bahía Blanca-BHI
2. Buenos Aires Aeroparque-AEP
3. Buenos Aires El Palomar-EPA
4. Buenos Aires Ezeiza-EZE
5. San Carlos de Bariloche-BRC
6. San Fernando del Valle de Catamarca-CTC
7. Comodoro Rivadavia-CRD
El usuario introduce los datos personales, la clase y el origen – destino, mostrando el resultado x pantalla.
 */

typedef enum { BHI, AEP, EPA, EZE, BRC, CTC, CRD } tAir;

typedef enum {ECO, BUS, FST} tClase;


string currentDateTime();

string ingresaNombre();

tClase eligeClase();

tAir eligeAeropuerto();

void ingresaDatos(string &fh, string &name, tClase &cl, tAir &origen, tAir &destino);



void imprimeFechaHora(string fh);

void imprimeNombre(string name);

void imprimeClase(tClase cl);

void imprimeAeropuerto(tAir vuelo);

void imprimePasaje(string fh, string name, tClase cl, tAir origen, tAir destino);



int main()
{
	string fechaHora, nombre;
	tClase clase;
	tAir origen, destino;

	ingresaDatos(fechaHora, nombre , clase, origen, destino);
	cout << endl;

	imprimePasaje(fechaHora, nombre , clase, origen, destino);
	cout << endl;

	return 0;
}





string currentDateTime() 
// Get current date/time, format is DD-MM-YYYY.HH:mm:ss
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);

    return buf;
}


string ingresaNombre()
{	
	string nombre;

	cout << "Ingrese su nombre completo: ";
	getline(cin, nombre);

	return nombre;
}


tClase eligeClase()
{
	int op;
	cout << "CLASES disponibles:" << endl;
	cout << "1) Economica." << endl;
	cout << "2) Business." << endl;
	cout << "3) Primera Clase." << endl;
	cout << endl;
	cout << "Elija su opcion: ";
	cin >> op;
	return tClase(op-1);
}


tAir eligeAeropuerto()
{
	int op;
	cout << "1. Bahia Blanca" << endl;
	cout << "2. Buenos Aires Aeroparque" << endl;
	cout << "3. Buenos Aires El Palomar" << endl;
	cout << "4. Buenos Aires Ezeiza" << endl;
	cout << "5. San Carlos de Bariloche" << endl;
	cout << "6. San Fernando del Valle de Catamarca" << endl;
	cout << "7. Comodoro Rivadavia" << endl;
	cout << endl;
	cout << "Elija su opcion: ";
	cin >> op;
	return tAir(op-1);
}	


void ingresaDatos(string &fh, string &name, tClase &cl, tAir &origen, tAir &destino)
{
	fh = currentDateTime();

	name = ingresaNombre();
	cout << endl;
	cout << endl;

	cl = eligeClase();
	cout << endl;
	cout << endl;

	cout << "Elija el ORIGEN: " <<endl;
	origen = eligeAeropuerto();
	cout << endl;
	cout << endl;

	cout << "Elija el DESTINO: " <<endl;
	destino = eligeAeropuerto();
	cout << endl;
	cout << endl;
}





void imprimeFechaHora(string fh)
{
	cout << "Fecha y Hora: " << fh << endl;
}


void imprimeNombre(string name)
{
	cout << "Nombre: " << name << endl;
}



void imprimeClase(tClase cl)
{
	cout << "Clase: ";
	switch(cl) {
	  case 0:
	    cout << "Economica" << endl;
	    break;
	  case 1:
	    cout << "Business" << endl;
	    break;
	  case 2:
	  	cout << "Primera Clase" << endl;
	}	
}


void imprimeAeropuerto(tAir vuelo)
{
	switch(vuelo) {
	  case 0:
	    cout << "BHI" << endl;
	    break;
	  case 1:
	    cout << "AEP" << endl;
	    break;
	  case 2:
	  	cout << "EPA" << endl;
	    break;
	  case 3:
	  	cout << "EZE" << endl;
	    break;
	  case 4:
	    cout << "BRC" << endl;
	    break;
	  case 5:
	  	cout << "CTC" << endl;
	    break;
	  case 6:
	  	cout << "CRD" << endl;
	}	

}


void imprimePasaje(string fh, string name, tClase cl, tAir origen, tAir destino)
{
	imprimeFechaHora(fh);

	imprimeNombre(name);

	imprimeClase(cl);

	cout << "ORIGEN: ";

	imprimeAeropuerto(origen);

	cout << "DESTINO: ";

	imprimeAeropuerto(destino);
}