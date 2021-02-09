//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Triangulo.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Triangulo
//*************************************************************

#ifndef Triangulo_h
#define Triangulo_h

#include "Figura.h"

class Triangulo : public Figura
{
public:
	Triangulo();

	void dibujar();

	void borrar();

	~Triangulo();
	
};

#endif // Triangulo_h