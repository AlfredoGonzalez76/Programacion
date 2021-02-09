#include <string>
#include <iostream>

using namespace std;

class Persona
{
public:
	Persona();
	// Constructor


	void SetNombre(string nom);
	// Precondicion: Dato de tipo string
	// Poscondicion: Se establece el nombre con el parametro entrante


	string GetNombre();
	// Precondicion: La funcion SetNombre tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el nombre de una persona


	void SetDiaNac(int d);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el dia con el parametro entrante


	int GetDiaNac();
	// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el dia de nacimiento de una persona


	void SetMesNac(int m);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el mes de nacimiento con el parametro entrante


	int GetMesNac();
	// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el mes de nacimiento de una persona


	void SetAnnoNac(int a);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el anno de nacimiento con el parametro entrante


	int GetAnnoNac();
	// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el mes de nacimiento de una persona


	void SetDiaAct(int da);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el dia actual con el parametro entrante


	int GetDiaAct();
	// Precondicion: La funcion SetDiaAct tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el dia actual


	void SetMesAct(int ma);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el mes actual con el parametro entrante


	int GetMesAct();
	// Precondicion: La funcion SetMesAct tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el mes actual


	void SetAnnoAct(int aa);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el anno actual con el parametro entrante


	int GetAnnoAct();
	// Precondicion: La funcion SetAnnoAct tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el anno actual


	int obtenerEdad();
	// Precondicion: La funcion SetDia, SetMes, SetAnno, SetDiaAct, SetMesAct, SetAnnoAct
	//               tienen que haber sido invocadas al menos una vez.
	// Poscondicion: Se obtiene la edad de la persona


	~Persona();
	// Destructor

private:
	string nombre;
	int dianac;
	int mesnac;
	int annonac;
	int diaact;
	int mesact;
	int annoact;
};


Persona::Persona()
// Constructor
{}


void Persona::SetNombre(string nom)
// Precondicion: Dato de tipo string
// Poscondicion: Se establece el nombre con el parametro entrante
{
	nombre = nom;
}


string Persona::GetNombre()
// Precondicion: La funcion SetNombre tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el nombre de una persona
{
	return nombre;
}


void Persona::SetDiaNac(int d)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el dia con el parametro entrante
{
	dianac = d;
}


int Persona::GetDiaNac()
// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el dia de nacimiento de una persona
{
	return dianac;
}


void Persona::SetMesNac(int m)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el mes de nacimiento con el parametro entrante
{
	mesnac = m;
}


int Persona::GetMesNac()
// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el mes de nacimiento de una persona
{
	return mesnac;
}


void Persona::SetAnnoNac(int a)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el anno de nacimiento con el parametro entrante
{
	annonac = a;
}

int Persona::GetAnnoNac()
// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el mes de nacimiento de una persona
{
	return annonac;
}

void Persona::SetDiaAct(int da)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el dia actual con el parametro entrante
{
	diaact = da;
}

int Persona::GetDiaAct()
// Precondicion: La funcion SetDiaAct tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el dia actual
{
	return diaact;
}


void Persona::SetMesAct(int ma)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el mes actual con el parametro entrante
{
	mesact = ma;
}


int Persona::GetMesAct()
// Precondicion: La funcion SetMesAct tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el mes actual
{
	return mesact;
}

void Persona::SetAnnoAct(int aa)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el anno actual con el parametro entrante
{
	annoact = aa;
}


int Persona::GetAnnoAct()
// Precondicion: La funcion SetAnnoAct tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el anno actual
{
	return annoact;
}

int Persona::obtenerEdad()
// Precondicion: La funcion SetDia, SetMes, SetAnno, SetDiaAct, SetMesAct, SetAnnoAct
//               tienen que haber sido invocadas al menos una vez.
// Poscondicion: Se obtiene la edad de la persona
{
	if (annoact >= annonac)
	{
		return annoact - annonac;
	}
}

Persona::~Persona()
// Destructor
{}




int main()
{
	Persona persona;
	int auxInt;
	string auxNom;

	cout << "Ingrese el nombre de la persona: ";
	getline(cin, auxNom);
	persona.SetNombre(auxNom);

	cout << "Solicitaremos ahora la fecha de nacimiento:" << endl;

	cout << "Ingrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetDiaNac(auxInt);

	cout << "Ingrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetMesNac(auxInt);
	
	cout << "Ingrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetAnnoNac(auxInt);

	cout << "\nIngrese ahora la fecha actual:" << endl;

	cout << "\nIngrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetDiaAct(auxInt);

	cout << "\nIngrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetMesAct(auxInt);
	
	cout << "\nIngrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	persona.SetAnnoAct(auxInt);


	if (persona.obtenerEdad() != -1)
	{
		cout << "\nLa fecha de nacimiento de " << persona.GetNombre() << " es: " 
		<< persona.GetDiaNac() << '-' << persona.GetMesNac() << '-' << persona.GetAnnoNac() << endl;

		cout << "\nLa fecha actual es: " << persona.GetDiaAct() << '-' << persona.GetMesAct() << '-' << persona.GetAnnoAct() << endl;

		cout << "\ny tiene " << persona.obtenerEdad() << " annos.\n" << endl;
	}
	else
	{
		cout << "El anno actual es menor al anno de nacimiento. Revise los datos." << endl;
	}


	return 0;
} 