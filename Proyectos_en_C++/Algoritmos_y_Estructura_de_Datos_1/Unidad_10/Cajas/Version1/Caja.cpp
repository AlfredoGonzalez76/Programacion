//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Caja.cpp)
// Este archivo implementa las funciones miembro de Caja.h
//**********************************************************************

#include "Caja.h"

#include <iostream>

using namespace std;

// Miembros de clase privados:
//	double largo;
//	double ancho;
//	double alto;


Caja::Caja(double lar, double an, double al)
{
	largo = lar;
	ancho = an;
	alto = al;
}

double Caja::Volumen()
{
	return largo * ancho * alto;
}

Caja::~Caja()
{}
