//*******************************************************************
// ARCHIVO DE IMPLEMENTACION (Ganso.cpp)
// Este archivo implementa las funciones miembro de Ganso.h
//*******************************************************************
#include "Ganso.h"
#include <iostream>
#include <string>

using namespace std;


Ganso::Ganso()
{}

void Ganso::Comer()
{
	cout << "Comer como un Ganso" << endl;
}


void Ganso::Dormir()
{
	cout << "Dormir como un Ganso" << endl;
}


Ganso::~Ganso()
{}