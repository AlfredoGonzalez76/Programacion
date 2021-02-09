#include <iostream>

using namespace std;


typedef double** tMatrizDin;   // Creo una matriz dinamica (puntero a un array dinamico)

typedef struct {
	tMatrizDin matriz;
	int rows;
	int cols;
} tMatDinStr;

// -----------  Prototipos de Funciones  ------------

// Crea una matriz dinamica (vacia). Solicita numero de filas y columnas
void creaMatrizStr(tMatDinStr& tabla);


tMatDinStr creaMatrizStr(int filas, int columnas);


// Inicializa la matriz dinamica solicitando los elementos al usuario
void inicializaMatrizStr(tMatDinStr& tabla);


// Recorre y muestra los elementos de la matriz dinamica
void muestraMatrizStr(tMatDinStr& tabla);

// Borra la matriz dinamica liberando la memoria
void borraMatrizStr(tMatDinStr& tabla);


tMatDinStr trasponeMatrizStr(tMatDinStr& tabla);

// Esta funcion crea y devuelve la matriz dinamica suma de las matrices dinamicas matA y matB
bool sumaMatriz(tMatDinStr& matA, tMatDinStr& matB, tMatDinStr& matC);


// ----------- PRINCIPAL  --------------

int main()
{
	tMatDinStr tablita1, tablita2, tablita3, tablita4;


	creaMatrizStr(tablita1);

	inicializaMatrizStr(tablita1);

	cout << "La matriz ingresada es: " << endl;
	muestraMatrizStr(tablita1);

// --------------------------------------------
	creaMatrizStr(tablita2);

	inicializaMatrizStr(tablita2);

	cout << "\nLa matriz ingresada es: " << endl;
	muestraMatrizStr(tablita2);

// --------------------------------------------

	if(sumaMatriz(tablita1, tablita2, tablita3))
	{
		cout << "\nLa suma de las matrices " <<endl;
		muestraMatrizStr(tablita1);
		cout << " y " << endl;
		muestraMatrizStr(tablita2);
		cout << " es " << endl;
		muestraMatrizStr(tablita3);
	}
	else
	{
		cout << "\nLas matrices " <<endl;
		muestraMatrizStr(tablita1);
		cout << " y " << endl;
		muestraMatrizStr(tablita2);
		cout << " tienen distintas dimensiones y la suma no es posible." << endl;
	}

	tablita4 = trasponeMatrizStr(tablita1);

	cout << "\nLa traspuesta de la matriz " << endl;

	muestraMatrizStr(tablita1);
	cout << " es: " << endl;
	muestraMatrizStr(tablita4);

	borraMatrizStr(tablita1);
	borraMatrizStr(tablita2);
	borraMatrizStr(tablita3);
	borraMatrizStr(tablita4);

	return 0;
}

// ----------- Implementacion de Funciones -------------

void creaMatrizStr(tMatDinStr& tabla)
{
	cout << "Ingrese el numero de filas de la matriz: ";
	cin >> tabla.rows;
	cin.ignore();

	cout << "Ingrese el numero de columnas de la matriz: ";
	cin >> tabla.cols;
	cin.ignore();

	tabla.matriz = new double*[tabla.rows];
	for (int i = 0; i < tabla.rows; i++)
	{
	  tabla.matriz[i] = new double[tabla.cols];
	}
}


tMatDinStr creaMatrizStr(int filas, int columnas)
{
	tMatDinStr tabla;

	tabla.rows = filas;
	tabla.cols = columnas;

	tabla.matriz = new double*[tabla.rows];
	for (int i = 0; i < tabla.rows; i++)
	{
	  tabla.matriz[i] = new double[tabla.cols];
	}
	return tabla;
}


void inicializaMatrizStr(tMatDinStr& tabla)
{
	for (int i = 0; i < tabla.rows; ++i)
	{
		for (int j = 0; j < tabla.cols; ++j)
		{
			cout << "Ingrese el elemento (" << i+1 << ',' << j+1 << ") : ";
			cin >> tabla.matriz[i][j];
			cin.ignore();
			cout << endl;
		}
		cout << endl;
	}
}


void muestraMatrizStr(tMatDinStr& tabla)
{
	for (int i = 0; i < tabla.rows; ++i)
	{
		for (int j = 0; j < tabla.cols; ++j)
		{
			cout << tabla.matriz[i][j] << ' ';
		}
		cout << endl;
	}
}


void borraMatrizStr(tMatDinStr& tabla)
{
   for (int i = 0; i < tabla.rows; i++) {
      delete [] tabla.matriz[i];
   }
   delete [] tabla.matriz;
}



tMatDinStr trasponeMatrizStr(tMatDinStr& tabla)
{
	tMatDinStr traspuesta;

	traspuesta = creaMatrizStr(tabla.cols, tabla.rows);

	for (int i = 0; i < tabla.cols; ++i)
	{
		for (int j = 0; j < tabla.rows; ++j)
		{
			traspuesta.matriz[i][j] = tabla.matriz[j][i];
		}
	}
	return traspuesta;
}


bool sumaMatriz(tMatDinStr& matA, tMatDinStr& matB, tMatDinStr& matC)
{
	bool esPosible;

	if((matA.rows == matB.rows)&&(matA.cols == matB.cols))
	{
		matC = creaMatrizStr(matA.rows, matA.cols);
		for (int i = 0; i < matA.rows; ++i)
		{
			for (int j = 0; j < matA.cols; ++j)
			{
				matC.matriz[i][j] = matA.matriz[i][j] + matB.matriz[i][j];
			}
		}
		esPosible = true;
	}
	else
	{
		esPosible = false;
	}
	return esPosible;
}