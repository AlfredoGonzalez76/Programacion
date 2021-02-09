#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3;

	cout << "Calcularemos el promedio de tres numeros." << endl;
	cout << "Ingrese el primer numero: ";
	cin >> num1;
	cout << "Ingrese el segundo numero: ";
	cin >> num2;
	cout << "Ingrese el tercer numero: ";
	cin >> num3;

	cout << "El promedio es: " << (num1 + num2 + num3)/3 << endl;

	return 0;
}