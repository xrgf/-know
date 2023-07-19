#include<iostream>
using namespace std;
int BFalgorithm(const char* str,const char*strc)
{
	int len = strlen(str);
	int count = 0;
	int len2 = strlen(strc);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str[i+j] == strc[j])
			{
				count++;
			}
		}
		if (count == len2)
		{
			return i;
		}
		count = 0;
	}
	return -1;

 }

int main()
{
	int n = BFalgorithm("asdbcc", "sdb");
	cout << n << endl;
	return 0;
}