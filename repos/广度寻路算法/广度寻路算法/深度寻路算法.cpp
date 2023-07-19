#include<iostream>
#include<vector>
#include<array>
#define CLOS 10
#define ROW  10
using namespace std;
int mapArr[ROW][CLOS] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 1, 0, 1, 1, 0, 1, 0, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
		{ 0, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 }
};

struct mypoint
{
	int y;
	int x;
	
};
enum D
{
	p_up=0, p_right, p_down, p_left
	
};
struct pathnode
{
	int val;
	 D dir;
	bool isfind;
};

template<class T>
class stack
{
public:
	
	void push(T data)
	{
		all[++cursize] = data;
	}
	T gettop()
	{
		return all[cursize];
	}
	void pop()
	{
		cursize--;
	}
	bool empty()
	{
		return cursize == -1;
	}
protected:
	T data;
	T all[1000];
	int cursize=-1;
	
};
bool isCheckMove(pathnode p[][CLOS], int row, int col)
{
	if (row < 0 || row >= ROW|| col < 0 || col >= CLOS)//越界判断
		return false;
	if (p[row][col].isfind == true || p[row][col].val != 0)//判断当前行列表示的坐标已经访问过，或者当前坐标上的值为表示障碍
		return false;
	return true;
}
void migong(int map[][CLOS])
{
	pathnode path[ROW][CLOS];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < CLOS; j++)
		{
			path[i][j].val = map[i][j];
			path[i][j].isfind = false;
			path[i][j].dir = p_up;
		}
	}
	mypoint beginpoint = { 1,1 };
	mypoint endpoint = { 9,8 };
	stack<mypoint>ms;
	ms.push(beginpoint);
	mypoint curpoint = beginpoint;
	while (true)
	{
		switch (path[curpoint.y][curpoint.x].dir)
		{
		case p_up:

			path[curpoint.y][curpoint.x].dir = p_right;
			if (isCheckMove(path, curpoint.y - 1, curpoint.x))
			{
				path[curpoint.y][curpoint.x].isfind = true;
				mypoint temppoint = { curpoint.y-1, curpoint.x };
				ms.push(temppoint);
				curpoint = temppoint;
			}
			break;
		case p_right:

			path[curpoint.y][curpoint.x].dir = p_down;
			if (isCheckMove(path, curpoint.y, curpoint.x + 1))
			{
				path[curpoint.y][curpoint.x].isfind = true;
				mypoint temppoint = { curpoint.y, curpoint.x+1 };
				ms.push(temppoint);
				curpoint = temppoint;
			}
			break;
		case p_down:

			path[curpoint.y][curpoint.x].dir = p_left;//表示换方向如果
			if (isCheckMove(path, curpoint.y + 1, curpoint.x))//按p_down下坐标去找
			{
				//如果进了这个条件前面换方向是没用的 只能在这个新的坐标符合
				path[curpoint.y][curpoint.x].isfind = true;//将原来的点设置为走过的点
				mypoint temppoint = { curpoint.y+1, curpoint.x };
				ms.push(temppoint);
				curpoint = temppoint;
			}
			break;
		case p_left:

			//path[curpoint.y][curpoint.x].dir;
			if (isCheckMove(path, curpoint.y, curpoint.x - 1))
			{
				path[curpoint.y][curpoint.x].isfind = true;//走过的点标记一下
				mypoint temppoint = { curpoint.y, curpoint.x-1 };//用这个点表示下一个方向的点
				ms.push(temppoint);
				curpoint = temppoint;
			}
			else
			{
				//mypoint temppoint = ms.gettop();
				path[curpoint.y][curpoint.x].isfind = true;
				ms.pop();
				if (!ms.empty())
				{
					curpoint = ms.gettop();
				}
			}
			break;
		}//switch(
		if (ms.empty())//意思就是退到空了 没空就是0 空就是1
		{
			break;//没有出口
		}
		if (curpoint.y == endpoint.y && curpoint.x == endpoint.x)
		{
			break;
		}
	}//while(1)
	while (!ms.empty())
	{
		cout <<"("<< ms.gettop().y << "," << ms.gettop().x<<")" << endl;
		ms.pop();
	}
}
int main()
{

	migong(mapArr);





	return 0;
}