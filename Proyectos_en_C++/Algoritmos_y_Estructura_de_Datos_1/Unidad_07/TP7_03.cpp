#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
using namespace std;

//--------------  Tipos de datos Introducidos  -----------------

const int cantCarreras = 6;
const int cantAnios = 3;

const int Dimension = 100;

typedef struct {
   string apellidos;
   string nombres;
   int edad;
   int dni;
   int nota;
} tRegistro;


typedef tRegistro tArray[Dimension];

typedef struct {
   tArray elementos;
   int contador = 0;
} tLista;


typedef tLista tLibro[cantCarreras][cantAnios];




// -------------------------   MENUS   ------------------------------

// Menu para operaciones Globales sobre las listas de todos los cursos.
int menuPrincipal();


// Menu con las operaciones a realizar en una carrera determinada.
int menuPorCarrera(int carrera, int anio);


// Funcion que coloca el encabezado correspondiente a la carrera y anio seleccionados.
void mostrarCabeceraCarrera(int carrera, int anio);


// Menu para elegir la carrera sobre la cual se va a trabajar.
int eligeCarrera();


// Menu para elegir el anio sobre el que se va a trabajar.
int eligeAnio();


// Menu que permite seleccionar el tipo de ordenamiento que se aplicará sobre una lista o todo el libro.
int menuOrdenacion();



// ------------------   Funciones Extra   --------------------

// Funcion que permite pasar a mayuscula toda una cadena de caracteres.
string mayuscula(string cadena);


// Funcion booleana: devuelve true si 'fragmento' se encuentra en 'palabra'.
bool In(string fragmento, string palabra);


// Intercambia los valores de dos enteros.          FUNCION SOBRECARGADA
void intercambio(int& a, int& b);



//------------------  Funciones sobre Registros   ------------------------

// Funcion que muestra solo un registro con la informacion de todos sus campos.
void muestraRegistroCompleto(tRegistro& registro);


// Funcion que carga datos a un registro.
tRegistro cargaRegistro();


// Funcion que permite modificar campos de un registro.
void modificaRegistro(tRegistro& registro);


// Intercambia dos registros.                       FUNCION SOBRECARGADA
void intercambio(tRegistro& a, tRegistro& b);



//------------------  Funciones sobre Listas   ------------------------

// Funcion que muestra una lista correspondiente a una carrera y un anio.
void mostrarLista(tLista& listita);


// Funcion que muestra lista de un curso con la informacion completa de cada registro.
void mostrarListaConNotas(tLista& listita);


// Funcion que permite agregar un registro a una lista.
void agregaRegistro(tLista& listita);


// Funcion que permite eliminar un registro de una lista.
void eliminaRegistro(tLista& listita, int posicion);


// Esta funcion busca 'fragmento' entre todos los Nombres y Apellidos de la lista
void buscaNomApeEnLista(tLista& listita, string fragmento);


// Función que ordena una lista de acuerdo al tipo de ordenamiento seleccionado en el menuOrdenacion.
void ordenaListaPorIntercambio(tLista& listita, int op);


// Esta funcion ejecuta el tipo de accion sobre una lista que haya sido seleccionada en menuPorCarrera
void ejecutarEnLista(int opcion, tLista& listita);



// ---------------   Funciones Estadisticas sobre Listas   -----------------


// Muestra la estadistica de Notas de una lista (grupo de alumnos).
void estadistica(tLista& listita);


// Calcula la media de las Notas de una lista.
double media(tLista& listita);


// Calcula la varianza de las Notas de una lista. 
double varianza(tLista& listita);


// Calcula el desvio de las Notas de una Lista.
double desvio(tLista& listita);


// Devuelve la Nota Maxima de una Lista.
int maxima(tLista& listita);


// Devuelve la Nota Minima de una Lista.
int minima(tLista& listita);


// Devuelve la moda entre las Notas de una Lista.
int moda(tLista& listita);


// Quiero copiar solo las notas en un array. Como las funciones no devuelven un array,use este recurso. Esta func. devuelve un puntero 
int* copiaNotas(tLista& listita);   //  https://www.youtube.com/watch?v=rxAUwddWfQk


// Calcula la mediana de las Notas de la Lista por el metodo Burbuja
double medianaPorBurbuja(tLista& listita);



//------------------  Funciones sobre Libro   ------------------------

// Funcion que muestra la base de datos completa: Las listas correspondientes a cada curso diferente.
void mostrarLibro(tLibro& librito);


// Esta funcion busca 'fragmento' entre los Nombres y Apellidos de todas las listas del libro (base de datos)
void buscaNomApeEnLibro(tLibro& librito, string fragmento);


// Función que ordena todo el libro de acuerdo al tipo de ordenamiento seleccionado en el menuOrdenacion.
void ordenaLibroPorIntercambio(tLibro& librito, int op);


// Esta funcion ejecuta el tipo de accion sobre el libro que haya sido seleccionada en el menuPrincipal
void ejecutarEnLibro(char opcion, tLibro& librito);


//--------------------- ESTADISTICA TOTAL  -------------------

// Muestra la estadistica de todas Notas de las diferentes listas del libro.
void estadisticaTotal(tLibro& librito);


// ----------------   Manejo de Archivos   ---------------

// En caso de utilizar archivos de texto la informacion se guarda y lee de la sig. manera:
// El primer renglón consta de un entero correspondiente al numero de carrera.
// El segundo renglón consta de un entero que corresponde al anio que cursa.
// Luego, un campo por cada línea y cada registro de la lista debajo del anterior.


// Funcion para leer la base de datos completa.
void leerLibroDeArchivo(string nombreArch, tLibro& librito);


// Funcion que cueta el total de alumnos en todo el libro.
int cuentaAlumnos(tLibro& librito);


// Funcion que permite persistir la informacion de todo el libro en el archivo de nombre nombreArch
void escribeLibroEnArchivo(string nombreArch, tLibro& librito);









//------------------------  Principal  ---------------------------

int main()
{
	string nombreArchivo = "Alumnos.txt";
//	tLista lista;
	tLibro libro;
	char opcion;

// Aquí va a tener que preguntar si el archivo nombreArchivo existe. Caso contrario lo creará y lo cerrará.

	leerLibroDeArchivo(nombreArchivo, libro);

	do
	{
		opcion = menuPrincipal();
		ejecutarEnLibro(opcion, libro);
	}while(opcion != 'f');

	escribeLibroEnArchivo(nombreArchivo, libro);


	return 0;
}




//----------------- Definicion de Funciones Propias ----------------------



int menuPrincipal()
{
	char op;

	cout << "--------------------------------------------" << endl;
	cout << '|' << "               MENU PRINCIPAL             " << '|' << endl;
	cout << "--------------------------------------------" << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (a) Mostrar Listado TOTAL de Alumnos     " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (b) Buscar un Alumno en el Listado TOTAL " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (c) Ver Estadisticas de TODOS los cursos " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (d) Ordenar Listas de TODOS los cursos   " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (e) Trabajar por carrera y por anio      " << '|' << endl;
	cout << '|' << setw(40) <<setiosflags(ios::left) << " (f) Grabar Datos y Salir                 " << '|' << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 'a') && (op > 'f') );
	cout << endl;

	return op;
}


int menuPorCarrera(int carrera, int anio)
{
	int op;
	mostrarCabeceraCarrera(carrera, anio);
	cout << "---------------------------------------------------------------------" << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 1. Mostrar Listado de Alumnos " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 2. Ingresar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 3. Buscar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 4. Modificar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 5. Eliminar un Registro " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 6. Ordenar Registros " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 7. Listado con Datos completos " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 8. Ver Estadisticas " << '|' << endl;
	cout << '|' << setw(67) <<setiosflags(ios::left) << " 9. Volver al Menu Principal " << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 1) && (op > 9) );

	cout << endl;
	return op;
}


void mostrarCabeceraCarrera(int carrera, int anio)
{
    cout << "---------------------------------------------------------------------" << endl ;
	switch(carrera)
	{
	  case 0:
	     cout << '|' << "       Tecnicatura Superior en Analisis de Sistemas       | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 1:
	     cout << '|' << "            Tecnicatura Superior en Logistica             | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 2:
	     cout << '|' << " Tecnicatura Superior en Industria Textil e Indumentaria  | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 3:
	     cout << '|' << "             Tecnicatura Superior en Turismo              | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 4:
	     cout << '|' << "        Tecnicatura Superior en Gestion Ambiental         | Anio " << (anio + 1) << " |" << endl ;
	    break;
	  case 5:
	     cout << '|' << "       Tecnicatura Superior en Emergencias Medicas        | Anio " << (anio + 1) << " |" << endl ;
	    break;
	}
    cout << "---------------------------------------------------------------------" << endl ;

}


int eligeCarrera()
{
	int op;

	cout << "---------------------------------------------------------" << endl ;
	cout << "|  1  |  Tecnicatura Superior en Analisis de Sistemas   |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  2  |  Tecnicatura Superior en Logistica              |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  3  |  Tecnicatura Superior en Industria Textil       |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  4  |  Tecnicatura Superior en Turismo                |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  5  |  Tecnicatura Superior en Gestion Ambiental      |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << "|  6  |  Tecnicatura Superior en Emergencias Medicas    |" << endl ;
	cout << "---------------------------------------------------------" << endl ;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 1) && (op > 6) );
	cout << endl;

	return op;
}


int eligeAnio()
{
	int op;

	cout << "------------------------------" << endl ;
	cout << "|  1  |  Primer Anio         |" << endl ;
	cout << "------------------------------" << endl ;
	cout << "|  2  |  Segundo Anio        |" << endl ;
	cout << "------------------------------" << endl ;
	cout << "|  3  |  Tercer Anio         |" << endl ;
	cout << "------------------------------" << endl ;
	cout << endl;
	cout << "Elija una opcion: ";
	do
	{
		cin >> op;
		cin.ignore(); // Esto evita que quede el \n del Enter en el bufer y el programa se sale el getline del nombre
	}
	while ((op < 1) && (op > 3) );
	cout << endl;

	return op;
}


int menuOrdenacion()
{
	int op;
	cout << "---------------------------------------------------------------------" << endl ;
	cout << setw(68) << setiosflags(ios::left) << "| 1. Orden Ascendente por Apellidos" << '|' << endl;
	cout << setw(68) << setiosflags(ios::left) << "| 2. Orden Descendente por Apellidos" << '|' << endl;
	cout << setw(68) << setiosflags(ios::left) << "| 3. Orden Ascendente por Nombres" << '|' << endl;
	cout << setw(68) << setiosflags(ios::left) << "| 4. Orden Descendente por Nombres" << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl ;
	cout << setiosflags(ios::left) << endl;
	cout << " Digite aqui su opcion: ";
	cin >> op;
	cin.ignore();
	cout << endl;

	return op;
}


// ---------------------   Funciones Extra   --------------------------

string mayuscula(string cadena)
{
	for (int i = 0; i < cadena.length(); ++i)
	{
		cadena[i] = toupper(cadena[i]);
	}
	return cadena;
}


bool In(string fragmento, string palabra)
{
	bool esta = false;
	int i = 0, j = 0, aciertos = 0;

	while((i < fragmento.length()) && (j < palabra.length()) && (aciertos < fragmento.length()))
	{
		if(fragmento[i] == palabra[j])
		{
			i++;
			j++;
			aciertos++;
		}
		else
		{
			i = 0;
			aciertos = 0;
			j++;
		}
	}
	esta = (aciertos == fragmento.length());

	return esta;
}


void intercambio(int& a, int& b)
{
	int aux;

	aux = a;
	a = b;
	b = aux;
}


//------------------  Funciones sobre Registros   ------------------------


void muestraRegistroCompleto(tRegistro& registro)
{
	cout << "---------------------------------------------------------------------" << endl ;
	cout << "| Apellidos: " << setw(55) << setiosflags(ios::right) << registro.apellidos << '|' << endl;
	cout << "| Nombres:   " << setw(55) << setiosflags(ios::right) << registro.nombres << '|' << endl;
	cout << "| Edad:      " << setw(55) << setiosflags(ios::right) << registro.edad << '|' << endl;
	cout << "| DNI:       " << setw(55) << setiosflags(ios::right) << registro.dni << '|' << endl;
	cout << "| Nota:      " << setw(55) << setiosflags(ios::right) << registro.nota << '|' << endl;
	cout << setiosflags(ios::left) << "---------------------------------------------------------------------" << endl ;
}

tRegistro cargaRegistro()
{
	string auxString;
	tRegistro registro;

	cout << "Ingrese Apellidos del alumno: ";
	getline(cin, registro.apellidos);

	cout << "Ingrese Nombres del alumno: ";
	getline(cin, registro.nombres);

	cout << "Ingrese la Edad del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro.edad = atoi(auxString.c_str());

	cout << "Ingrese DNI del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro.dni = atoi(auxString.c_str());

	cout << "Ingrese la NOTA del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro.nota = atoi(auxString.c_str());

	return registro;
}


void modificaRegistro(tRegistro& registro)
{
	int opcion;
	string auxString;

	do
	{
		muestraRegistroCompleto(registro);

		cout << " Presione: " << endl;
		cout << " 1) Para modificar Apellidos" << endl;
		cout << " 2) Para modificar Nombres " << endl;
		cout << " 3) Para modificar edad" << endl;
		cout << " 4) Para modificar DNI" << endl;
		cout << " 5) Para modificar nota" << endl;
		cout << " 6) Para terminar modificacion" << endl;
		cout << endl;
		cout << " Digite aqui su opcion: ";
		cin >> opcion;
		cin.ignore();
		cout << endl;

		switch(opcion)
		{
		  case 1:
		     cout << "Apellidos: ";
		     getline(cin, registro.apellidos);
		     cout << endl;
		    break;
		  case 2:
		     cout << "Nombres: ";
		     getline(cin, registro.nombres);
		     cout << endl;
		    break;
		  case 3:
		  	cout << "Edad: ";
			cin >> auxString;
			cin.ignore();
			registro.edad = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 4:
		  	cout << "DNI: ";
			cin >> auxString;
			cin.ignore();
			registro.dni = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 5:
		  	cout << "Nota: ";
			cin >> auxString;
			cin.ignore();
			registro.nota = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 6:
		  	cout << "Ha terminado de modificar el Registro" << endl;;
		    break;
		  default:
		  	cout << "Opcion incorrecta" << endl;
		  	cout << endl;
		}
	}
	while(opcion != 6);
}


void intercambio(tRegistro& a, tRegistro& b)
{
	tRegistro aux;

	aux = a;
	a = b;
	b = aux;
}


//------------------  Funciones sobre Listas   ------------------------


void mostrarLista(tLista& listita)
{
	cout << "---------------------------------------------------------------------" << endl ;
	cout << '|' << setw(55) << setiosflags(ios::left) << " Apellidos y Nombres  " << " |" << 
	setw(10) << setiosflags(ios::left) << " Registro" << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl ;

	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "| " << setw(55) <<setiosflags(ios::left) << listita.elementos[i].apellidos + ", " + listita.elementos[i].nombres << "|     " <<
		setw(5) << setiosflags(ios::left) << i << '|' << endl;
	}

	cout << "---------------------------------------------------------------------" << endl ;
	cout << endl;
}


void mostrarListaConNotas(tLista& listita)
{
	cout << "\n La lista acutal es:" << endl;
	cout << "------------------------------" << endl ;
	for (int i = 0; i < listita.contador; ++i)
	{
		muestraRegistroCompleto(listita.elementos[i]);
		cout << "| Registro:  " << setw(55) << setiosflags(ios::right) << i << '|' << endl;
		cout << setiosflags(ios::left) << "---------------------------------------------------------------------" << endl ;

	}
	cout << endl;
}


void agregaRegistro(tLista& listita)
{

	listita.elementos[listita.contador] = cargaRegistro();

	listita.contador++;
}


void eliminaRegistro(tLista& listita, int posicion)
{
	if (posicion < listita.contador)
	{
		for (int i = posicion; i < listita.contador; ++i)
		{
			listita.elementos[i] = listita.elementos[i+1];
		}
		listita.contador--;
	}
	else
	{
		cout << "El Registro ingresado no existe." << endl;
	}
}


void buscaNomApeEnLista(tLista& listita, string fragmento)
{

	for (int i = 0; i < listita.contador; ++i)
	{
		if(In(mayuscula(fragmento),mayuscula(listita.elementos[i].nombres)) || In(mayuscula(fragmento),mayuscula(listita.elementos[i].apellidos)))
		{
			muestraRegistroCompleto(listita.elementos[i]);
			cout << "| Registro:  " << setw(55) << setiosflags(ios::right) << i << '|' << endl;
			cout << setiosflags(ios::left) << "---------------------------------------------------------------------" << endl ;
		}

	}

}


void ordenaListaPorIntercambio(tLista& listita, int op)
{
	for (int i = 0; i < (listita.contador - 1); ++i)
	{
		for (int j = i+1; j < listita.contador; ++j)
		{
			switch(op)
			{
				case 1:
					if((listita.elementos[i].apellidos > listita.elementos[j].apellidos) || ((listita.elementos[i].apellidos == listita.elementos[j].apellidos) && (listita.elementos[i].nombres > listita.elementos[j].nombres)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
				case 2:
					if((listita.elementos[i].apellidos < listita.elementos[j].apellidos) || ((listita.elementos[i].apellidos == listita.elementos[j].apellidos) && (listita.elementos[i].nombres < listita.elementos[j].nombres)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
				case 3:
					if((listita.elementos[i].nombres > listita.elementos[j].nombres) || ((listita.elementos[i].nombres == listita.elementos[j].nombres) && (listita.elementos[i].apellidos > listita.elementos[j].apellidos)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
				case 4:
					if((listita.elementos[i].nombres < listita.elementos[j].nombres) || ((listita.elementos[i].nombres == listita.elementos[j].nombres) && (listita.elementos[i].apellidos < listita.elementos[j].apellidos)))
					{
						intercambio(listita.elementos[i],listita.elementos[j]);
					}
				break;
			}
		}
	}
}


void ejecutarEnLista(int opcion, tLista& listita)
{
  	int op, pos;
  	string fragmento;
	switch(opcion) {
	  case 1:
	     mostrarLista(listita);
	    break;
	  case 2:
	    agregaRegistro(listita);
	    break;
	  case 3:
	  	cout << "Ingrese al menos un fragmento del nombre o el apellido que busca: ";
	  	getline(cin, fragmento);
	  	cout << endl;
	  	buscaNomApeEnLista(listita, fragmento);
	    break;
	  case 4:
	    cout << "Ingrese el numero de Registro a Modificar: ";
	    cin >> pos;
	    cin.ignore();
	    cout << endl;
	    	if (pos < listita.contador)
			{
			    modificaRegistro(listita.elementos[pos]);
			}
			else
			{
				cout << "El Registro ingresado no existe." << endl;
			}

	    break;
	  case 5:
	    cout << "Ingrese el numero de Registro a Eliminar: ";
	    cin >> pos;
	    cin.ignore();
	    cout << endl;
	    eliminaRegistro(listita, pos);
	    break;
	  case 6:
	  	cout << endl;
	  	op = menuOrdenacion();
	  	ordenaListaPorIntercambio(listita,op);
	    break;
	  case 7:
	  	cout << endl;
	  	mostrarListaConNotas(listita);
	    break;
	  case 8:
	  	cout << endl;
	  	estadistica(listita);
	    break;
	}	
	cout << endl;
}


// ---------------   Funciones Estadisticas sobre Listas   -----------------


void estadistica(tLista& listita)
{
	cout << "---------------------------------------------------------------------" << endl ;
	cout << '|' << "                            ESTADISTICA                            " << '|' << endl;
	cout << "---------------------------------------------------------------------" << endl;

	if(listita.contador > 0)
	{
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Media:            " << '|' << setw(6) << fixed << setprecision(2) << media(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Varianza:         " << '|' << setw(6) << fixed << setprecision(2) << varianza(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Desvio Estandard: " << '|' << setw(6) << fixed << setprecision(2) << desvio(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Nota Maxima:      " << "| " << setw(5) << maxima(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Nota Minima:      " << "| " << setw(5) << minima(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Moda:             " << "| " << setw(5) << moda(listita) << '|' << endl;
		cout << '|' << setw(60) <<setiosflags(ios::left) << " Mediana:          " << "| " << setw(5) << medianaPorBurbuja(listita) << '|' << endl;
	}
	else
	{
		cout << '|' << "                             SIN DATOS                             " << '|' << endl;
	}

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
}


double media(tLista& listita)
{
	double acumula = 0;
	if(listita.contador > 0)
	{
		for (int i = 0; i < listita.contador; ++i)
		{
			acumula = acumula + listita.elementos[i].nota;
		}
	}
	else
	{
		cout << "No se han encontrado registros" << endl;
	}
	return (acumula/listita.contador);
}


double varianza(tLista& listita)
{
	double med = media(listita);
	double sigma2 = 0;

	for (int i = 0; i < listita.contador; ++i)
	{
		sigma2 = sigma2 + ((listita.elementos[i].nota - med)*(listita.elementos[i].nota - med));
	}
	return sigma2;
}


double desvio(tLista& listita)
{
	return sqrt(varianza(listita));
}


int maxima(tLista& listita)
{
	int max = 0;

	if(listita.contador > 0)
	{
		for (int i = 0; i < listita.contador; ++i)
		{
			if(listita.elementos[i].nota > max)
			{
				max = listita.elementos[i].nota;
			}
		}
	}
	else
	{
		cout << "No se han encontrado registros" << endl;
	}

	return max;
}


int minima(tLista& listita)
{
	int min = 10;

	if(listita.contador > 0)
	{
		for (int i = 0; i < listita.contador; ++i)
		{
			if(listita.elementos[i].nota < min)
			{
				min = listita.elementos[i].nota;
			}
		}
	}
	else
	{
		cout << "No se han encontrado registros" << endl;
	}

	return min;
}


int moda(tLista& listita)
{
	int notas[11] = {};
	int max = 0, cant = 0;
	for (int i = 0; i < listita.contador; ++i)
	{
		notas[listita.elementos[i].nota]++;
	}
	for (int j = 0; j < 11; ++j)
	{
		if(notas[j] > max)
		{
			cant = notas[j]; // Lo que encuentra es el maximo de las cantidades de cada nota
			max = j;
		}
	}
	return max;
}


int* copiaNotas(tLista& listita)
{
	static int notas[Dimension] = {};
	for (int i = 0; i < listita.contador; ++i)
	{
		notas[i] = listita.elementos[i].nota;
	}
	return notas;
}


double medianaPorBurbuja(tLista& listita)
{
	int aux;
	double median;
	bool ordenado = false;
	int* notas = copiaNotas(listita);

	for (int j = (listita.contador - 1); ((j > 0) && !ordenado); j--)
	{
		ordenado = true;
		for (int k = 0; k < j; ++k)
		{
			if(notas[k] > notas[k+1] )
			{
				intercambio(notas[k], notas[k+1]);
				ordenado = false;
			}
		}
	}
	if((listita.contador % 2) == 0 )
	{
		median = 0.5*(notas[listita.contador/2] + notas[(listita.contador/2)-1]);
	}
	else
	{
		median =notas[listita.contador/2];
	}

	return median;
}

//------------------  Funciones sobre Libro   ------------------------


void mostrarLibro(tLibro& librito)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			mostrarCabeceraCarrera(i,j);
			mostrarLista(librito[i][j]);
		}
	}
}


void buscaNomApeEnLibro(tLibro& librito, string fragmento)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			mostrarCabeceraCarrera(i,j);
			buscaNomApeEnLista(librito[i][j], fragmento);
		}
	}
}


void ordenaLibroPorIntercambio(tLibro& librito, int op)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			ordenaListaPorIntercambio(librito[i][j], op);
		}
	}
}


void ejecutarEnLibro(char opcion, tLibro& librito)
{
	string fragmento;
	int carrera, anio, op;
	do
	{
		switch(opcion)
		{
		  case 'a':
		  	system("cls");
		    mostrarLibro(librito);
		    break;
		  case 'b':
		  	cout << "Ingrese al menos un fragmento del nombre o el apellido que busca: ";
		  	getline(cin, fragmento);
		  	cout << endl;
		  	buscaNomApeEnLibro(librito, fragmento);
		    break;
		  case 'c':
		  	system("cls");
		  	estadisticaTotal(librito);
		    break;
		  case 'd':
			cout << endl;
			op = menuOrdenacion();
			ordenaLibroPorIntercambio(librito,op);
	    break;
		    break;
		  case 'e':
		  	system("cls");
		  	carrera = eligeCarrera(); carrera--;
		  	anio = eligeAnio(); anio--;
			do
			{
				op = menuPorCarrera(carrera,anio);
				ejecutarEnLista(op, librito[carrera][anio]);
			}while(op != 9);
		    break;
		}
	} while ((opcion < 'a') && (opcion > 'e'));  // si la opcion es 'f' (fuera de este rango), sale.
}


//--------------------- ESTADISTICA TOTAL  -------------------

void estadisticaTotal(tLibro& librito)
{
	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			mostrarCabeceraCarrera(i,j);
			estadistica(librito[i][j]);
		}
	}
}


// ----------------   Manejo de Archivos   ---------------

void leerLibroDeArchivo(string nombreArch, tLibro& librito)
{
	ifstream flujoIn;

	flujoIn.open(nombreArch);

	if (flujoIn.fail()) // comprueba una conexión fallida
	{
		cout << "\n El archivo no se abrió con éxito"
			 << "\n Por favor compruebe que el archivo realmente exista."
		<< endl;
		exit(1);
	}
	else
	{
		int carrera, anio, auxInt;
		string linea;

		while ( ! flujoIn.eof() )
		{		
			getline(flujoIn,linea);        // La primera linea contiene el caracter identificador de la carrera
			carrera = atoi(linea.c_str()); // Lo transformo a entero para poder operar con el

			getline(flujoIn,linea);        // La segunda linea contiene el caracter identificador del anio q cursa
			anio = atoi(linea.c_str());    // Lo transformo a entero para poder operar con el

			getline(flujoIn,linea);
			librito[carrera][anio].elementos[librito[carrera][anio].contador].apellidos = linea ;

			getline(flujoIn,linea);
			librito[carrera][anio].elementos[librito[carrera][anio].contador].nombres = linea ;
			
			getline(flujoIn,linea);
			auxInt = atoi(linea.c_str());
			librito[carrera][anio].elementos[librito[carrera][anio].contador].edad = auxInt ;

			getline(flujoIn,linea);
			auxInt = atoi(linea.c_str());
			librito[carrera][anio].elementos[librito[carrera][anio].contador].dni = auxInt ;

			getline(flujoIn,linea);
			auxInt = atoi(linea.c_str());
			librito[carrera][anio].elementos[librito[carrera][anio].contador].nota = auxInt ;

			librito[carrera][anio].contador++;
	}
		flujoIn.close();		
	}
}


int cuentaAlumnos(tLibro& librito)
{
	int total = 0;

	for (int i = 0; i < cantCarreras; ++i)
	{
		for (int j = 0; j < cantAnios; ++j)
		{
			total+= librito[i][j].contador;
		}
	}
	return total;
}


void escribeLibroEnArchivo(string nombreArch, tLibro& librito)
{
	int total = cuentaAlumnos(librito); // Uso este valor como control del fin del archivo.
	int acumula = 0;
	ofstream flujoOut;

	flujoOut.open(nombreArch);

	if (flujoOut.fail()) // comprueba una conexión fallida
	{
		cout << "\n El archivo no se abrió con éxito" << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < cantCarreras; ++i)
		{
			for (int j = 0; j < cantAnios; ++j)
			{
				for (int k = 0; k < librito[i][j].contador; ++k)
				{
					acumula ++; // Aqui voy registrando la cantidad de registros escritos hasta este momento
					flujoOut << i << endl;
					flujoOut << j << endl;
					flujoOut << librito[i][j].elementos[k].apellidos << endl;
					flujoOut << librito[i][j].elementos[k].nombres << endl;
					flujoOut << librito[i][j].elementos[k].edad << endl;
					flujoOut << librito[i][j].elementos[k].dni << endl;
					if (acumula < total)  // Me veo obligado a hacer esto para que no deje un renglon en blanco al final del archivo
					{
						flujoOut << librito[i][j].elementos[k].nota << endl;
					}
					else
					{
						flujoOut << librito[i][j].elementos[k].nota;
					}
				}
			}
		}

	}
	flujoOut.close();
}