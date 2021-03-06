#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


typedef struct {
   string apellidos;
   string nombres;
   int edad;
   int dni;
   int nota;
} tRegistro;

typedef tRegistro* tRegPtr;

typedef struct {
	tRegPtr* elementos;
	int contador;
	int maximo;
} tListaDin;


// --------------- Prototipos de Funciones ------------------

tRegPtr nuevoRegistro();

void muestraRegistroCompleto(tRegPtr& registro);

void modificaRegistro(tRegPtr& registro);

void eliminaRegistro(tRegPtr& registro);



tListaDin crearListaDin();

void cargaListaDin(tListaDin& listita);

void muestraListaDin(tListaDin& listita);

void eliminaListaDin(tListaDin& listita);


// ----------------  PRINCIPAL  -----------------


int main()
{

	tListaDin lista;

	lista = crearListaDin();

	cout << endl;

	cargaListaDin(lista);

	muestraListaDin(lista);

	cout << endl;

//	ordenaListaPorIntercambio(lista);

	cout << endl;

	eliminaListaDin(lista);

	return 0;
}



/*
int main()
{

	tRegPtr puntReg;

	puntReg = nuevoRegistro();

	muestraRegistroCompleto(puntReg);

//	modificaRegistro(puntReg);

	eliminaRegistro(puntReg);

	return 0;
}
*/

tRegPtr nuevoRegistro()
{
	string auxString;
	tRegPtr registro = new tRegistro;

	cout << "Ingrese Apellidos del alumno: ";
	getline(cin, registro->apellidos);

	cout << "Ingrese Nombres del alumno: ";
	getline(cin, registro->nombres);

	cout << "Ingrese la Edad del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro->edad = atoi(auxString.c_str());

	cout << "Ingrese DNI del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro->dni = atoi(auxString.c_str());

	cout << "Ingrese la NOTA del alumno: ";
	cin >> auxString;
	cin.ignore();
	registro->nota = atoi(auxString.c_str());

	return registro;
}


void muestraRegistroCompleto(tRegPtr& registro)
{
	cout << "---------------------------------------------------------------------" << endl ;
	cout << "| Apellidos: " << setw(55) << setiosflags(ios::right) << registro->apellidos << '|' << endl;
	cout << "| Nombres:   " << setw(55) << setiosflags(ios::right) << registro->nombres << '|' << endl;
	cout << "| Edad:      " << setw(55) << setiosflags(ios::right) << registro->edad << '|' << endl;
	cout << "| DNI:       " << setw(55) << setiosflags(ios::right) << registro->dni << '|' << endl;
	cout << "| Nota:      " << setw(55) << setiosflags(ios::right) << registro->nota << '|' << endl;
	cout << setiosflags(ios::left) << "---------------------------------------------------------------------" << endl ;
}

void modificaRegistro(tRegPtr& registro)
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
		     getline(cin, registro->apellidos);
		     cout << endl;
		    break;
		  case 2:
		     cout << "Nombres: ";
		     getline(cin, registro->nombres);
		     cout << endl;
		    break;
		  case 3:
		  	cout << "Edad: ";
			cin >> auxString;
			cin.ignore();
			registro->edad = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 4:
		  	cout << "DNI: ";
			cin >> auxString;
			cin.ignore();
			registro->dni = atoi(auxString.c_str());
		    cout << endl;
		    break;
		  case 5:
		  	cout << "Nota: ";
			cin >> auxString;
			cin.ignore();
			registro->nota = atoi(auxString.c_str());
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


void eliminaRegistro(tRegPtr& registro)
{
	delete registro;
}






tListaDin crearListaDin() // Crea una lista de punteros a registros
{
	int N;
	tListaDin listita;

	cout << "Ingrese la cantidad MAXIMA de registros a almacenar: ";
	cin >> N;
	listita.maximo = N;
	cin.ignore();

	listita.elementos = new tRegPtr[N];
	listita.contador = 0;

	return listita;
}


void cargaListaDin(tListaDin& listita)
{
	char rta;
	do
	{
		cout << endl;
		cout << "Desea introducir datos en la lista? (S/N) ";
		cin >> rta;
		cin.ignore();
		if ((toupper(rta)=='S')&&(listita.contador < listita.maximo))
		{
			listita.elementos[listita.contador] = nuevoRegistro();
			listita.contador++;
		}
	}while((toupper(rta)!='N') && (listita.contador < listita.maximo));
}


void muestraListaDin(tListaDin& listita)
{
	for (int i = 0; i < listita.contador; ++i)
	{
		cout << "El elemento " << i+1 << " de la lista es " << endl;
		muestraRegistroCompleto(listita.elementos[i]);
	}
}


void eliminaListaDin(tListaDin& listita)
{
	for (int i = 0; i < listita.contador; ++i)
	{
		eliminaRegistro(listita.elementos[i]);
	}
	listita.contador = 0;

	delete [] listita.elementos;

}