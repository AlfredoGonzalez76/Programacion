//*****************************************************************
// ARCHIVO DE IMPLEMENTACION (Fecha.cpp)
// Este archivo implementa las funciones miembro de Fecha
//*****************************************************************

#include "Fecha.h"

#include <iostream>
#include <string>

using namespace std;


// Miembros de clase privados:
//	int dia;
//	int mes;
//	int anno;

Fecha::Fecha()
// Constructor
{}

void Fecha::SetDia(int d)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el dia con el parametro entrante
{
	dia = d;
}


int Fecha::GetDia()
// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el campo dia correspondiente a una fecha
{
	return dia;
}

void Fecha::SetMes(int m)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el mes con el parametro entrante
{
	mes = m;
}


int Fecha::GetMes()
// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el campo mes correspondiente a una fecha
{
	return mes;
}


void Fecha::SetAnno(int a)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el anno con el parametro entrante
{
	anno = a;
}


int Fecha::GetAnno()
// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el campo anno correspondiente a una fecha
{
	return anno;
}


Fecha Fecha::tiempoTranscurrido(Fecha fechaPost)
// Precondicion: Se le debe pasar un objeto de tipo fecha.
// Poscondicion: Se obtiene la diferencia entre fechaPost y la fecha del objeto actual
// si la fechaPost es posterior a la fecha del objeto actual y -1/-1/-1 en caso contrario
{
	Fecha dif;

	if (fechaPost.anno > this->anno)
	{
		if (fechaPost.mes > this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
			}
			else
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes - 1;
				dif.dia  = fechaPost.dia  + 30 - this->dia;
			}
		}
		else if (fechaPost.mes == this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
			}
			else
			{
				dif.anno = fechaPost.anno - 1 - this->anno;
				dif.mes  = fechaPost.mes + 11 - this->mes;
				dif.dia  = fechaPost.dia + 30 - this->dia;
			}
		}
		else if (fechaPost.mes < this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - 1 - this->anno;
				dif.mes  = fechaPost.mes + 12  - this->mes;
				dif.dia  = fechaPost.dia - this->dia;
			}
			else
			{
				dif.anno = fechaPost.anno - 1 - this->anno;
				dif.mes  = fechaPost.mes + 11 - this->mes;
				dif.dia  = fechaPost.dia + 30 - this->dia;
			}
		}
	}
	else if (fechaPost.anno == this->anno)
	{
		if (fechaPost.mes > this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
			}
			else
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes - 1 - this->mes;
				dif.dia  = fechaPost.dia  + 30 - this->dia;
			}
		}
		else if (fechaPost.mes == this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
			}
			else
			{
				dif.anno = -1;
				dif.mes  = -1;
				dif.dia  = -1;
			}
		}
		else if (fechaPost.mes < this->mes)
		{
			dif.anno = -1;
			dif.mes  = -1;
			dif.dia  = -1;
		}
	}
	else
	{
		dif.anno = -1;
		dif.mes = -1;
		dif.dia = -1;
	}
	return dif;
}


Fecha::~Fecha()
// Destructor
{}
