//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Triangulo.cpp)
// Este archivo implementa las funciones miembro de Triangulo
//**********************************************************************

#include "Triangulo.h"
#include "Figura.h"

#include <iostream>
using namespace std;

Triangulo::Triangulo()
{
	cout << "Constructor de Triangulo." << endl;
}


void Triangulo::dibujar()
{
	cout << "Dibuja Triangulo." << endl;
}


void Triangulo::borrar()
{
	cout << "Borra Triangulo." << endl;
}


Triangulo::~Triangulo()
{
	cout << "Destructor de Triangulo" << endl;
}
