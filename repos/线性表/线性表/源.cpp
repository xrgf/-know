#include<iostream>
#include<stdlib.h>
//#include<cstdio>
//#include<cassert>
//using namespace std;
//typedef struct list
//{
//	char** str;
//	int cusize;
//}List,* IPList;
//IPList creatlist(int capacity)
//{
//	IPList list = new List;
//	list->cusize = 0;
//	list->str = (char**)malloc(sizeof(char*)*capacity);
//	for (int i = 0; i < capacity; i++)
//	{
//		list->str[i] = (char*)malloc(sizeof(char) * 20);
//		assert(list->str[i]);
//	}
//	assert(list->str);
//	return list;
//}
//void insertbylist(IPList list,const char *str)
//{
//	if (list->cusize + 1 == 10)
//	{
//		cout << "���Ա��Ѿ�����  �޷�����" << endl;
//	}
//	else
//	{
//		//����ǽṹ�廹���԰��ṹ��Ȩֵ����
//		strcpy(list->str[list->cusize++], str);
//	}
//
//}
//void printflist(IPList list)
//{
//	for (int i = 0; i < list->cusize; i++)
//	{
//		cout << list->str[i] << endl;
//	}
//}
//void deletelist(IPList list,const char* str)
//{
//	int index = -1;
//	for (int i = 0; i < list->cusize; i++)
//	{
//		
//		if (!strcmp(list->str[i], str))
//		{
//			index = i;//��¼�ҵ���ͬ��Ԫ��
//			break;
//		}
//		if (i + 1 == list->cusize)
//		{
//			cout << "û���ҵ���delete��Ԫ��" << endl;
//			
//		}
//		
//	}
//	
//	if(index!=-1)
//	{
//		for (int i = index; i < list->cusize; i++)
//		{
//			list->str[i] = list->str[i + 1];
//			list->cusize--;
//		}
//	}
//	
//}
//int main()
//{
//	IPList list = creatlist(10);
//	insertbylist(list, "ëë");
//	insertbylist(list, "mama");
//	insertbylist(list, "ll");
//	printflist(list);
//	deletelist(list, "kk");
//	printflist(list);
//
//
//	return  0;
//}
