//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Caja.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Caja
//*************************************************************

#ifndef Caja_h
#define Caja_h

#include <iostream>

class Caja
{
	public:
		Caja(double lar, double an, double al);

		double Volumen();

		~Caja();

	private:
		double largo;
		double ancho;
		double alto;
};

#endif // Caja_h