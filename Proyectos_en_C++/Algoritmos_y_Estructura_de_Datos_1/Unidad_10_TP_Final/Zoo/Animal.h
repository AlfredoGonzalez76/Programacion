//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Animal.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Animal
//*************************************************************
#ifndef Animal_h
#define Animal_h

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

#endif // Animal_h