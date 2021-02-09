//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Rectangulo.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Rectangulo
//*************************************************************

#ifndef Rectangulo_h
#define Rectangulo_h

#include "Figura.h"

class Rectangulo : public Figura
{
public:
	Rectangulo();

	void dibujar();

	void borrar();

	~Rectangulo();
	
};

#endif // Rectangulo_h