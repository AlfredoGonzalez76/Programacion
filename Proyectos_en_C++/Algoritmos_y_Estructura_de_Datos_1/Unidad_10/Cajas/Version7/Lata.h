#pragma once
#include "contenedor.h"

class Lata : public Contenedor
{
	public:
		Lata(double al=4.0, double d=2.0);
		virtual double volumen() const;
		~Lata(void);
	protected:
		double alto;
		double diametro;
};
