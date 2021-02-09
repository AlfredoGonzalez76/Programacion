#include <iostream>
using namespace std;

int main()
{
	int diaNac, mesNac, anioNac, diaAct, mesAct, anioAct, anioEdad, mesEdad, diaEdad;

	cout << "Ingrese el anio de su nacimiento: ";
	cin >> anioNac;
	cout << "Ingrese el mes de su nacimiento: ";
	cin >> mesNac;
	cout << "Ingrese el dia de su nacimiento: ";
	cin >> diaNac;
	cout << "Ingrese el anio actual: ";
	cin >> anioAct;
	cout << "Ingrese el mes actual: ";
	cin >> mesAct;
	cout << "Ingrese el dia actual: ";
	cin >> diaAct;
	if (anioAct >= anioNac)
	{
		if (mesAct >= mesNac)
		{
			anioEdad = anioAct - anioNac;

			if (diaAct >= diaNac)
			{
				mesEdad = mesAct - mesAct;
				diaEdad = diaAct - diaNac;
				cout << "Usted tiene " << anioEdad << " anios, " << mesEdad << " meses y " << diaEdad << " dias.";
			}
			else
			{
				mesEdad = mesAct - mesNac - 1;
				diaEdad = diaAct + 30 - diaNac;
				cout << "Usted tiene aprox. " << anioEdad << " anios, " << mesEdad << " meses y " << diaEdad << " dias.";
			}
		}
		else
		{
			anioEdad = anioAct - 1 - anioNac;
			if (diaAct >= diaNac)
			{
				mesEdad = mesAct + 12 - mesNac;
				diaEdad = diaAct - diaNac;
				cout << "Usted tiene aprox." << anioEdad << " anios, " << mesEdad << " meses y " << diaEdad << " dias.";
			}
			else
			{
				mesEdad = mesAct + 12 - mesNac;
				diaEdad = diaAct + 30 - diaNac;
				cout << "Usted tiene aprox. " << anioEdad << " anios, " << mesEdad << " meses y " << diaEdad << " dias.";
			}

		}
	}
	return 0;
}