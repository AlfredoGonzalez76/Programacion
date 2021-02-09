//*************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Alumno.h)
// Este archivo proporciona la especificación
// de un tipo de datos abstractos Alumno
//*************************************************************

#ifndef Alumno_h
#define Alumno_h

#include <string>
#include <iostream>

using namespace std;

class Alumno
{
public:
	Alumno();
	// Constructor

	void SetCedula(string ced);
	// Precondicion: Dato alfanumerico
	// Poscondicion: Se establece la cedula con el parametro entrante


	string GetCedula();
	// Precondicion: La funcion SetCedula tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la cedula de un alumno


	void SetNombre(string nom);
	// Precondicion: Dato de tipo string
	// Poscondicion: Se establece el nombre con el parametro entrante


	string GetNombre();
	// Precondicion: La funcion SetNombre tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el nombre de un alumno


	void SetNota1(float n1);
	// Precondicion: Dato numerico float
	// Poscondicion: Se establece la primera nota con el parametro entrante


	float GetNota1();
	// Precondicion: La funcion SetNota1 tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la primera nota de un alumno


	void SetNota2(float n2);
	// Precondicion: Dato numerico float
	// Poscondicion: Se establece la segunda nota con el parametro entrante


	float GetNota2();
	// Precondicion: La funcion SetNota2 tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la segunda nota de un alumno


	void SetNota3(float n3);
	// Precondicion: Dato numerico float
	// Poscondicion: Se establece la tercera nota con el parametro entrante


	float GetNota3();
	// Precondicion: La funcion SetNota3 tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la tercera nota de un alumno


	float NotaFinal();
	// Precondicion: Las funciones SetNota1, SetNota2 y SetNota3 tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Se obtiene la nota final de un alumno


	string AproRepro();
	// Precondicion: Las funciones SetNota1, SetNota2, SetNota3 y NotaFinal tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Genera un mensaje con la condicion final de un alumno: Aprobado o Reprobado


	~Alumno();
	// Destructor

private:
	string cedula;
	string nombre;
	float nota1;
	float nota2;
	float nota3;
};


#endif // Alumno_h