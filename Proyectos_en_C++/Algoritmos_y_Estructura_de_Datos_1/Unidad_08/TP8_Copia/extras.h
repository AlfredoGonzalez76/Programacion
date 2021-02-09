#ifndef extras_h
#define extras_h

#include <string>
using namespace std;

// ------------------   Funciones Extra   --------------------

// Funcion que permite pasar a mayuscula toda una cadena de caracteres.
string mayuscula(string cadena);


// Funcion booleana: devuelve true si 'fragmento' se encuentra en 'palabra'.
bool In(string fragmento, string palabra);


// Intercambia los valores de dos enteros.          FUNCION SOBRECARGADA
void intercambio(int& a, int& b);

#endif