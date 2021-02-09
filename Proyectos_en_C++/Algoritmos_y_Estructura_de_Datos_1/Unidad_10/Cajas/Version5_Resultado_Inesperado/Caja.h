//Archivo cabecera Caja.h

/*
Se añade a la clase Caja una función miembro mostrarVolumen( ) que se encarga de invocar a la función
volumen( ) y mostrar en pantalla el valor calculado por dicha función. Esta función, por pertenecer a la
interfaz pública de esta clase base es heredada por las clases derivadas de la misma.
*/
#pragma once

class Caja
{
public:
	Caja(double l=1.0, double an=1.0, double al=1.0);
	Caja(const Caja& c);
	double volumen(void);
	void mostrarVolumen();
	~Caja();
private:
	double largo;
	double ancho;
	double alto;
};
