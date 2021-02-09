#include <iostream>
#include "CajaBotellas.h"

/*
En la funcion main( )
de una clase de prueba, se invoca dicha función para mostrar los datos de una Caja y de una
CajaBotellas, de las mismas dimensiones (en caso de CajaBotellas el volumen debería ser 85% menor
que la Caja de mismas dimensiones). Se observa que al ser invocada produce los mismos resultados.
*/

#include <stdlib.h>  // para system("pause")

using std::cout;
using std::endl;


void Output(const Caja& c); //prototipo de función para ver referencia +func.virtuales


int main()
{
	Caja caja1(4.0, 3.0, 2.0);
	CajaBotellas cajab1(4.0, 3.0, 2.0);
	Caja* cajap=0; //puntero nulo a la clase base Caja
	caja1.mostrarVolumen();
	cajab1.mostrarVolumen();//sino es virtual se llama volumen de la clase Caja
	cajap=&caja1; //puntero a objeto de la clase base
	cajap->mostrarVolumen();
	cajap=&cajab1; //puntero a objeto de la clase derivada
	cajap->mostrarVolumen();
	cout<<endl;

	system("pause");
	
	return 0;
}

void Output(const Caja& c)
{
	c.mostrarVolumen();
}