//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Murcielago.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Murcielago
//*************************************************************

#ifndef Murcielago_h
#define Murcielago_h
#include "Mamifero.h"

class Murcielago : public Mamifero
{
public:
	Murcielago();

	void Comer();

	void Dormir();

	~Murcielago();
	
};

#endif // Murcielago_h