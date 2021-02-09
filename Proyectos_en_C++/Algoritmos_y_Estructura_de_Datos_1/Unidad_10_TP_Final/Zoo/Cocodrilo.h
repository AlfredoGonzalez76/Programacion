//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Cocodrilo.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Cocodrilo
//*************************************************************

#ifndef Cocodrilo_h
#define Cocodrilo_h
#include "Oviparo.h"

class Cocodrilo : public Oviparo
{
public:
	Cocodrilo();

	void Comer();

	void Dormir();

	~Cocodrilo();
	
};

#endif //Cocodrilo_h