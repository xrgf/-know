#pragma once
#include"common.h"
typedef struct People
{
	char name[20];
	char num[20];
	struct People* next;
}NODE,*IPNODE;
typedef struct Peoplelist
{
	int size;
	IPNODE head;
	IPNODE tail;

}LIST,*IPLIST;
IPNODE creatnode();
IPLIST creatlist();
void tailinsert(IPLIST list);