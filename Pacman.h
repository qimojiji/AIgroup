#pragma once
#include"Map.h"

class Pacman:public Position
{
	DIRECTION go;
public:
	friend class Game;
	Pacman() {};
	
	void init(int x, int y);
	
	void move(int dir, Map &map);
	
	void getXY(int &a, int &b);
};

