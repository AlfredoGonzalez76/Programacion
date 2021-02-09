#include <iostream>
using namespace std;

/* Escriba una función nombrada tiempo() que tenga un parámetro en
número entero llamado totalSeg y tres parámetros enteros nombrados
horas, min y seg. La función es convertir el número de segundos
transmitido en un número equivalente de horas, minutos y segundos. */

void tiempo(int totalSeg, int &horas, int &min, int &seg);

int main()
{
	int ts, h = 0, m = 0, s = 0;

	cout << "Ingrese una cantidad de tiempo en segundos: ";
	cin >> ts;

	tiempo(ts,  h, m, s);

	cout << "Eso suma un total de " << h << " hs. " << m << " min. " << s << " seg. " << endl;

	return 0;
}

void ntiempo(int totalSeg, int &horas, int &min, int &seg)
{
	seg = totalSeg % 60;
	totalSeg = totalSeg / 60;
	min = totalSeg % 60;
	horas = totalSeg / 60;
}