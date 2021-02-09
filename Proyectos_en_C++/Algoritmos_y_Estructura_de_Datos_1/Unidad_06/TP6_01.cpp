#include <iostream>
#include <fstream>
using namespace std;

//--------------  Tipos de datos Introducidos  -----------------

const int Dimension = 5000;

typedef struct {
   int id;
   double precio;
   int stock;
} tProducto;


typedef tProducto tArray[Dimension];

typedef struct {
   tArray elementos;
   int contador;
} tLista;


tLista leerListaDeArchivo(string nombreArch);

void mostrarListado(tLista& listita);

