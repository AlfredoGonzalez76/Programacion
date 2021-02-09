#include <iostream>
#include "CajaBotellas.h"

#include <stdlib.h>  // para system("pause")

using std::cout;
using std::endl;

int main()
{
	Caja caja1(4.0, 3.0, 2.0);
	CajaBotellas cajab1;
	CajaBotellas cajab2(6);
	cout << "Volumen de caja1: " << caja1.volumen() << endl
	<< "Volumen de cajab1: " << cajab1.volumen() << endl
	<< "Volumen de cajab2: " << cajab2.volumen() << endl;

	system("pause");
	
	return 0;
}
