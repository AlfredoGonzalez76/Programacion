//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Mamifero.cpp)
// Este archivo implementa las funciones miembro de Mamifero
//**********************************************************************
#include "Mamifero.h"

#include <iostream>
#include <string>
#include "Mamifero.h"

using namespace std;

// Miembros de clase privados:


Mamifero::Mamifero()
{}

void Mamifero::Comer()
{
	cout << "Comer como los Mamiferos" <<endl;
}

void Mamifero::Dormir()
{
	cout << "Dormir como los Mamiferos" << endl;
}


void Mamifero::Amamantar()
{
	cout << "Amamantar a sus crias" << endl;
}

Mamifero::~Mamifero()
{}
