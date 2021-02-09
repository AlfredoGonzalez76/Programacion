//***************************************************************
// ARCHIVO DE IMPLEMENTACION (Articulo.cpp)
// Este archivo implementa las funciones miembro de Articulo.h
//***************************************************************

#include "Articulo.h"
#include <iostream>

using namespace std;

// Miembros de clase privados:
//	float costoBase;

Articulo::Articulo()
// Constructor
{}


void Articulo::SetCostoBase(float CB)
// Precondicion: Dato numerico
// Poscondicion: El costo base de un producto se establece con el parametro entrante
{
	costoBase = CB;
}


float Articulo::GetCostoBase()
// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el costo base de un producto
{
	return costoBase;
}


float Articulo::PVPMayor()
// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se calcula el costo por Mayor de un producto
{
	return costoBase * 1.15;
}


float Articulo::PVPDetal()
// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se calcula el costo al Detal de un producto
{
	return costoBase * 1.3;
}


Articulo::~Articulo()
// Destructor
{}
