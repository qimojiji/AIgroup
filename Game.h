#pragma once
#include"Map.h"
#include"Pacman.h"
#include"Ghost.h"
#include"Record.h"
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include<conio.h>


const int INFO_UI_SIZE = 5;

const int SIDE_INFO_UI_SIEZ = 22;

extern const int WINDOWS_SIZE_X;
extern const int WINDOWS_SIZE_Y;

class Game
{
	
	Pacman pacmanX;
	vector<Ghost> ghosts;
	Map mapX;
	Record record;

	
	int GHOST_SPEED,speed_value;
	
	int time_counter;

	vector<int> steps;
	
	bool play_flag;

public:
	Game();
	
	void init();
	
	int start();
	
	bool settings();
	
	int show_record();

	bool loop();
	
	void play(int x);
	
	void background_music(); 
	
private:
	
	void pause();
	
	bool game_over();
	
	bool game_win();
	
	void infoUI();
	
	void helpUI();
	
	void refresh();
};

