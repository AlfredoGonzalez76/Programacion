//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Mamifero.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Mamifero
//*************************************************************
#ifndef Mamifero_h
#define Mamifero_h

#include "Animal.h"

class Mamifero : Animal
{
public:
	Mamifero();
	virtual void Comer();
	virtual void Dormir();
	void Amamantar();
	~Mamifero();
};


#endif // Mamifero_h