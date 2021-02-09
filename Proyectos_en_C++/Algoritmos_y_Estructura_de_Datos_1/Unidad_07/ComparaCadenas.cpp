#include <iostream>
#include <cstring> //Importante agregar esta biblioteca para hacer uso de las funciones 
 
using namespace std;
 
int main () {
    
    //Declaramos las cadenas 
    string cadena1 = "mazamorra";
    string cadena2 = "maximizar";
    string cadena3 = "máximo";
 
    //Mostramos el nombre de las cadenas al usuario 
    cout << "La cadena uno se llama: " << cadena1 << endl;
    cout << "La cadena dos se llama: " << cadena2 << endl;
   
    //Comparando cadenas
    cout << "Comparando cadena 1 con respecto a cadena 1, es igual a: " << (cadena1 == cadena1) << endl;
    cout << "Comparando cadena 1 con respecto a cadena 2, es igual a: " << (cadena1 < cadena2) << endl;
    cout << "Comparando cadena 2 con respecto a cadena 3, es igual a: " << (cadena2 > cadena3) << endl;
 
    return 0;
}