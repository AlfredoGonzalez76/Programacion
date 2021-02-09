/*Comprobar si un número es par o impar, y señalar la posicion de memoria
donde se está guardando el número. Con punteros.*/

#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	//creo 2 variables una de tipo Puntero, ambas en el Stack (Pila)
	int numero, *dir_numero;

	cout<<"Digite un numero: "; cin>>numero; //Pedimos el numero al usuario

	//Agigna al Puntero el Valor de la Direccion de Numero
	dir_numero = &numero;

	if(*dir_numero%2==0){
		cout<<"El numero: "<<*dir_numero<<" es par"<<endl; // muestra el Valor contenido en el Memoria a la que apunta el Puntero
		cout<<"Posicion: "<<dir_numero<<endl; // muestra la direccion de Memeoria a la que apunta el Puntero
	}
	else{
		cout<<"El numero: "<<*dir_numero<<" es impar"<<endl;
		cout<<"Posicion: "<<dir_numero<<endl;
	}

	getch();
	return 0;
}
