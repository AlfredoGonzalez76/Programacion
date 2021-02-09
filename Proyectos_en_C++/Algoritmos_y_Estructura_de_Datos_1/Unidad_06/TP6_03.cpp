#include <iostream>
using namespace std;

const int N = 2;

typedef double matriz[N][N];

typedef int tVecInt[N];


// ------------------ Funciones ---------------------

void ingresaMatriz(matriz& d);

void muestraMatriz(matriz d);

void sumaMatrices(matriz a, matriz b, matriz& c);

void multiplicaMatrices(matriz a, matriz b, matriz& c);

void restaMatrices(matriz a, matriz b, matriz& c);

void trasponeMatriz(matriz& d);

void buscaPuntosSilla(matriz a);


int main()
{
	matriz a = {}, b = {}, c = {};

	ingresaMatriz(a);
	cout << "La matriz ingresada es: " << endl;
	muestraMatriz(a);
	cout << endl;

	ingresaMatriz(b);
	cout << "La matriz ingresada es: " << endl;
	muestraMatriz(b);
	cout << endl;

	cout << "La suma de las matrices ingresadas es: \n " << endl;
	sumaMatrices(a,b,c);
	muestraMatriz(c);
	cout << endl;

	cout << "La resta de las matrices ingresadas es: \n" << endl;
	restaMatrices(a,b,c);
	muestraMatriz(c);
	cout << endl;


	cout << "La traspuesta de la matriz " << endl;
	muestraMatriz(a);
	cout << "es: " << endl;
	trasponeMatriz(a);
	muestraMatriz(a);

	cout << "Para la matriz " << endl;
	muestraMatriz(a);
	
	buscaPuntosSilla(a);

	return 0;
}


void ingresaMatriz(matriz& d)
{
	cout << "Vamos a llenar la matriz." << endl;
	cout << endl;
	cout << "Le iremos solicitando los distintos elementos." << endl;
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << '(' << (i+1) << ',' << (j+1) << ") : " << ' ';
			cin >> d[i][j];
		}
		cout << endl;
	}
}


void muestraMatriz(matriz d)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
}

void sumaMatrices(matriz a, matriz b, matriz& c)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}


void restaMatrices(matriz a, matriz b, matriz& c)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}



void multiplicaMatrices(matriz a, matriz b, matriz& c)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}


void trasponeMatriz(matriz& d)
{
	matriz t;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			t[i][j] = d[j][i];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			d[i][j] = t[i][j];
		}
	}

}


/*e) Mostrar una matriz señalando cuáles son los puntos de silla 
(los puntos de silla de una matriz son aquellos elementos de la misma
 que cumplen ser el mínimo de su fila y el máximo de su columna). */


void buscaPuntosSilla(matriz a)
{
	double min;
	tVecInt colMin, cont;

	for (int i = 0; i < N; ++i)
	{
		min = a[i][0];
		colMin[i] = 0 ;    // Aquí guardaré la coordenada (columna) donde se encuentra el minimo de la fila 'i'
		for (int j = 1; j < N; ++j)
		{
			if (a[i][j] < min)
				{
					colMin[i] = j;
				}	
		}
	}
	for (int j = 0; j < N; ++j)
	{
		cont[j] = 0;    // Aqui acumula la cantidad de elementos de la columna que son menores que el minimo
		for (int i = 0; i < N; ++i)
		{
			if((a[j][colMin[j]] > a[i][colMin[j]]) && (i != colMin[i]))
			{
				cont[j]++;
			}
		}
		if(cont[j] == N-1)  // Si contabilizó N-1 elementos significa que 
		{
			cout << "Hay un punto silla en la ubicacion " << '(' << (j+1) << ',' << (colMin[j]+1) << ')' << endl;
		}
	}
}
