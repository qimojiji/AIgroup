#pragma once
#include"Position.h"
#include"Map.h"
#include"Pacman.h"

class Ghost:public Position
{
	
	DIRECTION go;

	int init_x, init_y;
public:
	Ghost() {};
	
	Ghost(int x, int y);
	
	int move(Map &map,Pacman &pacman);
	int move(int dir,Map &map, Pacman &pacman);
	
	bool hit(Pacman &pacman, Map &map);
};

