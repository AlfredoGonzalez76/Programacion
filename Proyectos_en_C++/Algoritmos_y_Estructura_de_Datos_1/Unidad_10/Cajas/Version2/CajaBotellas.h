//Archivo de cabecera CajaBotellas.h
#pragma once
#include "caja.h"
class CajaBotellas : public Caja
{
	public:
		CajaBotellas(int nro=1);
		double volumen(void);
		~CajaBotellas(void);
	private:
		int nrobotellas;
};
