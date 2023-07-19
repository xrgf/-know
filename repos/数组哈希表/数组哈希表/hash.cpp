#include<iostream>
#include<assert.h>
using namespace std;
typedef struct node
{
	int first;
	char str[20];
}Data,*IPData;
typedef struct hash
{
	IPData *data;//这样就可以处理hash冲突了 如果没有存储就是空
	int divide;
}Hash,*IPHash;
IPHash creahhash(int divide)
{
	IPHash hash = new Hash;
	hash->divide = divide;
	hash->data = new IPData[hash->divide];
	for (int i = 0; i < hash->divide; i++)
	{
		
		hash->data[i] = NULL;
	}
	return hash;
}
int searchpos(IPHash hash, Data data)
{
	int pos = data.first % hash->divide;
	do
	{
		if (hash->data[pos] == NULL || pos == data.first)//相同first的情况
		{
			return pos;
		}
		else
		{
			pos = pos++ % hash->divide;
		}
	} while (data.first != pos);
	cout << "hash表满了无法插入" << endl;
	return -1;//用来表示满了无法插入的情况
}
void insertbyhash(IPHash hash, Data data)
{
	int pos = searchpos(hash, data);
	
	if (pos != -1)
	{
		if (hash->data[pos] == NULL )
		{
			//如果是空的空间那么就创建空间去赋值;
			hash->data[pos] = (IPData)malloc(sizeof(Data));
			assert(hash->data[pos]);
			memcpy(hash->data[pos], &data,sizeof(Data));
		}
		if (data.first == hash->data[pos]->first)
		{
			//如果有了直接改变其中的字符串
			strcpy(hash->data[pos]->str, data.str);
		}
	}
}
void printfhash(IPHash hash)
{
	for (int i = 0; i < hash->divide; i++)
	{
		if (hash->data[i] != NULL)
		{
			cout << hash->data[i]->str << "  " << hash->data[i]->first << endl;
		}
	}
}
int main()
{
	IPHash hash = creahhash(10);
	Data data[3] = { 1,"mm",2,"kk",3,"jj" };
	for (int i = 0; i < 3; i++)
	{
		insertbyhash(hash, data[i]);
	}
	printfhash(hash);





	return 0;
}