#include"button.h"
Button::Button(int x, int y, int w, int h,
	string name,COLORREF CurColor, COLORREF  InColor, COLORREF OutColor ,COLORREF NameColor)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->CurColor = CurColor;
	this->InColor = InColor;
	this->OutColor = OutColor;
	this->NameColor = NameColor;
	this->name = name;
}

void Button::DrawButton()
{
	settextcolor(this->NameColor);
	setfillcolor(this->CurColor);
	setbkmode(TRANSPARENT);
	fillrectangle(this->x, this->y, this->x + this->w, this->y + this->h);
	int xx = textwidth(name.c_str());
	int yy = textheight(name.c_str());
	int xxx = x + (this->w - xx)/2;
	int yyy = y + (this->h - yy)/2;
	outtextxy(xxx, yyy, name.c_str());
	
}

bool Button::MoveMouse(EASYXMSG m)
{
	if (m.x > this->x && m.x<this->x + this->w && m.y>this->y && m.y < this->y + this->h)
	{
		this->CurColor = InColor;
		return true;
	}
	else
	{
		this->CurColor = OutColor;
		return false;

	}
}

bool Button::Click(EASYXMSG m)
{
	if (MoveMouse(m) && m.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}
Button::~Button()
{

}
