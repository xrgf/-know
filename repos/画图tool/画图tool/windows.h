#pragma once
#include<iostream>
#include<graphics.h>
using namespace std;
class windows
{
public:
	windows(int w, int h, string str = "", int flag = 0);
	~windows();
	void SetCOLOR(COLORREF bkColor);
	void out();
protected:
	int w;
	int h;
	IMAGE img;
	string str;
	

};