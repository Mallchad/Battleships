#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#include "Player.h"

//Handles Monitor Output
class DisplayManager
{

public:
	DisplayManager(bool windowOn = true);
	bool isWindowEnabled;
	//Console Display
	void displayMessage(const char* message, float x = 0.f, float y = 0.f);
	void cDisplayShips(Player& rPlayer);
	void cDisplayGameView(Player& rPlayer);
};


#endif