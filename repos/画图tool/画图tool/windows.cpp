#include"tool.h"
windows::windows(int w, int h, string str  ,int flag)
{
	this->w = w;
	this->h = h;
	this->str = str;
	initgraph(w, h, flag);
	if (str.c_str() != nullptr)
	{
		loadimage(&this->img, this->str.c_str(), this->w, this->h);
		putimage(0, 0, &this->img);
	}
	else
		cleardevice();


}
windows::~windows()
{
	closegraph();
}

void windows::SetCOLOR(COLORREF bkColor)
{
	setbkcolor(bkColor);
	cleardevice();
}

void windows::out()
{
	outtextxy(0, 0, str.c_str());
}


