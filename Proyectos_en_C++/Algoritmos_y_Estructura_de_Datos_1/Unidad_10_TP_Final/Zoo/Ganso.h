//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Ganso.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Ganso
//*************************************************************

#ifndef Ganso_h
#define Ganso_h
#include "Oviparo.h"

class Ganso : public Oviparo
{
public:
	Ganso();

	void Comer();

	void Dormir();

	~Ganso();
	
};

#endif //Ganso_h