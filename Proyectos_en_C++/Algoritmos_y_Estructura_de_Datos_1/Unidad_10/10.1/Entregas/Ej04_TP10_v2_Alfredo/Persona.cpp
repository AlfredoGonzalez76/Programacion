//*****************************************************************
// ARCHIVO DE IMPLEMENTACION (Persona.cpp)
// Este archivo implementa las funciones miembro de Persona
//*****************************************************************

#include "Fecha.h"
#include "Persona.h"

#include <iostream>
#include <string>

using namespace std;


// Miembros de clase privados:
//	string nombre;
//	Fecha fechaNac;

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


void Persona::SetFechaNac(Fecha f)
// Precondicion: Dato de tipo Fecha
// Poscondicion: Se establece la fecha de nacimiento con el parametro entrante
{
	fechaNac = f;
}


Fecha Persona::GetFechaNac()
// Precondicion: La funcion SetFechaNac tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la fecha de nacimiento de una persona
{
	return fechaNac;
}


Persona::~Persona()
// Destructor
{}