#include <iostream>
using namespace std;

int main()
{
	const int rows = 4;
	const int cols = 6;
	int mat[rows][cols];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			mat[i][j] = i + j;
			cout << "mat[" << i << ','<< j << "] = " << mat[i][j] << ", ";
		}
	cout << endl;
	}

	return 0;
}