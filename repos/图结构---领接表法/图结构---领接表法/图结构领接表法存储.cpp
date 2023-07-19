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
	Array allv;//顶点信息
	int acrnum;//边数
	int vertnum;//顶点个数
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
	cout << "输入边数和顶点个数" << endl;
	cin >> g->acrnum;
	cin >> g->vertnum;
	cout << "输入各个顶点" << endl;
	for (int i = 0; i < g->vertnum; i++)
	{
		cin >> g->allv[i].V;//这个顶点信息输入每一个顶点
		g->allv[i].first = NULL;
	}
	cout << "输入顶点间的信息" << endl;
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