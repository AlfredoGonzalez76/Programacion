#include <iostream>
#include <string>
#include <iomanip>

#include "registroDin.h"

using namespace std;

int main()
{
	tRegPtr puntReg;

	nuevoRegistro(puntReg);

	muestraRegistroCompleto(puntReg);

//	modificaRegistro(puntReg);

	eliminaRegistro(puntReg);

	return 0;
}
