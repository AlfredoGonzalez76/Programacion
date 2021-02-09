#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    int ID, edad;
    string nombre;
    char genero;
    ifstream archivo;

    archivo.open("Datos.csv");  


    string linea;
    while(std::getline(archivo,linea))
    {
        stringstream stream(linea);
        string valor;

        cout << "Contenido de la linea:\n";
        while(std::getline(stream,valor,','))
        {
            cout << "valor leido: " << valor << '\n';
        }
        cout << "Fin de la linea\n";
    }

    archivo.close();

    return 0;
}