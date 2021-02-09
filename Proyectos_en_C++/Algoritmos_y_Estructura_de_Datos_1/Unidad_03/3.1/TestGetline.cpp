#include <iostream>
#include <string>

using namespace std;

/* Una Verdulería nos pide que armemos el pedido para el mayorista para lo cual
deberemos pedir al usuario el código de proveedor, razón social, fecha de solicitud
y fecha de entrega. Las frutas estarán enumeradas (tomar solo 6 a modo de ejemplo),
mostrando los datos por pantalla.
 */

string ingresaNombre();
void escribeNombre(string nom);

int main()
{
	string nom;
	nom = ingresaNombre();
	escribeNombre(nom);

	return 0;
}

string ingresaNombre()
{
	string nombre;
	cout << "Ingrese su nombre completo: ";
	getline(cin,nombre);
	return nombre;	
}

void escribeNombre(string nomb)
{
	cout << "Su nombre es: " << nomb << endl;
}