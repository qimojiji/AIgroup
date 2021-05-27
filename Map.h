#pragma once
#include"Position.h"
#include<vector>
#include<queue>
using namespace std;

const int MAP_SIZE = 29;
const int PACMAN_X = MAP_SIZE / 2;
const int PACMAN_Y = MAP_SIZE / 2;


extern const int TIME_SPEED;
const int MAX_FREEZE_TIME = 5 * 1000 / TIME_SPEED;


enum MAP_POS_TYPE { SPACE,WALL,PEAN,SUPER_PEAN };
class MapPos: public Position
{
	int type; 
public:
	
	void setType(int t);
	int getType() { return type; }
};


struct PosXY
{
	int x, y;
};

class Pacman;
class Ghost;
class Map
{
	
	MapPos points[MAP_SIZE][MAP_SIZE];
	
	int scores;
	
	int target_scores;

	int freezeTime;
	
	void findPath(Position &A, Position&B);

public:
	friend class Game;
	friend class Ghost;
	Map() {};
	
	void init(const char* filepath, Pacman &pacman, vector<Ghost> &ghosts);
	
	void renew(int x, int y) { points[x][y].print(); }
	
	int goXY(int x, int y) { return points[x][y].getType(); }
	
	void delPean(int x, int y);
	
	bool oK(int x, int y);
	
	void delSuperPean(int x, int y);
	
	int findDir(Position &A, Position&B);
};

