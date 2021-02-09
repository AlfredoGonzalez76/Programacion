//archivo CajaBotellas.cpp
#include "CajaBotellas.h"
#include <iostream>
using std::cout;
using std::endl;

CajaBotellas::CajaBotellas(int nro)
{
	cout << "Se invoca al constructor 1 de CajaBotellas" << endl;
	nrobotellas = nro;
}

CajaBotellas::CajaBotellas(double l, double an, double al, int nro) : Caja(l, an, al)
{
	cout << "Se invoca al constructor 2 de CajaBotellas" << endl;
	nrobotellas = nro;
}

CajaBotellas::CajaBotellas(const CajaBotellas& cb):Caja(cb)
{
	cout << "Invocando constructor por copia de CajaBotellas" << endl;
	nrobotellas = cb.nrobotellas;	
}

double CajaBotellas::volumen(void) const
{
	return 0.85 * Caja::volumen();//ojo no olvidar :: para invocar volumen() de Caja
}


CajaBotellas::~CajaBotellas(void)
{
	//cout << "Se invoca al destructor de CajaBotellas" << endl;
}
