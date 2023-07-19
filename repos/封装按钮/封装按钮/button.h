#pragma once
#include<iostream>
#include<graphics.h>
using namespace std;
class Button
{
public:
	Button(int x, int y, int w, int h,string name,
		COLORREF CurColor=RED, COLORREF  InColor=BLUE,COLORREF OutColor=RED,COLORREF NameCOLOR=BLACK);
	void DrawButton();
	bool MoveMouse(EASYXMSG m);
	bool Click(EASYXMSG m);

	~Button();
protected:
	int x;
	int y;
	int w;
	int h;
	COLORREF CurColor;
	COLORREF InColor;
	COLORREF OutColor;
	COLORREF NameColor;
	string name;
	

};