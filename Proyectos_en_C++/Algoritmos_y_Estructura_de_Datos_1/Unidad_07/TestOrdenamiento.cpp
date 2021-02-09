#include <iostream>
using namespace std;

void ordAscendentePorIntercambio(int a[], int n);

void ordDescendentePorIntercambio(int a[], int n);


int main()
{
	int b[12] = {3,5,2,8,1,9,0,-4,-7,6,11,2};


	cout << "Arreglo Desordenado: ";
	for (int k = 0; k < 12; ++k)
	{
		cout << b[k] << ", ";
	}
	cout << endl;

	ordAscendentePorIntercambio(b, 12);

	cout << "Arreglo Ordenado Ascendente: ";
	for (int k = 0; k < 12; ++k)
	{
		cout << b[k] << ", ";
	}
	cout << endl;

	ordDescendentePorIntercambio(b, 12);

	cout << "Arreglo Ordenado Descendente: ";
	for (int k = 0; k < 12; ++k)
	{
		cout << b[k] << ", ";
	}
	cout << endl;

	return 0;
}

void ordAscendentePorIntercambio(int a[], int n)
{
	int aux;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(a[i] > a[j])
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
}

void ordDescendentePorIntercambio(int a[], int n)
{
	int aux;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(a[i] < a[j])
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
}