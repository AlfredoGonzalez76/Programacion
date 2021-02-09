//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Rectangulo.cpp)
// Este archivo implementa las funciones miembro de Rectangulo
//**********************************************************************

#include "Rectangulo.h"
#include "Figura.h"

#include <iostream>
using namespace std;

Rectangulo::Rectangulo()
{
	cout << "Constructor de Rectangulo." << endl;
}


void Rectangulo::dibujar()
{
	cout << "Dibuja Rectangulo." << endl;
}


void Rectangulo::borrar()
{
	cout << "Borra Rectangulo." << endl;
}


Rectangulo::~Rectangulo()
{
	cout << "Destructor de Rectangulo" << endl;
}
