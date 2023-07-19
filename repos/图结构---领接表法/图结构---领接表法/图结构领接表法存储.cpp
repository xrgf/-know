#include<iostream>
using namespace std;
typedef char vertex[8];
typedef struct node
{
	int verteindex;
	struct node* next;
}Node,*LPNode;
LPNode creatnode(int index)
{
	LPNode newnode = (LPNode)malloc(sizeof(Node));
	newnode->verteindex = index;
	newnode->next = NULL;
	return newnode;
}
void insertnode(LPNode* headnode,int index)
{
	LPNode node = creatnode(index);
	node->next = (*headnode);
	*headnode = node;
}
typedef struct v
{
	vertex V;
	LPNode first;
}Vertex,*LPVertex,Array[10];

typedef struct graph
{
	Array allv;//������Ϣ
	int acrnum;//����
	int vertnum;//�������
}Graph,*LPGraph;
int searchnode(vertex v1, LPGraph g)
{
	for (int i = 0; i < g->vertnum; i++)
	{
		if (strcmp(v1, g->allv[i].V) == 0)
		{
			return i;
		}
	}
	return -1;
}
LPGraph creatgraph()
{
	LPGraph g = (LPGraph)malloc(sizeof(Graph));
	cout << "��������Ͷ������" << endl;
	cin >> g->acrnum;
	cin >> g->vertnum;
	cout << "�����������" << endl;
	for (int i = 0; i < g->vertnum; i++)
	{
		cin >> g->allv[i].V;//���������Ϣ����ÿһ������
		g->allv[i].first = NULL;
	}
	cout << "���붥������Ϣ" << endl;
	for (int i = 0; i < g->acrnum; i++)
	{
		vertex v1, v2;
		cin >> v1 >> v2;
		int pos_v1 = searchnode(v1, g);
		int pos_v2 = searchnode(v2, g);
		insertnode(&g->allv[pos_v1].first, pos_v2);
		insertnode(&g->allv[pos_v2].first, pos_v1);
		
	}
	return g;

}
void printfgraph(LPGraph g)
{
	/*cout << "  ";
	for (int i = 0; i < g->vertnum; i++)
	{
		cout << g->allv[i].V << "  ";
	}*/
	cout << endl;
	
	for (int i = 0; i < g->vertnum; i++)
	{
		cout << g->allv[i].V<<"  ";
		
		LPNode pmove = g->allv[i].first;
		while (pmove != NULL)
		{
			cout << pmove->verteindex << "  ";
			pmove = pmove->next;
		}
		cout << endl;
	}

}
int main()
{

  LPGraph g=creatgraph();
  printfgraph(g);


	return 0;
}