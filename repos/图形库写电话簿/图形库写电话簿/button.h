#pragma once
#include"common.h"
#include"dateOperate.h"

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
}BUTTON, * IPBUTTON;
IPBUTTON creatbutton(int x, int y, int w, int h, COLORREF incolor, COLORREF outcolor, COLORREF curcolor,const char*name);
void drawbutton(IPBUTTON button);
int mousemove(IPBUTTON button, EASYXMSG m);