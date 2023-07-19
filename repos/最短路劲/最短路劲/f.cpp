#include<iostream>
#include<assert.h>
#include<stdio.h>
using namespace std;

typedef  char Vertexm[8];
#define MAX 10
typedef int shortpathtable[MAX][MAX];
typedef int pathmatirx[MAX][MAX];
typedef struct graph
{
	int arcnum;
	int vertex;
	int map[MAX][MAX];
	Vertexm V[MAX];
}Grape,*LPGrape;
int serarchpos(LPGrape g, Vertexm v1)
{
	for (int i = 0; i < g->vertex; i++)
	{
		if (strcmp(g->V[i], v1) == 0)
		{
			return i;
		}
	}
	return -1;
}
LPGrape creatgraph(shortpathtable*d,pathmatirx*p)
{
	LPGrape g = (LPGrape)malloc(sizeof(Grape));
	assert(g);
	/*cout << "输入边数" << endl;
	cin >> g->arcnum;
	cout << "输入顶点数" << endl;
	cin >> g->vertex;*/
	FILE *graph = fopen("graph.txt","w+");
	if (graph == nullptr)
	{
		return NULL;
	}
	fscanf(graph,"%d\n",&g->arcnum);
	fscanf(graph, "%d\n", &g->vertex);
	
	for (int i = 0; i < g->vertex; i++)
	{
		fscanf(graph, "%s\t",&g->V[i]);
	}
	Vertexm v1, v2;
	int value;
	memset(g->map, 1000, sizeof(int) * 100);
	for (int i = 0; i < g->arcnum; i++)
	{
		
		fscanf(graph, "%s\t%s\t%d\n", &v1, &v2, &value);
		int pos_v1 = serarchpos(g, v1);
		int pos_v2 = serarchpos(g, v2);
		g->map[pos_v1][pos_v2] = value;
		g->map[pos_v2][pos_v1] = value;
		system("cls");
	}
	for (int v = 0; v < g->vertex; v++)
	{
		for (int w = 0; w < g->vertex; w++)
		{
			(*d)[v][w] = g->map[v][w];
			(*p)[v][w] = w;
		}
	}
	for (int v = 0; v < g->vertex; v++)
	{
		for (int k = 0; k < g->vertex; k++)
			for (int w = 0; w < g->vertex; w++)
			{
				if ((*d)[v][w] > (*d)[v][k] + (*d)[k][w])
				{
					(*d)[v][w] = (*d)[v][k] + (*d)[k][w];
					(*p)[v][w] = (*p)[v][k];
				};
			}
	}
	Vertexm v12, v21;
	cout << "输入要求顶点间" << endl;
	fscanf(graph, "%s\t%s\t", v1, v2);
	int PPos_v1 = serarchpos(g, v12);
	int PP0s_v2 = serarchpos(g, v21);
	int k= 100;
	//fprintf(graph, "%d", k);
	cout << "v0--v8最短距离" << (*d)[PPos_v1][PP0s_v2] << endl;;
	for (int i = 0; i < g->vertex; i++)
	{
		for (int j = 0; j < g->vertex; j++)
		{
			cout << (*d)[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < g->vertex; i++)
	{
		for (int j = 0; j < g->vertex; j++)
		{
			cout << (*p)[i][j] << "  ";
		}
		cout << endl;
	}
	Vertexm v11, v22;
	cin >> v11 >> v22;
	int pos_vv1 = serarchpos(g, v11);
	int pos_vv2 = serarchpos(g, v22);
	int i = 1;
	
	while (1)
	{
		cout << "v" << (*p)[pos_vv1][pos_vv2];
		int pos_v11 = (*p)[pos_vv1][pos_vv2];
		if (pos_vv1 == pos_vv2)
		{
			break;
		}
	}
	fclose(graph);
	return g;

}
void dijkster(LPGrape g,shortpathtable*d,pathmatirx *p)
{
	

}
int main()
{

	int d[10][10];
	int p[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			d[i][j] = 6550;
			p[i][j] = 0;
		}
	}
	LPGrape g = creatgraph(&d,&p);
	
	int i = 1;


	return 0;
}