//**********************************************************************
// ARCHIVO DE IMPLEMENTACION (Animal.cpp)
// Este archivo implementa las funciones miembro de Animal
//**********************************************************************
#include "Animal.h"

#include <iostream>
#include <string>

using namespace std;

// Miembros de clase privados:
//	string nombre;
//	int codigo;

Animal::Animal(){}

void Animal::SetName(string n)
{
	nombre = n;
}

string Animal::GetName()
{
	return nombre;
}


void Animal::SetCode(int c)
{
	codigo = c;
}


int Animal::GetCode()
{
	return codigo;
}

Animal::~Animal(){}
