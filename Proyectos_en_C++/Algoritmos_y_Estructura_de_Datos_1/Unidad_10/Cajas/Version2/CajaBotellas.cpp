//archivo CajaBotellas.cpp
#include "CajaBotellas.h"
#include <iostream>
using std::cout;
using std::endl;

CajaBotellas::CajaBotellas(int nro)
{
	nrobotellas=nro;
}

double CajaBotellas::volumen(void)
{
	return 0.85*Caja::volumen();//ojo no olvidar :: para invocar volumen() de Caja
}

CajaBotellas::~CajaBotellas(void)
{
	//cout << "Se invoca al destructor de CajaBotellas" << endl;
}
