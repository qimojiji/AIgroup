#pragma once
#include<vector>
#include<ctime>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
#include"win_tools.h"

class Record;
class RecordItem 
{
	string name;
	int score;
	int speed;
	int ghost_num;
	int steps_num;
	vector<int> steps;
public:
	friend class Record;
	friend class Game;
	RecordItem() { steps_num = 0;};
	RecordItem(const string& iname, int iscore) { name = iname; score = iscore; steps_num = 0;};
	bool operator <(const RecordItem &B) { return score > B.score; }
};

class Record 
{
	const char *filepath; 
	vector<RecordItem> items; 
public:
	friend class Game;
	Record():filepath("game.record"){};
	
	void read();
	
	void save();
	
	void add(int the_score,const vector<int> &steps,int ghost_num,int speed);

	void del(int x);
	
	void show();
};

