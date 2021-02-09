#ifndef listaDin_h
#define listaDin_h


#include "extrasDin.h"
#include "menus.h"
#include "registroDin.h"

using namespace std;


const int MaxDim = 100;

typedef tRegistro tArray[MaxDim];

typedef struct {
   tArray elementos;
   int contador = 0;
} tLista;


//------------------  Funciones sobre Listas   ------------------------



/*
// Funcion que muestra una lista correspondiente a una carrera y un anio.
void mostrarLista(tLista& listita);


// Funcion que muestra lista de un curso con la informacion completa de cada registro.
void mostrarListaConNotas(tLista& listita);


// Funcion que permite agregar un registro a una lista.
void agregaRegistro(tLista& listita);


// Funcion que permite eliminar un registro de una lista.
void eliminaRegistro(tLista& listita, int posicion);


// Esta funcion busca 'fragmento' entre todos los Nombres y Apellidos de la lista
void buscaNomApeEnLista(tLista& listita, string fragmento);


// Función que ordena una lista de acuerdo al tipo de ordenamiento seleccionado en el menuOrdenacion.
void ordenaListaPorIntercambio(tLista& listita, int op);


// Esta funcion ejecuta el tipo de accion sobre una lista que haya sido seleccionada en menuPorCarrera
void ejecutarEnLista(int opcion, tLista& listita);
*/

/*

// ---------------   Funciones Estadisticas sobre Listas   -----------------


// Muestra la estadistica de Notas de una lista (grupo de alumnos).
void estadistica(tLista& listita);


// Calcula la media de las Notas de una lista.
double media(tLista& listita);


// Calcula la varianza de las Notas de una lista. 
double varianza(tLista& listita);


// Calcula el desvio de las Notas de una Lista.
double desvio(tLista& listita);


// Devuelve la Nota Maxima de una Lista.
int maxima(tLista& listita);


// Devuelve la Nota Minima de una Lista.
int minima(tLista& listita);


// Devuelve la moda entre las Notas de una Lista.
int moda(tLista& listita);


// Quiero copiar solo las notas en un array. Como las funciones no devuelven un array,use este recurso. Esta func. devuelve un puntero 
int* copiaNotas(tLista& listita);   //  https://www.youtube.com/watch?v=rxAUwddWfQk


// Calcula la mediana de las Notas de la Lista por el metodo Burbuja
double medianaPorBurbuja(tLista& listita);
*/

#endif