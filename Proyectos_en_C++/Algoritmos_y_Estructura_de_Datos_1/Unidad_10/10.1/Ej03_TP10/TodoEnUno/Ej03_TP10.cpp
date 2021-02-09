#include <iostream>
using namespace std;

class Rectangulo
{
public:
	Rectangulo();
	// Constructor


	void SetAltura(float al);
	// Precondicion: Dato numerico
	// Poscondicion: Se establece la altura del rectangulo con el parametro entrante


	float GetAltura();
	// Precondicion: La funcion SetAltura tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la altura del rectangulo


	void SetBase(float ba);
	// Precondicion: Dato numerico
	// Poscondicion: Se establece la base del rectangulo con el parametro entrante


	float GetBase();
	// Precondicion: La funcion SetBase tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la base del rectangulo


	float area();
	// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Se obtiene el area del rectangulo


	float perimetro();
	// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Se obtiene el perimetro del rectangulo


	~Rectangulo();
	// Destructor

private:
	float altura;
	float base;
};



Rectangulo::Rectangulo()
// Constructor
{}

void Rectangulo::SetAltura(float al)
// Precondicion: Dato numerico
// Poscondicion: Se establece la altura del rectangulo con el parametro entrante
{
	altura = al;
}


float Rectangulo::GetAltura()
// Precondicion: La funcion SetAltura tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la altura del rectangulo
{
	return altura;
}


void Rectangulo::SetBase(float ba)
// Precondicion: Dato numerico
// Poscondicion: Se establece la base del rectangulo con el parametro entrante
{
	base = ba;
}


float Rectangulo::GetBase()
// Precondicion: La funcion SetBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la base del rectangulo
{
	return base;
}


float Rectangulo::area()
// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
// Poscondicion: Se obtiene el area del rectangulo
{
	return (base * altura);
}

float Rectangulo::perimetro()
// Precondicion: La funcion SetBase y SetAltura tienen que haber sido invocadas al menos una vez.
// Poscondicion: Se obtiene el perimetro del rectangulo
{
	return (2*(base + altura));
}


Rectangulo::~Rectangulo()
// Destructor
{}



int main()
{
	Rectangulo rectangulo;
	float auxReal;

	cout << "Vamos a calcular el area y perimetro de un Rectangulo." <<endl;
	cout << "\nIngrese la altura del Rectangulo: ";
	cin >> auxReal;
	cin.ignore();
	rectangulo.SetAltura(auxReal);

	cout << "\nIngrese la base del Rectangulo: ";
	cin >> auxReal;
	cin.ignore();
	rectangulo.SetBase(auxReal);
	
	cout << "\nEl area del Rectangulo es: " << rectangulo.area() << endl;

	cout << "\nEl perimetro del Rectangulo es: " << rectangulo.perimetro() << endl;

	return 0;
}
