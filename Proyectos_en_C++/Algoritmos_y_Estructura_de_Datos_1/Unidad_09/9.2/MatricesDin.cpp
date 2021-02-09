#include <iostream>

using namespace std;


typedef double** tMatrizDin;   // Creo una matriz dinamica (puntero a un array dinamico)


// --------------  Funciones  ---------------

// Solicita la dimension de la matriz (numero de filas y de columnas)
void pideRowCol(int& nRow, int& nCol);

// Crea la matriz dinamica (vacia)
void creaMatriz(tMatrizDin& matriz, int nRow, int nCol);

// Inicializa la matriz dinamica solicitando los elementos
void inicializarMatriz(tMatrizDin& matriz, int nRow, int nCol);

// Muestra la matriz con nRow filas y nCol columnas
void muestraMatriz(tMatrizDin& matriz, int nRow, int nCol);

// Borra la matriz liberando la memoria
void borraMatriz(tMatrizDin& matriz, int nRow, int nCol);

// Esta funcion no muestra sino que CREA (y devuelve) la matriz dinamica traspuesta de 'matriz'
tMatrizDin trasponeMatriz(tMatrizDin& matriz, int nRow, int nCol);

// Esta funcion crea y devuelve la matriz dinamica suma de las matrices dinamicas matA y matB
tMatrizDin sumaMatriz(tMatrizDin& matA, tMatrizDin& matB, int nRow, int nCol);


// --------------  PRINCIPAL  ---------------

int main()
{
	tMatrizDin matDinA = NULL, matDinB = NULL, matDinC = NULL, matDinT = NULL;
	int row, col;


	pideRowCol(row, col);

	creaMatriz(matDinA, row, col);

	inicializarMatriz(matDinA, row, col);

	cout << "\n La matriz ingresada es: " << endl;

	muestraMatriz(matDinA, row, col);

	cout << endl;

	// --------------------------------------------

	creaMatriz(matDinB, row, col);

	inicializarMatriz(matDinB, row, col);

	cout << "\nLa matriz ingresada es: " << endl;

	muestraMatriz(matDinB, row, col);

	cout << endl;

	// --------------------------------------------

	matDinC = sumaMatriz(matDinA, matDinB, row, col);

	cout << "\nLa suma de estas dos matrices es: " << endl;

	muestraMatriz(matDinC, row, col);

	// ---------------------------------------------

	cout << "\nLa matriz traspuesta de esta ultima es: " << endl;

 	matDinT = trasponeMatriz(matDinC, row, col);

	muestraMatriz(matDinT, col, row);

	// ---------------------------------------------

	borraMatriz(matDinA, row, col);

	borraMatriz(matDinB, row, col);

	borraMatriz(matDinC, row, col);

	borraMatriz(matDinT, col, row);

	// ---------------------------------------------

	return 0;
}


void pideRowCol(int& nRow, int& nCol)
{
	cout << "Ingrese el numero de filas de la matriz: ";
	cin >> nRow;
	cin.ignore();

	cout << "Ingrese el numero de columnas de la matriz: ";
	cin >> nCol;
	cin.ignore();
}


void creaMatriz(tMatrizDin& matriz, int nRow, int nCol)
{

	matriz = new double*[nRow];
	for (int i = 0; i < nRow; i++)
	{
	  *(matriz+i) = new double[nCol];
	}
}


void inicializarMatriz(tMatrizDin& matriz, int nRow, int nCol)
{
	for (int i = 0; i < nRow; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
			cout << "Ingrese el elemento (" << i+1 << ',' << j+1 << ") : ";
			cin >> *(*(matriz+i)+j);
			cin.ignore();
			cout << endl;
		}
		cout << endl;
	}
}


void muestraMatriz(tMatrizDin& matriz, int nRow, int nCol)
{
	for (int i = 0; i < nRow; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
			cout << *(*(matriz+i)+j) << ' ';
		}
		cout << endl;
	}
}


void borraMatriz(tMatrizDin& matriz, int nRow, int nCol)
{
   for (int i = 0; i < nRow; i++) {
      delete [] *(matriz+i);
   }
   delete [] matriz;
}


tMatrizDin sumaMatriz(tMatrizDin& matA,tMatrizDin& matB, int nRow, int nCol)
{
	tMatrizDin matC;

	creaMatriz(matC, nRow, nCol);

	for (int i = 0; i < nRow; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
			*(*(matC+i)+j) = *(*(matA+i)+j) + *(*(matB+i)+j);
		}
	}

	return matC;
}


tMatrizDin trasponeMatriz(tMatrizDin& matriz, int nRow, int nCol)
{
	tMatrizDin traspuesta;

	creaMatriz(traspuesta, nCol, nRow);

	for (int i = 0; i < nCol; ++i)
	{
		for (int j = 0; j < nRow; ++j)
		{
			*(*(traspuesta+i)+j) = *(*(matriz+j)+i);
		}
	}
	return traspuesta;
}