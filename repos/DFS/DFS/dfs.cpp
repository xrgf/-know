#include<iostream>
using namespace std;
typedef char vetype[8];//顶点名
int visited[10] = { 0 };
typedef struct graph
{
	int arenum;
	int vertex;
	vetype V[10];
	int array[10][10];
}Graph,* LPGraph;
int searchpos(LPGraph g, vetype v)
{
	for (int i = 0; i < g->vertex; i++)
	{
		if (strcmp(v, g->V[i]) == 0)
		{
			return i;
		}

	}
	return -1;
}
LPGraph creatgraph()
{
	LPGraph g = (LPGraph)malloc(sizeof(Graph));
	cout << "请输入边数和顶点数" << endl;
	cin >> g->arenum >> g->vertex;
	cout << "请输入顶点信息";
	for (int i = 0; i < g->vertex; i++)
	{
		cin >> g->V[i];
	}
	memset(g->array, 0, sizeof(int) *100);
	vetype v1, v2;
	cout << "请输入顶点信息和权值" << endl;
	for (int i = 0; i < g->arenum; i++)
	{
		int value;
		cin >> v1 >> v2 >> value;
		int pos_v1 = searchpos(g, v1);
		int pos_v2 = searchpos(g, v2);
		g->array[pos_v1][pos_v2] = value;
		g->array[pos_v2][pos_v1] = value;
	}
	return g;
}
void printfgraph(LPGraph g)
{
	cout << "   ";
	for (int i = 0; i < g->vertex; i++)
	{
		cout << g->V[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < g->vertex; i++)
	{
		cout << g->V[i] << "  ";
		for (int j = 0; j < g->vertex; j++)
		{
			cout << g->array[i][j] << "  ";
		}
		cout << endl;
	}
}
void DFS(LPGraph g, int i)
{
	visited[i] = 1;
	cout << g->V[i];
	for (int j = 0; j < g->vertex; j++)
	{
		if (g->array[i][j] !=0 && visited[i] != 1)
		{
			DFS(g, j);
		}
	}
}
void DFSvertex(LPGraph g)
{
	
	for (int i = 0; i < g->vertex; i++)
	{
		if (visited[i] != 1)
		{
			DFS(g, i);
		}
	}
}

int main()
{


	LPGraph g = creatgraph();
	printfgraph(g);

	DFSvertex(g);


	return 0;
}