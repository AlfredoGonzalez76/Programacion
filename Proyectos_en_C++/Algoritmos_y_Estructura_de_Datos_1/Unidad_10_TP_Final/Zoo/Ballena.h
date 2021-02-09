//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Ballena.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Ballena
//*************************************************************

#ifndef Ballena_h
#define Ballena_h
#include "Mamifero.h"

class Ballena : public Mamifero
{
public:
	Ballena();

	void Comer();

	void Dormir();

	~Ballena();
	
};

#endif // Ballena_h