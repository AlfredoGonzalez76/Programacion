//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Oviparo.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Oviparo
//*************************************************************
#ifndef Oviparo_h
#define Oviparo_h

#include "Animal.h"

class Oviparo : Animal
{
public:
	Oviparo();
	virtual void Comer();
	virtual void Dormir();
	void ponerHuevos();
	~Oviparo();
};


#endif // Oviparo_h