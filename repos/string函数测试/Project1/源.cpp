#include<iostream>
#include<array>
using namespace std;
int main()
{
	array<array<int, 3>, 2>array2D;
	for (int i = 0; i < 2; i++)
	{
		array<int, 3> temp = {i,i,i};
		array2D[i] = temp;

	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << array2D[i][j] << "  ";
		}
		cout << endl;
	}



	return 0;
}