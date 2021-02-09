#include <iostream>
#include <stdlib.h>  // para system("pause")

using namespace std;


class Figura
{
public:
	Figura();

	virtual void dibujar();

	virtual void borrar();

	void rotar();

	void mover();

	~Figura();
	
};


// ------------- IMPLEMENTACION ------------

Figura::Figura()
{
	cout << "Constructor de Figura." << endl;
}


void Figura::dibujar()
{
	cout << "Dibuja Figura." << endl;
}


void Figura::borrar()
{
	cout << "Borra Figura." << endl;
}


void Figura::rotar()
{
	cout << "Rota Figura." << endl;
}


void Figura::mover()
{
	cout << "Mueve Figura." << endl;
}

Figura::~Figura()
{
	cout << "Destructor de Figura" << endl;
}


// -----------------------------------------------

class Circulo : public Figura
{
public:
	Circulo();

	void dibujar();

	void borrar();

	~Circulo();
	
};

// ------------- IMPLEMENTACION ------------

Circulo::Circulo()
{
	cout << "Constructor de Circulo." << endl;
}


void Circulo::dibujar()
{
	cout << "Dibuja Circulo." << endl;
}


void Circulo::borrar()
{
	cout << "Borra Circulo." << endl;
}


Circulo::~Circulo()
{
	cout << "Destructor de Circulo" << endl;
}

// ----------------------------------------------

class Rectangulo : public Figura
{
public:
	Rectangulo();

	void dibujar();

	void borrar();

	~Rectangulo();
	
};

// ------------- IMPLEMENTACION ------------


Rectangulo::Rectangulo()
{
	cout << "Constructor de Rectangulo." << endl;
}


void Rectangulo::dibujar()
{
	cout << "Dibuja Rectangulo." << endl;
}


void Rectangulo::borrar()
{
	cout << "Borra Rectangulo." << endl;
}


Rectangulo::~Rectangulo()
{
	cout << "Destructor de Rectangulo" << endl;
}



// ----------------------------------------------

class Triangulo : public Figura
{
public:
	Triangulo();

	void dibujar();

	void borrar();

	~Triangulo();
	
};


// ------------- IMPLEMENTACION ------------


Triangulo::Triangulo()
{
	cout << "Constructor de Triangulo." << endl;
}


void Triangulo::dibujar()
{
	cout << "Dibuja Triangulo." << endl;
}


void Triangulo::borrar()
{
	cout << "Borra Triangulo." << endl;
}


Triangulo::~Triangulo()
{
	cout << "Destructor de Triangulo" << endl;
}


// ------------- PRINCIPAL ------------


int main()
{
	Figura* elemento[5] = {};  // Array de punteros nulos a la clase base
	char op;

	for (int i = 0; i < 5; ++i)
	{
		do
		{
			cout << endl;
			cout << "1) Crear Figura." << endl;
			cout << "2) Crear Circulo." << endl;
			cout << "3) Crear Rectangulo." << endl;
			cout << "4) Crear Triangulo." << endl;
			cout << "Pulse la opcion deseada: " ;
			cin >> op ;
			cin.ignore();
			cout << endl;
		} while ((op != '1') && (op != '2') && (op != '3') && (op != '4'));
		switch (op)
		{
			case '1':
				elemento[i] = new Figura;
			break;
			case '2':
				elemento[i] = new Circulo;
			break;
			case '3':
				elemento[i] = new Rectangulo;
			break;
			case '4':
				elemento[i] = new Triangulo;
			break;
		}
		elemento[i] -> dibujar();
		elemento[i] -> borrar();
	}

	delete [] elemento ;


	system("pause");


	return 0;
}