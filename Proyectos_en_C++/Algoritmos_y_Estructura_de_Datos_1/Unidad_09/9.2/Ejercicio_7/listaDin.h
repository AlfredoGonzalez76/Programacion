#ifndef listaDin_h
#define listaDin_h

#include "registroDin.h"



typedef struct {
	tRegPtr* elementos;
	int contador;
	int maximo;
} tListaDin;


// --------------- Prototipos de Funciones Basicas ------------------

// Pide al usuario el numero maximo de registros a almacenar y devuelve una lista dinamica 
tListaDin crearListaDin();

// Mientras no se supere el numero maximo de registros, pregunta si quiere crear y almacenar nuevos registros
void cargaListaDin(tListaDin& listita);

// Muestra la lista completa de registros almacenados
void muestraListaDin(tListaDin& listita);

// Elimina el contenido (registros) y la propia estructura de la lista.
void eliminaListaDin(tListaDin& listita);


// -------------- Prototipos de Funciones Adicionales -------------

// En lugar de devolver la nota maxima, devuelve la ubicacion en la lista del alumno con la nota maxima
void maximaNota(tListaDin& listita);

#endif