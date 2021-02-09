#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    string nombre;
    char datos[256];
    int compresion;
 
    cout << "Comprobador de imágenes BMP" << endl;
    cout << "Dime el nombre del fichero: ";
    getline(cin, nombre);
 
    ifstream fichero(nombre.c_str(), ifstream::binary);
 
    if ( fichero.fail() )
        cout << "No encontrado" << endl;
    else 
    {
        fichero.seekg(0, fichero.beg);
        fichero.read(datos,4);
        if ((datos[0] == 'B') && (datos[1] == 'M'))
        {
            cout << "Se trata de un archivo de imagenes .BMP" <<endl;
        }
        else
        {
            cout << "Mas alla de la extension que tenga, no se trata de un archivo .BMP" << endl;
        }
  }
 
    return 0;
}