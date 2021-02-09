//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Persona.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Persona
//*************************************************************

#ifndef Persona_h
#define Persona_h

#include <string>
#include <iostream>

using namespace std;

class Persona
{
public:
	Persona();
	// Constructor


	void SetNombre(string nom);
	// Precondicion: Dato de tipo string
	// Poscondicion: Se establece el nombre con el parametro entrante


	string GetNombre();
	// Precondicion: La funcion SetNombre tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el nombre de una persona


	void SetDiaNac(int d);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el dia con el parametro entrante


	int GetDiaNac();
	// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el dia de nacimiento de una persona


	void SetMesNac(int m);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el mes de nacimiento con el parametro entrante


	int GetMesNac();
	// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el mes de nacimiento de una persona


	void SetAnnoNac(int a);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el anno de nacimiento con el parametro entrante


	int GetAnnoNac();
	// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el mes de nacimiento de una persona


	void SetDiaAct(int da);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el dia actual con el parametro entrante


	int GetDiaAct();
	// Precondicion: La funcion SetDiaAct tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el dia actual


	void SetMesAct(int ma);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el mes actual con el parametro entrante


	int GetMesAct();
	// Precondicion: La funcion SetMesAct tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el mes actual


	void SetAnnoAct(int aa);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el anno actual con el parametro entrante


	int GetAnnoAct();
	// Precondicion: La funcion SetAnnoAct tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el anno actual


	int obtenerEdad();
	// Precondicion: La funcion SetDia, SetMes, SetAnno, SetDiaAct, SetMesAct, SetAnnoAct
	//               tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Se obtiene la edad de la persona


	~Persona();
	// Destructor

private:
	string nombre;
	int dianac;
	int mesnac;
	int annonac;
	int diaact;
	int mesact;
	int annoact;
};


#endif // Persona_h