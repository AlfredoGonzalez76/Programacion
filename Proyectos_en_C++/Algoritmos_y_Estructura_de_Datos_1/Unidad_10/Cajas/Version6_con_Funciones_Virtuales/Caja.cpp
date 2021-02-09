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
	cout << "Se invoca al constructor de Caja" << endl;
}

Caja::Caja(const Caja& c)
{
	largo = c.largo;
	ancho = c.ancho;
	alto = c.alto;
	cout << "Invocando el constructor por copia de Caja" << endl;
}

double Caja::volumen() const
{
	return largo*ancho*alto;
}

void Caja::mostrarVolumen(void) const
{
	cout << endl << "El volumen de la caja es: " << volumen() << endl;
}

Caja::~Caja()
{
	cout << "Se invoca al destructor de Caja" << endl;
}