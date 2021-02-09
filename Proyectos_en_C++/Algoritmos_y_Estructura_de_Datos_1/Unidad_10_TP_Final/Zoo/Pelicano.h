//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Pelicano.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Pelicano
//*************************************************************

#ifndef Pelicano_h
#define Pelicano_h
#include "Oviparo.h"

class Pelicano : public Oviparo
{
public:
	Pelicano();

	void Comer();

	void Dormir();

	~Pelicano();
	
};

#endif // Pelicano_h