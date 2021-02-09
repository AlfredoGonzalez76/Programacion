//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Circulo.cpp)
// Este archivo implementa las funciones miembro de Circulo
//**********************************************************************

#include "Circulo.h"
#include "Figura.h"

#include <iostream>
using namespace std;

Circulo::Circulo()
{
	cout << "Constructor de Circulo." << endl;
}


void Circulo::dibujar()
{
	cout << "Dibuja Circulo." << endl;
}


void Circulo::borrar()
{
	cout << "Borra Circulo." << endl;
}


Circulo::~Circulo()
{
	cout << "Destructor de Circulo" << endl;
}
