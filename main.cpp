#include"Game.h"


const int WINDOWS_SIZE_X = (MAP_SIZE + SIDE_INFO_UI_SIEZ) * 2 - 1;
const int WINDOWS_SIZE_Y = MAP_SIZE + INFO_UI_SIZE;
int main() {

	
	Game gameCtrl;
	int choice = 0;
	gameCtrl.background_music();
	while (true) {
		
		choice = gameCtrl.start();
		if (choice == 0) { 
			
			if(!gameCtrl.settings()) continue;
			
			gameCtrl.init();
			gameCtrl.loop();
		}
		else if (choice == 1) { 
			
			int record_idx=gameCtrl.show_record();
			if (record_idx != -1) { 
				gameCtrl.play(record_idx);
			}
		}
	}
}