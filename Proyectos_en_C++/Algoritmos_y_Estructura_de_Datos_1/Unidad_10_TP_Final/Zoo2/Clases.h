#ifndef Clases_h
#define Clases_h


#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal();
	virtual void SetName(string n);
	virtual string GetName();
	virtual void SetCode(int c);
	virtual int GetCode();
	virtual void Comer() = 0;
	virtual void Dormir() = 0;
	virtual ~Animal();
private:
	string nombre;
	int codigo;
};


class Oviparo : public Animal
{
public:
	Oviparo();
	virtual void Comer();
	virtual void Dormir();
	void ponerHuevos();
	~Oviparo();
};


class Mamifero : public Animal
{
public:
	Mamifero();
	virtual void Comer();
	virtual void Dormir();
	void Amamantar();
	~Mamifero();
};


class Cocodrilo : public Oviparo
{
public:
	Cocodrilo();

	void Comer();

	void Dormir();

	~Cocodrilo();
	
};


class Ganso : public Oviparo
{
public:
	Ganso();

	void Comer();

	void Dormir();

	~Ganso();
	
};


class Pelicano : public Oviparo
{
public:
	Pelicano();

	void Comer();

	void Dormir();

	~Pelicano();
	
};


class Murcielago : public Mamifero
{
public:
	Murcielago();

	void Comer();

	void Dormir();

	~Murcielago();
	
};


class Ballena : public Mamifero
{
public:
	Ballena();

	void Comer();

	void Dormir();

	~Ballena();
	
};


class LoboMarino : public Mamifero
{
public:
	LoboMarino();

	void Comer();

	void Dormir();

	~LoboMarino();
	
};

#endif // Clases_h