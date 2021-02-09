#include "Contenedor.h"
#include <iostream>
using std::cout;
using std::endl;

void Contenedor::mostrarVolumen() const
{
	cout << endl
	<< "El volumen de la caja es: " << volumen() << endl;
}

Contenedor::~Contenedor(void)
{
	cout<<"Invocado el destructor de Contenedor"<<endl;
}
