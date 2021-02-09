#ifndef menus_h
#define menus_h

using namespace std;

// -------------------------   MENUS   ------------------------------

// Menu para operaciones Globales sobre las listas de todos los cursos.
int menuPrincipal();


// Menu con las operaciones a realizar en una carrera determinada.
int menuPorCarrera(int carrera, int anio);


// Funcion que coloca el encabezado correspondiente a la carrera y anio seleccionados.
void mostrarCabeceraCarrera(int carrera, int anio);


// Menu para elegir la carrera sobre la cual se va a trabajar.
int eligeCarrera();


// Menu para elegir el anio sobre el que se va a trabajar.
int eligeAnio();


// Menu que permite seleccionar el tipo de ordenamiento que se aplicará sobre una lista o todo el libro.
int menuOrdenacion();

#endif