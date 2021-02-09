//Archivo cabecera Caja.h

#pragma once

#include "Contenedor.h"

class Caja: public Contenedor
{
public:
	Caja(double l=1.0, double an=1.0, double al=1.0);
	Caja(const Caja& c);
	virtual double volumen(void) const;
	void mostrarVolumen() const;
	~Caja();
protected:
	double largo;
	double ancho;
	double alto;
};
