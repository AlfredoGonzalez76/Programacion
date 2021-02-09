#include "Clases.h"

#include <iostream>
#include <string>

using namespace std;

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


Cocodrilo::Cocodrilo()
{}

void Cocodrilo::Comer()
{
	cout << "Comer como un Cocodrilo" << endl;
}


void Cocodrilo::Dormir()
{
	cout << "Dormir como un Cocodrilo" << endl;
}


Cocodrilo::~Cocodrilo()
{}


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


Murcielago::Murcielago()
{}

void Murcielago::Comer()
{
	cout << "Comer como un Murcielago" << endl;
}


void Murcielago::Dormir()
{
	cout << "Dormir como un Murcielago" << endl;
}


Murcielago::~Murcielago()
{}


Ballena::Ballena()
{}

void Ballena::Comer()
{
	cout << "Comer como una Ballena" << endl;
}


void Ballena::Dormir()
{
	cout << "Dormir como una Ballena" << endl;
}


Ballena::~Ballena()
{}


LoboMarino::LoboMarino()
{}

void LoboMarino::Comer()
{
	cout << "Comer como un LoboMarino" << endl;
}


void LoboMarino::Dormir()
{
	cout << "Dormir como un LoboMarino" << endl;
}


LoboMarino::~LoboMarino()
{}