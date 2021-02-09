#include <iostream>

using namespace std;

class Caja
{
	public:
		Caja(double lar, double an, double al);

		double Volumen();

		~Caja();

	private:
		double largo;
		double ancho;
		double alto;
};


Caja::Caja(double lar, double an, double al)
{
	largo = lar;
	ancho = an;
	alto = al;
}

double Caja::Volumen()
{
	return largo * ancho * alto;
}

Caja::~Caja()
{}


int main()
{
	Caja unaCaja(0.57, 0.25, 0.55);

	cout << "Volumen de la caja: " << unaCaja.Volumen() << " metros cubicos." << endl;


	return 0;
}
