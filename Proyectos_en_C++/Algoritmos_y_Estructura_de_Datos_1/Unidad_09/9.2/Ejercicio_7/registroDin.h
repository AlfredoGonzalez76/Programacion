#ifndef registroDin_h
#define registroDin_h

#include <string>
using namespace std;


typedef struct {
   string apellidos;
   string nombres;
   int edad;
   int dni;
   int nota;
} tRegistro;

typedef tRegistro* tRegPtr;


tRegPtr nuevoRegistro();

void muestraRegistroCompleto(tRegPtr& registro);

void modificaRegistro(tRegPtr& registro);

void eliminaRegistro(tRegPtr& registro);


#endif