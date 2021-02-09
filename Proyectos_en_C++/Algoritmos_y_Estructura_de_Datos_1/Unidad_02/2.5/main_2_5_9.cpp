#include <iostream>
using namespace std;

/* Escribir un Programa en C++ que duplique el valor dos números con una función 
Duplicar(int a, int b), pero a y b están definidas en el código… 
Mostrar los valores de a y b, antes y después del llamado de la Función.
{Nota: EL presente ejercicio es para “Inducir” al alcance de las Variables
 y el pasaje de Parámetros, dado que como vimos “hasta ahora” solo le pasamos
 un valor y no la variable en si. Comprenda y Conceptualice el Ejercicio, escriba 
 debajo del Código un Texto y relaciónelo con la pregunta 11 (opcional 12).  */

void Duplicar(int &a, int &b);

int main()
{
	int a, b;

	cout << "Ingrese el valor de a = ";
	cin >> a;

	cout << "Ingrese el valor de b = ";
	cin >> b;

	Duplicar(a,b);

	cout << "El doble del valor 'a' introducido es " << a << " y el doble de 'b' es " << b << endl;

	return 0;
}

void Duplicar(int &a, int &b)
{
	a = 2 * a;
	b = 2 * b;
}

/* Aquí es necesario pasar los parámetros por referencia a fin de que puedan ser afectados
por las modificaciones hechas en Duplicar. De haberlos pasado por valor, los valores de
'a' y 'b' hubieran permanecido inalterados. */