//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Oviparo.cpp)
// Este archivo implementa las funciones miembro de Oviparo
//**********************************************************************
#include "Oviparo.h"

#include <iostream>
#include <string>

using namespace std;

// Miembros de clase privados:
//	string name;
//	int code;


Oviparo::Oviparo()
{}

void Oviparo::Comer()
{
	cout << "Comer como los Oviparos" <<endl;
}

void Oviparo::Dormir()
{
	cout << "Dormir como los oviparos" << endl;
}

void Oviparo::ponerHuevos()
{
	cout << "Poner Huevos" << endl;
}

Oviparo::~Oviparo()
{}