#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[31];
	gets_s(str,30);
	int len = strlen(str);
	int count[31];
	for (int i = 0; i < len; i++)
	{
		count[i] = str[i] - 48;
	}

	for (int k = 2; k < 9; k++)
	{
		int num = 0;
		for (int i = 0; i <len; i++)
		{
			num =( count[i]+num*10) % k;
		}
		if (num == 0)
		{
			cout << k << endl;
		}
	}




	return 0;
}