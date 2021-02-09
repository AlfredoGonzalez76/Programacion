//*******************************************************************
// ARCHIVO DE IMPLEMENTACION (Pelicano.cpp)
// Este archivo implementa las funciones miembro de Pelicano.h
//*******************************************************************
#include "Pelicano.h"
#include <iostream>
#include <string>

using namespace std;


Pelicano::Pelicano()
{}

void Pelicano::Comer()
{
	cout << "Comer como un Pelicano" << endl;
}


void Pelicano::Dormir()
{
	cout << "Dormir como un Pelicano" << endl;
}


Pelicano::~Pelicano()
{}