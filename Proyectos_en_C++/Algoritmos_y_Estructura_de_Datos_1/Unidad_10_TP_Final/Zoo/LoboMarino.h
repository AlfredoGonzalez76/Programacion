//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (LoboMarino.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos LoboMarino
//*************************************************************

#ifndef LoboMarino_h
#define LoboMarino_h
#include "Mamifero.h"

class LoboMarino : public Mamifero
{
public:
	LoboMarino();

	void Comer();

	void Dormir();

	~LoboMarino();
	
};

#endif // LoboMarino_h