#include <iostream>

using namespace std;


class Articulo
{
public:
	Articulo();
	// Constructor

	void SetCostoBase(float CB);
	// Precondicion: Dato numerico
	// Poscondicion: El costo base de un producto se establece con el parametro entrante

	float GetCostoBase();
	// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se muestra el costo base de un producto

	float PVPMayor();
	// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se calcula el costo por Mayor de un producto

	float PVPDetal();
	// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se calcula el costo al Detal de un producto

	~Articulo();
	// Destructor

private:
	float costoBase;
};

Articulo::Articulo()
// Constructor
{}

void Articulo::SetCostoBase(float CB)
// Precondicion: Dato numerico
// Poscondicion: El costo base de un producto se establece con el parametro entrante
{
	costoBase = CB;
}


float Articulo::GetCostoBase()
// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se muestra el costo base de un producto
{
	return costoBase;
}


float Articulo::PVPMayor()
// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se calcula el costo por Mayor de un producto
{
	return costoBase * 1.15;
}


float Articulo::PVPDetal()
// Precondicion: La funcion SetCostoBase tiene que haber sido invocada al menos una vez.
// Poscondicion: Se calcula el costo al Detal de un producto
{
	return costoBase * 1.3;
}


Articulo::~Articulo()
// Destructor
{}


int main()
{
	Articulo articulo;
	float costoB;

	cout << "Ingrese el costo base del articulo: ";
	cin >> costoB;
	cin.ignore();

	articulo.SetCostoBase(costoB);

	cout << "El Precio de Venta por Mayor es: " << articulo.PVPMayor() << endl;
	cout << endl;

	cout << "El Precio de Venta al Detal es: " << articulo.PVPDetal() << endl;

	return 0;
}