#ifndef registro_h
#define registro_h

#include <string>
using namespace std;

//--------------  Tipos de datos Introducidos  -----------------

const int Dimension = 100;

typedef struct {
   string apellidos;
   string nombres;
   int edad;
   int dni;
   int nota;
} tRegistro;


//------------------  Funciones sobre Registros   ------------------------

// Funcion que muestra solo un registro con la informacion de todos sus campos.
void muestraRegistroCompleto(tRegistro& registro);


// Funcion que carga datos a un registro.
tRegistro cargaRegistro();


// Funcion que permite modificar campos de un registro.
void modificaRegistro(tRegistro& registro);


// Intercambia dos registros.                       FUNCION SOBRECARGADA
void intercambio(tRegistro& a, tRegistro& b);

#endif