#include<iostream>
#include<string>
#include<vector>
#include<array>
using namespace std;
void testvectornestarray()
{
	
	vector<array<int, 3>> vector2D;
	for (int i = 0; i < 3; i++)
	{
		array<int, 3> temp = { 1,2,3 };
		//vector2D[i] = temp;
		vector2D.push_back(temp);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << vector2D[i][j] << "  ";
		}
		cout << endl;
	}

}
ostream& operator<<(ostream out, array<int, 3>array)
{
	for (int i = 0; i < 3; ++i)
	{
		out << array[i] << "  ";
	}
	return out;
}
void arraynest()
{
	
	array<array<int, 3>, 2>Array;
	for (int i = 0; i < 2; ++i)
	{
		array<int, 3>temp = { 1,2,3 };
		Array[i] = temp;
	}
	
	for (array<array<int, 3>, 2>::iterator iter = Array.begin(); iter != Array.end(); iter++)
	{
		
			array<int, 3>::iterator it = (*iter).begin();
			for (it; it != (*iter).end(); ++it)
			{
				cout << *it << "  ";
			}
			
		
		cout << endl;
	}
}
void vectornest()
{
	vector < vector<string>> vector2D;
	for (int i = 0; i < 3; ++i)
	{
		vector<string>temp;
		for (int j = 0; j <=+i; ++j)
		{
			string str = "kkk";
			temp.push_back(str + to_string(i));
		}
		vector2D.push_back(temp);
	}
	for (int i = 0; i<vector2D.size() ; i++)
	{
		for (int j = 0; j < vector2D[i].size(); j++)
		{
			cout << vector2D[i][j] << "  ";
		}
		cout << endl;
	}
}
int main()
{
  /* testvectornestarray();*/
	arraynest();
	//vectornest();
	
	return 0;
}