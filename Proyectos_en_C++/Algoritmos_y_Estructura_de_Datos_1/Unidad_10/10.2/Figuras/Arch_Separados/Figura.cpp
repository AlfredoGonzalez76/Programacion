//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Figura.cpp)
// Este archivo implementa las funciones miembro de Figura
//**********************************************************************

#include "Figura.h"

#include <iostream>
using namespace std;

Figura::Figura()
{
	cout << "Constructor de Figura." << endl;
}


void Figura::dibujar()
{
	cout << "Dibuja Figura." << endl;
}


void Figura::borrar()
{
	cout << "Borra Figura." << endl;
}


void Figura::rotar()
{
	cout << "Rota Figura." << endl;
}


void Figura::mover()
{
	cout << "Mueve Figura." << endl;
}

Figura::~Figura()
{
	cout << "Destructor de Figura" << endl;
}
