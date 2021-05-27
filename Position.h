#pragma once

#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
#include"win_tools.h"


enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Position
{
protected:
	string key;
	int x, y;  
	int color; 
public:
	friend class Map;
	Position() {
		color = BLUE_GREEN_COLOR;
	}
	Position(int a, int b, const string str,int icolor = BLUE_GREEN_COLOR) {
		setXY(a, b);
		color = icolor;
		setKey(str);
	}
	
	void setKey(const string str);
	
	void setXY(int a, int b);
	
	void print();
	
	void clear();
};

