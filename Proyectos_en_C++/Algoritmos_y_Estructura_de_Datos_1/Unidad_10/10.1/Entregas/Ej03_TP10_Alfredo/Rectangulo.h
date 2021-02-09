//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Rectangulo.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Rectangulo
//*************************************************************

#ifndef Rectangulo_h
#define Rectangulo_h

#include <iostream>
using namespace std;

class Rectangulo
{
public:
	Rectangulo();
	// Constructor


	void SetAltura(float al);
	// Precondicion: Dato numerico float
	// Poscondicion: Se establece la altura del rectangulo con el parametro entrante


	float GetAltura();
	// Precondicion: La funcion SetAltura tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la altura del rectangulo


	void SetBase(float ba);
	// Precondicion: Dato numerico float
	// Poscondicion: Se establece la base del rectangulo con el parametro entrante


	float GetBase();
	// Precondicion: La funcion SetBase tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la base del rectangulo


	float area();
	// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Se obtiene el area del rectangulo


	float perimetro();
	// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Se obtiene el perimetro del rectangulo


	~Rectangulo();
	// Destructor

private:
	float altura;
	float base;
};


#endif // Rectangulo_h