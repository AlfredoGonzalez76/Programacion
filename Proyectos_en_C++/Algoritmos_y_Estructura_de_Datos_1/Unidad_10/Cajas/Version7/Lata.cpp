#include "Lata.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

const double PI = std::atan(1.0)*4;

Lata::Lata(double al, double d):alto(al), diametro(d)
{
	cout << "Invocado constructor de Lata" << endl;
}

double Lata::volumen() const
{
	return PI * diametro * diametro * alto;
}

Lata::~Lata(void)
{
	cout << "Invocado destructor de Lata" << endl;
}
