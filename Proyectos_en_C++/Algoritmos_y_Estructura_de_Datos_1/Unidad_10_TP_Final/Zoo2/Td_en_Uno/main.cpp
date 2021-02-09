
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


// ---------------- IMPLEMENTACION ---------------------



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



Cocodrilo::Cocodrilo(string n,int c) : Oviparo(n,c)
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



int main()
{

	Animal* animal[5] = {};  // Array de punteros nulos a la clase base
	char op;

	for (int i = 0; i < 5; ++i)
	{
		do
		{
			cout << endl;
			cout << "1) Dar vida a un Cocodrilo." << endl;
			cout << "2) Dar vida a un Ganso." << endl;
			cout << "3) Dar vida a un Pelicano." << endl;
			cout << "4) Dar vida a un Murcielago." << endl;
			cout << "5) Dar vida a una Ballena." << endl;
			cout << "6) Dar vida a un Lobo Marino." << endl;
			cout << "Seleccione la opcion deseada: " ;
			cin >> op ;
			cin.ignore();
			cout << endl;
		} while ((op != '1') && (op != '2') && (op != '3') && (op != '4') && (op != '5') && (op != '6'));
		switch (op)
		{
			case '1':
//				animal[i] = new Cocodrilo("Cocodrilo",21);
				animal[i] = new Cocodrilo;
			break;
			case '2':
				animal[i] = new Ganso("Ganso",22);
			break;
			case '3':
				animal[i] = new Pelicano("Pelicano",23);
			break;
			case '4':
				animal[i] = new Murcielago("Murcielago",24);
			break;
			case '5':
				animal[i] = new Ballena("Ballena",25);
			break;
			case '6':
				animal[i] = new LoboMarino("Lobo Marino",26);
			break;
		}
		animal[i] -> Comer();
		animal[i] -> Dormir();

		if (animal[i] -> ponerHuevos())
		{
			cout << "Se trata de un Oviparo" << endl;
		}
		else
		{
			cout << "Se trata de un Mamifero" << endl;
		}

	}
	for (int i = 0; i < 5; ++i)
	{
		delete animal[i];
	}

	system("pause");

	return 0;
}