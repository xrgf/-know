#include<iostream>
using namespace std;
void printf_sort(int* num, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << num[i] << "  ";
	}
}
void insert_sort(int* num, int len)
{
	int index = 0;
	for (int i = 1; i < len; i++)
	{
		int j = i;
		while (j > 0)
		{
			if (num[j] > num[j - 1])
			{
				int team = num[j];
				num[j] = num[j - 1];
				num[j - 1] = team;
				
			}
			j--;
		}
	}
	printf_sort(num, len);
}
void bubble_sort(int* num, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len-i-1; ++j)
		{
			if (num[j] >num[j + 1])
			{
				int team = num[j];
				num[j] = num[j + 1];
				num[j + 1] = team;
			}
		}
	}
	printf_sort(num, len);
}
void select_sort(int* num, int len)
{
	int index;
	for (int i = 0; i < len; ++i)
	{
		index = i;
		for (int j = i; j < len; ++j)
		{
			if (num[j] < num[index])
			{
				index = j;
			}
		}
		int team = num[i];
		num[i] = num[index];
		num[index] = team;
	}
	printf_sort(num, len);
}
int main()
{


	int num[10] = { 0,2,1,3,6,8,15,2,4,7 };
//	insert_sort(num, 10);
	/*bubble_sort(num, 10);*/
	select_sort(num, 10);

	return 0;
}