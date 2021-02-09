//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Fecha.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Fecha
//*************************************************************

#ifndef Fecha_h
#define Fecha_h

#include <iostream>

using namespace std;

class Fecha
{
public:
	Fecha();
	// Constructor


	void SetDia(int d);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el dia con el parametro entrante


	int GetDia();
	// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el campo dia correspondiente a una fecha


	void SetMes(int m);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el mes con el parametro entrante


	int GetMes();
	// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el campo mes correspondiente a una fecha


	void SetAnno(int a);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el anno con el parametro entrante


	int GetAnno();
	// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el campo anno correspondiente a una fecha


	Fecha tiempoTranscurrido(Fecha fechaPost);
	// Precondicion: Se le debe pasar un objeto de tipo fecha.
	// Poscondicion: Se obtiene la diferencia entre fechaPost y la fecha del objeto actual
	// si la fechaPost es posterior a la fecha del objeto actual y -1/-1/-1 en caso contrario


	~Fecha();
	// Destructor

private:
	int dia;
	int mes;
	int anno;
};

#endif // Fecha_h