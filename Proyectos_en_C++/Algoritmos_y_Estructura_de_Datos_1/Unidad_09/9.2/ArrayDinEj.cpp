#include <iostream>

using namespace std;

const int N = 100;

int main()
{
	int* p = new int[N];
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < N; i++) {
		cout << p[i] << endl;
	}

	cout << "La cantidad de elementos del arreglo dinamico es: " << sizeof(p) << endl;

	delete [] p;
	return 0;
}