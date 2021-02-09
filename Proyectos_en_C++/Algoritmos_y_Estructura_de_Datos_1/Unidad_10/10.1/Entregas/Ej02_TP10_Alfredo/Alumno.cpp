//*****************************************************************
// ARCHIVO DE IMPLEMENTACION (Alumno.cpp)
// Este archivo implementa las funciones miembro de Archivo
//*****************************************************************
#include "Alumno.h"

#include <iostream>
#include <string>

using namespace std;

// Miembros de clase privados:
//	string cedula;
//	string nombre;
//	float nota1;
//	float nota2;
//	float nota3;


Alumno::Alumno()
// Constructor
{}


void Alumno::SetCedula(string ced)
// Precondicion: Dato alfanumerico
// Poscondicion: Se establece la cedula con el parametro entrante
{
	cedula = ced;
}


string Alumno::GetCedula()
// Precondicion: La funcion SetCedula tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la cedula de un alumno
{
	return cedula;
}

void Alumno::SetNombre(string nom)
// Precondicion: Dato de tipo string
// Poscondicion: Se establece el nombre con el parametro entrante
{
	nombre = nom;
}

string Alumno::GetNombre()
// Precondicion: La funcion SetNombre tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el nombre de un alumno
{
	return nombre;
}

void Alumno::SetNota1(float n1)
// Precondicion: Dato numerico float
// Poscondicion: Se establece la primera nota con el parametro entrante
{
	nota1 = n1;
}

float Alumno::GetNota1()
// Precondicion: La funcion SetNota1 tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la primera nota de un alumno
{
	return nota1;
}


void Alumno::SetNota2(float n2)
// Precondicion: Dato numerico float
// Poscondicion: Se establece la segunda nota con el parametro entrante
{
	nota2 = n2;
}


float Alumno::GetNota2()
// Precondicion: La funcion SetNota2 tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la segunda nota de un alumno
{
	return nota2;
}

void Alumno::SetNota3(float n3)
// Precondicion: Dato numerico float
// Poscondicion: Se establece la tercera nota con el parametro entrante
{
	nota3 = n3;
}

float Alumno::GetNota3()
// Precondicion: La funcion SetNota3 tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la tercera nota de un alumno
{
	return nota3;
}


float Alumno::NotaFinal()
// Precondicion: Las funciones SetNota1, SetNota2 y SetNota3 tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la nota final de un alumno
{
	return ((nota1 + nota2 + nota3) / 3);
}

string Alumno::AproRepro()
// Precondicion: Las funciones SetNota1, SetNota2, SetNota3 y NotaFinal tienen que haber sido invocadas al menos una vez.
// Poscondicion: Genera un mensaje con la condicion final de un alumno: Aprobado o Reprobado
{
	if (NotaFinal() >= 48)
	{
		return "Aprobado";
	}
	else
	{
		return "Desaprobado";
	}
}

Alumno::~Alumno()
	// Destructor
{}