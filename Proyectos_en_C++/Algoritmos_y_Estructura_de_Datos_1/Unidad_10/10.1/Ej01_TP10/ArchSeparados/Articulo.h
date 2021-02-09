//******************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Articulo.h)
// Este archivo proporciona la especificación
// del tipo de datos abstractos Articulo
//******************************************************************

#ifndef Articulo_h
#define Articulo_h

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

#endif // Articulo_h