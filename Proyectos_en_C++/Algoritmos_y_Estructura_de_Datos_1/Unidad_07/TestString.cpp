#include <iostream>
#include <cstring> //Importante agregar esta biblioteca para hacer uso de las funciones 
 
using namespace std;
 
int main () {
    
    //Declaramos las cadenas 
    char cadena1[] = "maza";
    char cadena2[] = "mástil";
 
    //Mostramos el nombre de las cadenas al usuario 
    cout << "La cadena uno se llama: " << cadena1 << "\n";
    cout << "La cadena dos se llama: " << cadena2 << "\n";
   
    //Comparando cadenas
    cout << "Comparando cadena 1 con respecto a cadena 2, es igual a: " << strcmp(cadena1, cadena2) << "\n";
    cout << "Comparando cadena 2 con respecto a cadena 1, es igual a: " << strcmp(cadena2, cadena1) << "\n";
 
    return 0;
}