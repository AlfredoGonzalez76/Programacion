//Archivo cabecera Caja.h
#pragma once

class Caja
{
public:
	Caja(double l=1.0, double an=1.0, double al=1.0);
	Caja(const Caja& c);
	double volumen(void);
	~Caja(void);
private:
	double largo;
	double ancho;
	double alto;
};
