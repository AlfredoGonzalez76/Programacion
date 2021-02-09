#include <iostream>
using namespace std;

int main()
{
	int seg, min, horas;

	cout << "Convertidor de segundos en hs. min. y seg." << endl;

	cout << "Ingrese la cantidad total de segundos: ";

	cin >> seg;

	horas = seg / 3600;

	seg = seg % 3600;

	min = seg / 60;

	seg = seg % 60;

	cout << "Eso da " << horas << " horas, " << min << " minutos y " << seg << "segundos.";

	return 0;
}