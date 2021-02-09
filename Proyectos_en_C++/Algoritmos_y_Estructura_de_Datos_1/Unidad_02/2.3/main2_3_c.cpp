#include <iostream>
using namespace std;

/* Realizar un programa que pida los datos necesarios y Calcule
los Perímetros de Triángulos, Rectángulos o Cuadrados*/

int main()
{
	char figura;
	float lado1, lado2, lado3;

	cout << "A que figura le desea calcular el perimetro?" << endl;
	cout << "* Cuadrado (C) "<< endl;
	cout << "* Rectangulo (R) "<< endl;
	cout << "* Triangulo (T) "<< endl;
	cout << endl;
	cout << "Su eleccion: ";
	do
	{
		cin >> figura;
		figura = toupper(figura);
	}
	while ((figura != 'C') && (figura != 'R') && (figura != 'T'));
	if (figura == 'C')
	{
		cout << "Ingrese la medida de un lado del Cuadrado: ";
		cin >> lado1;
		cout << "El perimetro del Cuadrado es de " << 4 * lado1 << " unidades." << endl;
	}
	else if (figura == 'R')
	{
		cout << "Ingrese la medida de dos lados consecutivos del Rectangulo: " << endl;
		cout << "Lado 1: ";
		cin >> lado1;
		cout << "Lado 2: ";
		cin >> lado2;
		cout << "El perimetro del Rectangulo es de " << 2 * (lado1 + lado2) << " unidades." << endl;
	}
	else
	{
		cout << "Ingrese la medida de los tres lados del Triangulo: " << endl;
		cout << "Lado 1: ";
		cin >> lado1;
		cout << "Lado 2: ";
		cin >> lado2;
		cout << "Lado 3: ";
		cin >> lado3;
		cout << "El perimetro del Triangulo es de " << (lado1 + lado2 + lado3) << " unidades." << endl;
	}
	return 0;
}