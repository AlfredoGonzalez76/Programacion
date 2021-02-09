#include <iostream>

#include "stdlib.h"

#include "registroDin.h"
#include "listaDin.h"

using namespace std;


// ----------------  PRINCIPAL  -----------------


int main()
{

	tListaDin lista;

	lista = crearListaDin();

	cout << endl;

	cargaListaDin(lista);

	muestraListaDin(lista);

	cout << endl;

//	ordenaListaPorIntercambio(lista);

	cout << endl;

	eliminaListaDin(lista);

	system("pause");

	return 0;
}
