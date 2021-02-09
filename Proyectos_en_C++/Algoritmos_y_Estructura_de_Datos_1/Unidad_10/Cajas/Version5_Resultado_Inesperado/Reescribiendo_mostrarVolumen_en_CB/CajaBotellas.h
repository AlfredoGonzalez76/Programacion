//Archivo de cabecera CajaBotellas.h
#pragma once
#include "Caja.h"
class CajaBotellas : public Caja
{
	public:
		CajaBotellas(int nro=1);
		CajaBotellas(double l, double an, double al, int nro=1);
		CajaBotellas(const CajaBotellas& cb);
		double volumen(void);
		void mostrarVolumen(void);
		~CajaBotellas(void);
	private:
		int nrobotellas;
};
