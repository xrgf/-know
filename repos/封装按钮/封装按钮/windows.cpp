#include "windows.h"

Windows::Windows(int w, int h, string str,int flag )
{
	this->weight = w;
	this->height = h;
	this->str = str;
	initgraph(this->weight, this->height, flag);
	if (str.c_str() != nullptr)
	{
		loadimage(&this->imgbackground, str.c_str(), this->weight, this->height);
		putimage(0, 0, &this->imgbackground);
	}
}

void Windows::refresh()
{
	if (this->str.size() != 0)
	{
		putimage(0, 0, &this->imgbackground);
	}
	else
	{
		cleardevice();
	}
}

Windows::~Windows()
{
	closegraph();
}
int Windows:: getweight()
{
	return this->weight;
}
int Windows::getheight()
{
	return  this->weight;
}