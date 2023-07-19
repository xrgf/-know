#include <stdio.h>
#define NO  0xFFFFFF		//不连通的状态 用一个很大的值表示无穷大
#define MAX 100
typedef struct graph
{
	char vexs[MAX];			//顶点数组
	int vexnum;				//顶点数
	int arcnum;				//边数
	int matrix[MAX][MAX];	//权值数组
}GRAPH, * LPGRAPH;
//map:图  in:入口 dist：存放最短路径
void Dijkstra(GRAPH map, int in, int dist[])
{
	int i = 0;
	int flag[MAX];		//成功获取路径的标记
	//1.求出当前入口到其他顶点的路径
	for (i = 0; i < map.vexnum; i++)
	{
		//dist[i]用来存放in这个顶点到其他顶点的最短距离
		//1-1 dist[0]=NO
		//1-2 dist[1]=10  
		//1-3 dist[2]:NO :无穷大
		flag[i] = 0;
		dist[i] = map.matrix[in][i];		//当前in顶点到其他顶点距离
	}
	flag[in] = 1;		//in进来标记一下
	dist[in] = 0;	    //这个可以不写
	int min;
	int j = 0;
	int k = 0;
	//2.扩充顶点
	for (i = 1; i < map.vexnum; i++)	//i=1 扩充'2'顶点
	{
		//3.扩充顶点要做的事情
		min = NO;			//不连通
		for (j = 1; j < map.vexnum; j++)
		{
			//2-3
			if (flag[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
		flag[k] = 1;
		for (j = 1; j < map.vexnum; j++)
		{
			if (flag[j] == 0 && (min + map.matrix[k][j]) < dist[j])
			{
				dist[j] = min + map.matrix[k][j];
			}
		}
	}
	printf("\n");
	for (int i = 1; i < map.vexnum; i++)
	{
		printf("最短路径(%c,%c)=%d\n", map.vexs[in], map.vexs[i], dist[i]);
	}
}
int main()
{
	//创建图
	GRAPH  map = { {'1','2','3','4','5'},5,7,
		{
			{NO,10,NO,30,100},
			{NO,NO,50,NO,NO},
			{NO,NO,NO,NO,10},
			{NO,NO,20,NO,60},
			{NO,NO,NO,NO,NO}
		}
	};
	int in = 0;
	int dist[MAX];
	Dijkstra(map, in, dist);
	return 0;
}