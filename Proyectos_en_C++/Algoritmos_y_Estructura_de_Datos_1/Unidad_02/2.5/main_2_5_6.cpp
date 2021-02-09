#include <iostream>

using namespace std;

void intercambiar(double &i , double &j ); //Protipo de la función para intercambiar los valores

int main(void)
{
    double a = 2, b = 3;
    cout<<"Valores originales  a = "<< a <<" y b = "<< b << endl;

    intercambiar(a,b); //Llmado a la función intercambiar

    cout<<"Luego de la funcion a = "<< a <<" y b = "<< b << endl;

    return 0;
}

void intercambiar(double &i, double &j)
{
    double z;
    z = i;
    i = j;
    j = z;
}
