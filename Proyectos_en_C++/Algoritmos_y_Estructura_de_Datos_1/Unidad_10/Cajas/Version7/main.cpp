#include <iostream>
#include "CajaBotellas.h"
#include "Lata.h"

#include <stdlib.h>  // para system("pause")

using std::cout;
using std::endl;

int main()
{
	// puntero a la clase base abstracta Contenedor que apunta a un obeto Caja nuevo
	Contenedor* pc1 = new Caja(2.0, 3.0, 4.0);
	// puntero a la clase base abstracta Contenedor que apunta a un obeto Caja nuevo
	Contenedor* pl1 = new Lata(6.5, 3.0);

	Lata l1(6.5, 3.0); //crea otra lata igual a la anterior
	CajaBotellas cb(2.0, 3.0, 4.0);//crea caja de botellas
	pc1 -> mostrarVolumen();
	pl1 -> mostrarVolumen();
	cout << endl;
	//limpia el espacio asignado dinámicamente
	delete pc1;
	delete pl1;
	//inicializa pc1 con la dirección de la lata l1
	pc1 = &l1;
	pc1 -> mostrarVolumen();

	//ahora el puntero pc1 apunta a la dirección de CajaBotellas cb
	pc1=&cb;
	pc1->mostrarVolumen();

	system("pause");
	
	return 0;
}
