//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Figura.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Figura
//*************************************************************

#ifndef Figura_h
#define Figura_h

class Figura
{
public:
	Figura();

	virtual void dibujar();

	virtual void borrar();

	void rotar();

	void mover();

	virtual ~Figura();
	
};

#endif // Figura_h