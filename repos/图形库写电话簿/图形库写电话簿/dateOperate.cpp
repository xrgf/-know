#include "dateOperate.h"
IPNODE creatnode()
{
	IPNODE newnode = (IPNODE)malloc(sizeof(NODE));
	assert(newnode);
	newnode->next = NULL;
	return newnode;
}

IPLIST creatlist()
{
	IPLIST newlist = (IPLIST)malloc(sizeof(sizeof(LIST)));
	assert(newlist);
	newlist->size = 0;
	newlist->head = newlist->tail = NULL;
	return newlist;
}

void tailinsert(IPLIST list)
{
	IPNODE  node = creatnode();
	if (list->size == 0)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
}

