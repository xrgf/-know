#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<assert.h>
#define WIDTH 600
#define HIGHT 500
IMAGE img;
typedef struct Button
{
	int x;
	int y;
	int w;
	int h;
	COLORREF incolor;
    COLORREF outcolor;
    COLORREF curcolor;
	char* name;
}BUTTON ,*IPBUTTON;
IPBUTTON creatbutton(int x, int y, int w, int h, COLORREF incolor, COLORREF outcolor, COLORREF curcolor, const char* name)
{
	IPBUTTON button = (IPBUTTON)malloc(sizeof(BUTTON));
	assert(button);
	button->x = x;
	button->y = y;
	button->w = w;
	button->h = h;
	button->incolor = incolor;;
	button->outcolor = outcolor;
	button->curcolor = curcolor;
	int len = strlen(name) + 1;
	button->name = (char*)malloc(len);
	assert(button->name);
	strcpy_s(button->name, len, name);
	return button;


}
void drawbutton(IPBUTTON button)
{
	setfillcolor(button->incolor);
	fillrectangle(button->x, button->y, button->x + button->w, button->y + button->h);
	int w = textwidth(button->name);
	int h = textheight(button->name);
	int x = button->x + (button->w - w) / 2;
	int y = button->y + (button->h - h) / 2;
	setbkmode(0);
	outtextxy(x, y, button->name);

}
int  mousemove(IPBUTTON button, EASYXMSG m)
{
	if (m.x > button->x && m.x > button->x + button->w && m.y > button->y && m.y < button->y + button->h)
	{
		button->curcolor = button->incolor;
		return 1;
	}
	else
	{
		button->curcolor = button->outcolor;
		return 0;
	}
}

int main()
{
	IPBUTTON Creat = creatbutton(250, 200, 100, 40, BLUE, RED, RED, "新建联系人");
	IPBUTTON Delete = creatbutton(250, 250, 100, 40, BLUE, RED, RED, "删除联系人");
	initgraph(WIDTH, HIGHT);
	
	while (1)
	{
		EASYXMSG m = getmessage(EM_MOUSE|EM_KEY);
		BeginBatchDraw();
		//loadimage(&img, "背景.jpg", WIDTH, HIGHT);
		//putimage(0, 0, &img);
	
		drawbutton(Creat);
		drawbutton(Delete);
		mousemove(Creat, m);
		mousemove(Delete, m);
		EndBatchDraw();
	}
	
	closegraph();









}