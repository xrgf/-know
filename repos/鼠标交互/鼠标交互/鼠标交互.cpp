#include<stdio.h>
#include<easyx.h>
int main()
{
	initgraph(500, 500);
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		printf("%d", m.uMsg);
		printf("%d\t%d", m.x, m.y);
	}
	closegraph();



	return 0;
}