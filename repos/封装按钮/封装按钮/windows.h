#pragma once
#include<graphics.h>
#include<iostream>
using namespace std;
class Windows
{
public:
	Windows(int w, int h, string str = "",int flag=NULL);
	void refresh();
	int getweight();
	int getheight();
	

	~Windows();
protected:
	int weight;
	int height;
	IMAGE imgbackground;
	string str;

};