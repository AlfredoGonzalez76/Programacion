/*
Programó Carlos Ramos
@carlillos_Ramos
www.elbloggerdecarlos.blogspot.com
Licencia: Abierta.
De modo especial les pido que si copian el ejemplo
direccionen al blog donde se ha publicado originalmente.
Saludos!

[Compila, y muestra un resultado esperado.]
*/

//Hecho en VS 2010, si usas borland o devC++
//Sustituye la cabece precompilada #include "stdafx.h"
//por las tradicionales conio.h y stdio.h
#include "stdafx.h"
#include <iostream>
using namespace std;


void main (void)
{
	//Matriz 4x4 
	int matriz[4][4];
	//Número de filas y columnas
	int col=4, fil=4;
	//Valor que asignaré a cada elemento de la matriz
	int valor=0;
	//Vector de punteros
	int *p[4];
	//Puntero a puntero
	int **q;

	//Lleno la matriz con valores
	for (int i=0; i<fil; i++)
		for(int j=0;j<col; j++)
			matriz[i][j]=valor++;

	//Cada elemento del vector "p" apunta a una fila de la matriz
	for (int i=0; i<4;i++)
		p[i]=matriz[i];

	//El puntero "q" apunta al vector "p"
	q=p;
	//Función prototipo que asigna valores a una matriz
	//Por referencia.
	void Asignamatriz(int **&matriz,int fil, int col);
	//Función prototipo que Imprime valores de una matriz
	//Por valor.
	void Imprimematriz(int**matriz, int fil, int col);

	//Empleo la función que asigna valores.
	Asignamatriz(q,fil,col);

	//Función que imprime la matriz.
	Imprimematriz(q,fil, col);
}

	void Asignamatriz(int **&matriz, int fil, int col)
	{

		//Incremento en uno el valor de cada elemento de la matriz
		//Valores que ya tenía la matriz al ser recibida.
		for (int i=0; i<fil; i++)
			for(int j=0;j<col; j++)
				matriz[i][j]++;
	}


	void Imprimematriz(int**matriz, int fil, int col)
	{
		//Imprime la matriz que se recibe como argumento.
		for (int i=0; i<fil; i++)
			{
				for(int j=0;j<col; j++)
					cout<<matriz[i][j]<<" ";
				cout <<endl;

			}
	}