#include <stdio.h>
#define NO  0xFFFFFF		//����ͨ��״̬ ��һ���ܴ��ֵ��ʾ�����
#define MAX 100
typedef struct graph
{
	char vexs[MAX];			//��������
	int vexnum;				//������
	int arcnum;				//����
	int matrix[MAX][MAX];	//Ȩֵ����
}GRAPH, * LPGRAPH;
//map:ͼ  in:��� dist��������·��
void Dijkstra(GRAPH map, int in, int dist[])
{
	int i = 0;
	int flag[MAX];		//�ɹ���ȡ·���ı��
	//1.�����ǰ��ڵ����������·��
	for (i = 0; i < map.vexnum; i++)
	{
		//dist[i]�������in������㵽�����������̾���
		//1-1 dist[0]=NO
		//1-2 dist[1]=10  
		//1-3 dist[2]:NO :�����
		flag[i] = 0;
		dist[i] = map.matrix[in][i];		//��ǰin���㵽�����������
	}
	flag[in] = 1;		//in�������һ��
	dist[in] = 0;	    //������Բ�д
	int min;
	int j = 0;
	int k = 0;
	//2.���䶥��
	for (i = 1; i < map.vexnum; i++)	//i=1 ����'2'����
	{
		//3.���䶥��Ҫ��������
		min = NO;			//����ͨ
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
		printf("���·��(%c,%c)=%d\n", map.vexs[in], map.vexs[i], dist[i]);
	}
}
int main()
{
	//����ͼ
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