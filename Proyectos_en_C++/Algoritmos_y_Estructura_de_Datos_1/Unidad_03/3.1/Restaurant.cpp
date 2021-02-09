#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;


// (Se recomienda utilizar Funciones, Tipos definidos x el usuario y Enumeradores)
/* Una aplicación para un restaurante que tiene: primer plato, plato principal y poste,
toma pedidos de los mozos. Estos envían la comanda codificada por numero para cada plato.
El cocinero recibe el pedido en formato de texto con el nro de mesa, nombre mozo, fecha,
hora, primer plato, plato principal y poste. Se pide desarrollar una APP que pida la
comanda y muestre por pantalla la Info solicitada. */

typedef enum { Juan, Vanesa, Martin, Maria } tMozo;


string currentDateTime();

int eligeMesa();

tMozo codificaMozo(int mesa);

int codificaMenuEntrada();

int codificaMenuPrincipal();

int codificaMenuPostre();

void codificaComanda(int &table, string &fh, tMozo &waiter, int &pl1, int &pl2, int &pl3);


void imprimeMesa(int table);

void imprimeFechaHora(string fh);

void decodificaMozo(tMozo waiter);

void decodificaMenuEntrada(int pl1);

void decodificaMenuPrincipal(int pl2);

void decodificaMenuPostre(int pl3);

void decodificaComanda(int table, string fh, tMozo waiter, int pl1, int pl2, int pl3);




int main()
{
	tMozo mozo;

	string fechaHora;

	int mesa, plato1, plato2, plato3;

	codificaComanda(mesa, fechaHora, mozo, plato1, plato2, plato3);
	cout << endl;

	decodificaComanda(mesa, fechaHora, mozo, plato1, plato2, plato3);
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

void codificaComanda(int &table, string &fh, tMozo &waiter, int &pl1, int &pl2, int &pl3)
{

	table = eligeMesa();
	cout << endl;
	cout << endl;

	fh = currentDateTime();

	waiter = codificaMozo(table);

	pl1 = codificaMenuEntrada ();
	cout << endl;
	cout << endl;

	pl2 = codificaMenuPrincipal();
	cout << endl;
	cout << endl;

	pl3 = codificaMenuPostre();
	cout << endl;
	cout << endl;
}


int eligeMesa()
{
	int op;
	
	do
	{
		cout << "Ingrese un nro. de mesa ( 1 - 24 ): ";
		cin >> op;
	}
	while ( (op < 1) || (op > 24) );

	return op;
}


tMozo codificaMozo(int mesa)
{
	return tMozo((mesa-1)/6);     // De este modo asigna equitativamente las mesas a los mozos
}


int codificaMenuEntrada()
{
	int op;
	cout << "Estas son las ENTRADAS disponibles:" << endl;
	cout << "1) Quesadilla." << endl;
	cout << "2) Enchiladas." << endl;
	cout << "3) Nachos" << endl;
	cout << "4) Chicken fajitas" << endl;
	cout << "5) Tacos." << endl;
	cout << endl;
	cout << "Digite su opcion: " ;
	do
	{
		cin >> op;
	}
	while ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5));

	return op;
}


int codificaMenuPrincipal()
{
	int op;
	cout << "Estos son los platos PRINCIPALES disponibles:" << endl;
	cout << "1) Carne asada" << endl;
	cout << "2) Milanesa de Res" << endl;
	cout << "3) Lomito Completo" << endl;
	cout << "4) Hamburguesa" << endl;
	cout << "5) Ensalada Cesar" << endl;
	cout << endl;
	cout << "Digite su opcion: " ;
	do
	{
		cin >> op;
	}
	while ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5));

	return op;
}


int codificaMenuPostre()
{
	int op;
	cout << "Estos son los POSTRES disponibles:" << endl;
	cout << "1) Flan Casero" << endl;
	cout << "2) Almendrado" << endl;
	cout << "3) Budin de Pan" << endl;
	cout << "4) Selva Negra" << endl;
	cout << "5) Rogel" << endl;
	cout << endl;
	cout << "Digite su opcion: " ;
	do
	{
		cin >> op;
	}
	while ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5));
	
	return op;
}


void imprimeMesa(int table)
{
	cout << "Mesa " << table << endl;
}


void imprimeFechaHora(string fh)
{
	cout << "Fecha y Hora: " << fh << endl;
}


void decodificaMozo(tMozo waiter)
{
	cout << "Mozo: ";
	switch(waiter) {
	  case Juan:
	    cout << "Juan" << endl;
	    break;
	  case Vanesa:
	    cout << "Vanesa" << endl;
	    break;
	  case Martin:
	  	cout << "Martin" << endl;
	    break;
	  case Maria:
	  	cout << "Maria" << endl;
	}	
}


void decodificaMenuEntrada(int pl1)
{
	cout << "Entrada: ";
	switch(pl1)
	{
		case 1:
			cout << "Quesadilla" << endl;
			break;
		case 2:
			cout << "Enchiladas" << endl;
			break;
		case 3:
			cout << "Nachos" << endl;
			break;
		case 4:
			cout << "Chicken fajitas" << endl;
			break;
		case 5:
			cout << "Tacos" << endl;
	}
}

void decodificaMenuPrincipal(int pl2)
{
	cout << "Plato Principal: ";
	switch(pl2)
	{
		case 1:
			cout << "Carne asada" << endl;
			break;
		case 2:
			cout << "Milanesa de Res" << endl;
			break;
		case 3:
			cout << "Lomito Completo" << endl;
			break;
		case 4:
			cout << "Hamburguesa" << endl;
			break;
		case 5:
			cout << "Ensalada Cesar" << endl;
	}
}


void decodificaMenuPostre(int pl3)
{
	cout << "Postre: ";
	switch(pl3)
	{
		case 1:
			cout << "Flan Casero" << endl;
			break;
		case 2:
			cout << "Almendrado" << endl;
			break;
		case 3:
			cout << "Budin de Pan" << endl;
			break;
		case 4:
			cout << "Selva Negra" << endl;
			break;
		case 5:
			cout << "Rogel" << endl;
	}
}


void decodificaComanda(int table,string fh, tMozo waiter, int pl1, int pl2, int pl3)
{
	imprimeMesa(table);

	imprimeFechaHora(fh);

	decodificaMozo(waiter);

	decodificaMenuEntrada(pl1);

	decodificaMenuPrincipal(pl2);

	decodificaMenuPostre(pl3);
}