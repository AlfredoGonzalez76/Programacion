//Archivo Caja.cpp
#include "Caja.h"
#include <iostream>
using std::cout;
using std::endl;

Caja::Caja(double l, double an, double al)
{
	largo=l;
	ancho=an;
	alto=al;
}
	double Caja::volumen(void)
{
	return largo*ancho*alto;
}
	Caja::~Caja(void)
{
	//cout << "Se invoca al destructor de Caja" << endl;
}