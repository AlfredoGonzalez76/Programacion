//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Rectangulo.cpp)
// Este archivo implementa las funciones miembro de Rectangulo.h
//**********************************************************************

#include "Rectangulo.h"

#include <iostream>
using namespace std;


// Miembros de clase privados:
//	float altura;
//	float base;


Rectangulo::Rectangulo()
// Constructor
{}

void Rectangulo::SetAltura(float al)
// Precondicion: Dato numerico
// Poscondicion: Se establece la altura del rectangulo con el parametro entrante
{
	altura = al;
}


float Rectangulo::GetAltura()
// Precondicion: La funcion SetAltura tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la altura del rectangulo
{
	return altura;
}


void Rectangulo::SetBase(float ba)
// Precondicion: Dato numerico
// Poscondicion: Se establece la base del rectangulo con el parametro entrante
{
	base = ba;
}


float Rectangulo::GetBase()
// Precondicion: La funcion SetBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la base del rectangulo
{
	return base;
}


float Rectangulo::area()
// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
// Poscondicion: Se obtiene el area del rectangulo
{
	return (base * altura);
}

float Rectangulo::perimetro()
// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
// Poscondicion: Se obtiene el perimetro del rectangulo
{
	return (2*(base + altura));
}


Rectangulo::~Rectangulo()
// Destructor
{}