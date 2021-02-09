#ifndef listaDin_h
#define listaDin_h

#include "registroDin.h"



typedef struct {
	tRegPtr* elementos;
	int contador;
	int maximo;
} tListaDin;


// --------------- Prototipos de Funciones ------------------

tListaDin crearListaDin();

void cargaListaDin(tListaDin& listita);

void muestraListaDin(tListaDin& listita);

void eliminaListaDin(tListaDin& listita);


#endif