#include<iostream>
using namespace std;
typedef char vertex[8] ;//����
typedef int  vrtype  ;//Ȩֵ
#define MAX 10
typedef struct graph
{
	int arcnum;//����
	int vexnum;//������
	vertex  V[MAX];//����
	vrtype  map[MAX][MAX];
}Graph,*LPGraph;
int searchpos(char v1[], LPGraph graph)
{
	char* pmove;
	for (int i = 0; i < graph->vexnum; i++)
	{
		pmove = graph->V[i];
		if (!strcmp(pmove, v1))
		{
			return i;
		}
	}
	return -1;
}
LPGraph creatgapgh()
{
	LPGraph graph = (LPGraph)malloc(sizeof(Graph));
	cout << "�����붥�����ͱ���" << endl;
	scanf("%d", &graph->vexnum);
	scanf("%d", &graph->arcnum);
	cout << "�����붥����Ϣ" << endl;
	for (int i = 0; i < graph->vexnum; i++)
	{
		scanf("%s", graph->V[i]);
	}
	memset(graph->map, 0, sizeof(int)* 100);
	//���붥����Ϣ
	vertex v1, v2;
	cout << "�����붥��֮����Ϣ" << endl;
	for (int i = 0; i < graph->arcnum; i++)
	{
		int index;
		scanf("%s%s%d", v1, v2,&index);
		int pos1 = searchpos(v1, graph);
		int pos2 = searchpos(v2, graph);
		graph->map[pos1][pos2] = index;
		graph->map[pos2][pos1] = index;
		
	}
	
	return graph;
}
void printfgraph(LPGraph graph)
{
	for (int i = 0; i < graph->vexnum; i++)
	{
		for (int j = 0; j < graph->vexnum; j++)
		{
			cout << graph->map[i][j] << "  ";
		}
		cout << endl;
	}
}
int main()
{


	LPGraph graph = creatgapgh();
	printfgraph(graph);




	return 0;
}