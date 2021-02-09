#ifndef Clases_h
#define Clases_h


#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal(string,int);
	void SetName(string n);
	string GetName();
	void SetCode(int c);
	int GetCode();
	virtual void Comer();
	virtual void Dormir();
	virtual bool ponerHuevos() = 0;
	virtual bool Amamantar() = 0;
	virtual ~Animal();
private:
	string nombre;
	int codigo;
};


class Oviparo : public Animal
{
public:
	Oviparo(string,int);
	bool ponerHuevos();
	bool Amamantar();
	~Oviparo();
};


class Mamifero : public Animal
{
public:
	Mamifero(string,int);
	bool ponerHuevos();
	bool Amamantar();
	~Mamifero();
};


class Cocodrilo : public Oviparo
{
public:
	Cocodrilo(string,int);
	~Cocodrilo();
};


class Ganso : public Oviparo
{
public:
	Ganso(string,int);
	~Ganso();
};


class Pelicano : public Oviparo
{
public:
	Pelicano(string,int);
	~Pelicano();
};


class Murcielago : public Mamifero
{
public:
	Murcielago(string,int);
	~Murcielago();
};


class Ballena : public Mamifero
{
public:
	Ballena(string,int);
	~Ballena();
};


class LoboMarino : public Mamifero
{
public:
	LoboMarino(string,int);
	~LoboMarino();	
};

#endif // Clases_h