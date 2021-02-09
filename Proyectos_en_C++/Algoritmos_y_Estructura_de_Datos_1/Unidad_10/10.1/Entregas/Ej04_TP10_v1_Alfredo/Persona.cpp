//*****************************************************************
// ARCHIVO DE IMPLEMENTACION (Persona.cpp)
// Este archivo implementa las funciones miembro de Persona
//*****************************************************************

#include "Persona.h"

#include <iostream>
#include <string>

using namespace std;


// Miembros de clase privados:
//	string nombre;
//	int dianac;
//	int mesnac;
//	int annonac;
//	int diaact;
//	int mesact;
//	int annoact;

Persona::Persona()
// Constructor
{}


void Persona::SetNombre(string nom)
// Precondicion: Dato de tipo string
// Poscondicion: Se establece el nombre con el parametro entrante
{
	nombre = nom;
}


string Persona::GetNombre()
// Precondicion: La funcion SetNombre tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el nombre de una persona
{
	return nombre;
}


void Persona::SetDiaNac(int d)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el dia con el parametro entrante
{
	dianac = d;
}


int Persona::GetDiaNac()
// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el dia de nacimiento de una persona
{
	return dianac;
}


void Persona::SetMesNac(int m)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el mes de nacimiento con el parametro entrante
{
	mesnac = m;
}


int Persona::GetMesNac()
// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el mes de nacimiento de una persona
{
	return mesnac;
}


void Persona::SetAnnoNac(int a)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el anno de nacimiento con el parametro entrante
{
	annonac = a;
}

int Persona::GetAnnoNac()
// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el mes de nacimiento de una persona
{
	return annonac;
}

void Persona::SetDiaAct(int da)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el dia actual con el parametro entrante
{
	diaact = da;
}

int Persona::GetDiaAct()
// Precondicion: La funcion SetDiaAct tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el dia actual
{
	return diaact;
}


void Persona::SetMesAct(int ma)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el mes actual con el parametro entrante
{
	mesact = ma;
}


int Persona::GetMesAct()
// Precondicion: La funcion SetMesAct tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el mes actual
{
	return mesact;
}

void Persona::SetAnnoAct(int aa)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el anno actual con el parametro entrante
{
	annoact = aa;
}


int Persona::GetAnnoAct()
// Precondicion: La funcion SetAnnoAct tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el anno actual
{
	return annoact;
}

int Persona::obtenerEdad()
// Precondicion: La funcion SetDia, SetMes, SetAnno, SetDiaAct, SetMesAct, SetAnnoAct
//               tienen que haber sido invocadas al menos una vez.
// Poscondicion: Se obtiene la edad de la persona si el anno actual es mayor o igual al anno de nacimiento
//               y devuelve -1 si los datos cargados son incorrectos.
{
	if (annoact >= annonac)
	{
		return (annoact - annonac);
	}
	else
	{
		return (-1);
	}
}

Persona::~Persona()
// Destructor
{}
