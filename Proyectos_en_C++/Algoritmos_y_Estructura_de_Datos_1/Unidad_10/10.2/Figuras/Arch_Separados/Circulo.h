//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Circulo.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Circulo
//*************************************************************

#ifndef Circulo_h
#define Circulo_h
#include "Figura.h"

class Circulo : public Figura
{
public:
	Circulo();

	void dibujar();

	void borrar();

	~Circulo();
	
};

#endif // Circulo_h