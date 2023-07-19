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
	IPData *data;//�����Ϳ��Դ���hash��ͻ�� ���û�д洢���ǿ�
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
		if (hash->data[pos] == NULL || pos == data.first)//��ͬfirst�����
		{
			return pos;
		}
		else
		{
			pos = pos++ % hash->divide;
		}
	} while (data.first != pos);
	cout << "hash�������޷�����" << endl;
	return -1;//������ʾ�����޷���������
}
void insertbyhash(IPHash hash, Data data)
{
	int pos = searchpos(hash, data);
	
	if (pos != -1)
	{
		if (hash->data[pos] == NULL )
		{
			//����ǿյĿռ���ô�ʹ����ռ�ȥ��ֵ;
			hash->data[pos] = (IPData)malloc(sizeof(Data));
			assert(hash->data[pos]);
			memcpy(hash->data[pos], &data,sizeof(Data));
		}
		if (data.first == hash->data[pos]->first)
		{
			//�������ֱ�Ӹı����е��ַ���
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