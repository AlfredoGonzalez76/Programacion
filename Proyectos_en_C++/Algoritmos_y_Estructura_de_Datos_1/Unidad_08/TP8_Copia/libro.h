#ifndef libro_h
#define libro_h


#include <string>

#include "menus.h"
#include "registro.h"
#include "lista.h"
#include "extras.h"


const int cantCarreras = 6;
const int cantAnios = 3;

typedef tLista tLibro[cantCarreras][cantAnios];


//------------------  Funciones sobre Libro   ------------------------

// Funcion que muestra la base de datos completa: Las listas correspondientes a cada curso diferente.
void mostrarLibro(tLibro& librito);


// Esta funcion busca 'fragmento' entre los Nombres y Apellidos de todas las listas del libro (base de datos)
void buscaNomApeEnLibro(tLibro& librito, string fragmento);


// Función que ordena todo el libro de acuerdo al tipo de ordenamiento seleccionado en el menuOrdenacion.
void ordenaLibroPorIntercambio(tLibro& librito, int op);


// Esta funcion ejecuta el tipo de accion sobre el libro que haya sido seleccionada en el menuPrincipal
void ejecutarEnLibro(char opcion, tLibro& librito);


//--------------------- ESTADISTICA TOTAL  -------------------

// Muestra la estadistica de todas Notas de las diferentes listas del libro.
void estadisticaTotal(tLibro& librito);


// ----------------   Manejo de Archivos   ---------------

// En caso de utilizar archivos de texto la informacion se guarda y lee de la sig. manera:
// El primer renglón consta de un entero correspondiente al numero de carrera.
// El segundo renglón consta de un entero que corresponde al anio que cursa.
// Luego, un campo por cada línea y cada registro de la lista debajo del anterior.


// Funcion para leer la base de datos completa.
void leerLibroDeArchivo(string nombreArch, tLibro& librito);


// Funcion que cueta el total de alumnos en todo el libro.
int cuentaAlumnos(tLibro& librito);


// Funcion que permite persistir la informacion de todo el libro en el archivo de nombre nombreArch
void escribeLibroEnArchivo(string nombreArch, tLibro& librito);

#endif