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

    while (archivo.good()) {
        cout << "ID: " << ID << " " ;

        getline(archivo, nombre, ',') ;
        cout << "User: " << nombre << " " ;

        getline(archivo, edad, ',') ;
        cout << "Edad: " << edad << " "  ; 

        getline(archivo, genero);
        cout << "Sexo: " <<  genero<< " "  ;
    }

    archivo.close();

    return 0;
}