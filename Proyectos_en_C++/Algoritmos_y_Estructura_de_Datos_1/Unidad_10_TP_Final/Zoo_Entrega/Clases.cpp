// ---------------- IMPLEMENTACION ---------------------

#include "Clases.h"


#include <iostream>
#include <string>

using namespace std;

Animal::Animal(string n = "Animal", int c = 0)
{
	SetName(n);
	SetCode(c);
}

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

void Animal::Comer()
{
	cout << "Comer como " << GetName() << endl;
}


void Animal::Dormir()
{
	cout << "Dormir como " << GetName() << endl;
}


Animal::~Animal(){}



Oviparo::Oviparo(string n,int c) : Animal(n, c)
{}


bool Oviparo::ponerHuevos()
{
	return true;
}


bool Oviparo::Amamantar()
{
	return false;
}

Oviparo::~Oviparo()
{}


Mamifero::Mamifero(string n,int c) : Animal(n, c)
{}


bool Mamifero::ponerHuevos()
{
	return false;
}


bool Mamifero::Amamantar()
{
	return true;
}


Mamifero::~Mamifero()
{}



Cocodrilo::Cocodrilo(string n ,int c) : Oviparo(n,c)
{}

Cocodrilo::~Cocodrilo()
{}


Ganso::Ganso(string n,int c) : Oviparo(n,c)
{}

Ganso::~Ganso()
{}



Pelicano::Pelicano(string n,int c) : Oviparo(n,c)
{}

Pelicano::~Pelicano()
{}


Murcielago::Murcielago(string n,int c) : Mamifero(n,c)
{}

Murcielago::~Murcielago()
{}


Ballena::Ballena(string n,int c) : Mamifero(n,c)
{}

Ballena::~Ballena()
{}


LoboMarino::LoboMarino(string n,int c) : Mamifero(n,c)
{}

LoboMarino::~LoboMarino()
{}

