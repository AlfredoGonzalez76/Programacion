//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Persona.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Persona
//*************************************************************

#ifndef Persona_h
#define Persona_h

#include "Fecha.h"

#include <string>
#include <iostream>

using namespace std;

class Persona
{
public:
	Persona();
	// Constructor


	void SetNombre(string nom);
	// Precondicion: Dato de tipo string
	// Poscondicion: Se establece el nombre con el parametro entrante


	string GetNombre();
	// Precondicion: La funcion SetNombre tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el nombre de una persona


	void SetFechaNac(Fecha f);
	// Precondicion: Dato de tipo Fecha
	// Poscondicion: Se establece la fecha de nacimiento con el parametro entrante


	Fecha GetFechaNac();
	// Precondicion: La funcion SetFechaNac tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la fecha de nacimiento de una persona


	~Persona();
	// Destructor

private:
	string nombre;
	Fecha fechaNac;
};


#endif // Persona_h