#include"button.h"
#include"dateOperate.h"
IPBUTTON creatbutton(int x,int y,int w,int h,COLORREF incolor,COLORREF outcolor,COLORREF curcolor,const char *name)
{
	IPBUTTON button = (IPBUTTON)malloc(sizeof(BUTTON));
	assert(button);
	button->x = x;
	button-> y = y;
	button->w = w;
	button->h = h;
	button->incolor = incolor;
	button->outcolor = outcolor;
	button->curcolor = curcolor;
	int len = strlen(name) + 1;
	button->name = (char*)malloc(len);
	strcpy_s(button -> name,50, name);
	return button;
	
}
void drawbutton(IPBUTTON button)
{
	setfillcolor(button->curcolor);
	fillrectangle(button->x, button->y, button->x + button->w, button->y + button->h);
	int w = textwidth(button->name);
	int h = textheight(button->name);
	setbkmode(0);
	int x = button->x + (button->w - w) / 2;
	int y = button->y + (button->h - h) / 2;
	outtextxy(x, y, button->name);

	
}
int  mousemove(IPBUTTON button, EASYXMSG m)
{

		if (m.x > button->x && m.x<(button->x + button->w) && m.y>button->y && m.y < (button->y + button->h))
		{
			 button->curcolor=button->incolor;
			
			return 1;
		}
		else
		{
			button->curcolor = button->outcolor;
			return 0;
		}
	
}