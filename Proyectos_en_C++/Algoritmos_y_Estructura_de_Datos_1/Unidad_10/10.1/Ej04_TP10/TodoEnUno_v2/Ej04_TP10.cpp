#include <iostream>

using namespace std;

class Fecha
{
public:
	Fecha();
	// Constructor


	void SetDia(int d);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el dia con el parametro entrante


	int GetDia();
	// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el campo dia correspondiente a una fecha


	void SetMes(int m);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el mes con el parametro entrante


	int GetMes();
	// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el campo mes correspondiente a una fecha


	void SetAnno(int a);
	// Precondicion: Dato numerico entero
	// Poscondicion: Se establece el anno con el parametro entrante


	int GetAnno();
	// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene el campo anno correspondiente a una fecha


	Fecha tiempoTranscurrido(Fecha fechaPost);
	// Precondicion: Se le debe pasar un objeto de tipo fecha.
	// Poscondicion: Se obtiene la diferencia entre fechaPost y la fecha del objeto actual
	// si la fechaPost es posterior a la fecha del objeto actual y -1/-1/-1 en caso contrario


	~Fecha();
	// Destructor

private:
	int dia;
	int mes;
	int anno;
};


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


	void SetFechaNac(Fecha f);
	// Precondicion: Dato de tipo Fecha
	// Poscondicion: Se establece la fecha de nacimiento con el parametro entrante


	Fecha GetFechaNac();
	// Precondicion: La funcion SetFechaNac tiene que haber sido invocada al menos una vez.
	// Poscondicion: Se obtiene la fecha de nacimiento de una persona


	~Persona();
	// Destructor

private:
	string nombre;
	Fecha fechaNac;
};



Fecha::Fecha()
// Constructor
{}

void Fecha::SetDia(int d)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el dia con el parametro entrante
{
	dia = d;
}


int Fecha::GetDia()
// Precondicion: La funcion SetDia tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el campo dia correspondiente a una fecha
{
	return dia;
}

void Fecha::SetMes(int m)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el mes con el parametro entrante
{
	mes = m;
}


int Fecha::GetMes()
// Precondicion: La funcion SetMes tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el campo mes correspondiente a una fecha
{
	return mes;
}


void Fecha::SetAnno(int a)
// Precondicion: Dato numerico entero
// Poscondicion: Se establece el anno con el parametro entrante
{
	anno = a;
}


int Fecha::GetAnno()
// Precondicion: La funcion SetAnno tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene el campo anno correspondiente a una fecha
{
	return anno;
}


Fecha Fecha::tiempoTranscurrido(Fecha fechaPost)
// Precondicion: Se le debe pasar un objeto de tipo fecha.
// Poscondicion: Se obtiene la diferencia entre fechaPost y la fecha del objeto actual
// si la fechaPost es posterior a la fecha del objeto actual y -1/-1/-1 en caso contrario
{
	Fecha dif;

	if (fechaPost.anno > this->anno)
	{
		if (fechaPost.mes > this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
				cout << "Casos A y B" << endl;
			}
			else
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes - 1;
				dif.dia  = fechaPost.dia  + 30 - this->dia;
				cout << "Caso C" << endl;
			}
		}
		else if (fechaPost.mes == this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
				cout << "Casos D y E" << endl;
			}
			else
			{
				dif.anno = fechaPost.anno - 1 - this->anno;
				dif.mes  = fechaPost.mes + 11 - this->mes;
				dif.dia  = fechaPost.dia + 30 - this->dia;
				cout << "Caso F" << endl;
			}
		}
		else if (fechaPost.mes < this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - 1 - this->anno;
				dif.mes  = fechaPost.mes + 12  - this->mes;
				dif.dia  = fechaPost.dia - this->dia;
				cout << "Casos G y H" << endl;
			}
			else
			{
				dif.anno = fechaPost.anno - 1 - this->anno;
				dif.mes  = fechaPost.mes + 11 - this->mes;
				dif.dia  = fechaPost.dia + 30 - this->dia;
				cout << "Caso I" << endl;
			}
		}
	}
	else if (fechaPost.anno == this->anno)
	{
		if (fechaPost.mes > this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
				cout << "Casos J y K" << endl;
			}
			else
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes - 1 - this->mes;
				dif.dia  = fechaPost.dia  + 30 - this->dia;
				cout << "Caso L" << endl;
			}
		}
		else if (fechaPost.mes == this->mes)
		{
			if (fechaPost.dia >= this->dia)
			{
				dif.anno = fechaPost.anno - this->anno;
				dif.mes  = fechaPost.mes  - this->mes;
				dif.dia  = fechaPost.dia  - this->dia;
				cout << "Casos M y N" << endl;
			}
			else
			{
				dif.anno = -1;
				dif.mes  = -1;
				dif.dia  = -1;
				cout << "Caso O" << endl;
			}
		}
		else if (fechaPost.mes < this->mes)
		{
			dif.anno = -1;
			dif.mes  = -1;
			dif.dia  = -1;
			cout << "Caso P" << endl;
		}
	}
	else
	{
		dif.anno = -1;
		dif.mes = -1;
		dif.dia = -1;
		cout << "Caso Q" << endl;
	}
	return dif;
}


Fecha::~Fecha()
// Destructor
{}



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


void Persona::SetFechaNac(Fecha f)
// Precondicion: Dato de tipo Fecha
// Poscondicion: Se establece la fecha de nacimiento con el parametro entrante
{
	fechaNac = f;
}


Fecha Persona::GetFechaNac()
// Precondicion: La funcion SetFechaNac tiene que haber sido invocada al menos una vez.
// Poscondicion: Se obtiene la fecha de nacimiento de una persona
{
	return fechaNac;
}


Persona::~Persona()
// Destructor
{}





int main()
{
	Persona persona;
	Fecha fechaAct, fechaAux, diferencia;
	string auxNom;
	int auxInt;

	cout << "Ingrese el nombre de la persona: ";
	getline(cin, auxNom);
	persona.SetNombre(auxNom);

	cout << "Solicitaremos ahora la fecha de nacimiento:" << endl;

	cout << "Ingrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	fechaAux.SetDia(auxInt);

	cout << "Ingrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	fechaAux.SetMes(auxInt);
	
	cout << "Ingrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	fechaAux.SetAnno(auxInt);

	persona.SetFechaNac(fechaAux);

	cout << "\nIngrese ahora la fecha actual:" << endl;

	cout << "\nIngrese dia (1-31): ",
	cin >> auxInt;
	cin.ignore();
	fechaAct.SetDia(auxInt);

	cout << "\nIngrese mes (1-12): ",
	cin >> auxInt;
	cin.ignore();
	fechaAct.SetMes(auxInt);
	
	cout << "\nIngrese anno (AAAA): ",
	cin >> auxInt;
	cin.ignore();
	fechaAct.SetAnno(auxInt);

//	diferencia = fechaAux.tiempoTranscurrido(fechaAct);
	diferencia = (persona.GetFechaNac()).tiempoTranscurrido(fechaAct);


	if (diferencia.GetAnno() != -1)
	{
		cout << "\nLa fecha de nacimiento de " << persona.GetNombre() << " es: " 
		<< persona.GetFechaNac().GetDia() << '-' << persona.GetFechaNac().GetMes() << '-' << persona.GetFechaNac().GetAnno() << endl;

		cout << "\nLa fecha actual es: " << fechaAct.GetDia() << '-' << fechaAct.GetMes() << '-' << fechaAct.GetAnno() << endl;


		cout << "\nLa persona tiene " << diferencia.GetAnno() << " anios, " << diferencia.GetMes() << " meses y " << diferencia.GetDia() << " dias.\n" << endl;;

	}
	else
	{
		cout << "La fecha actual es menor a la de nacimiento. Revise los datos." << endl;
	}
	
	return 0;
}