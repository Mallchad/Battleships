#pragma once
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#include "Player.h"

//Handles Monitor Output
class DisplayManager
{	DisplayManager(bool windowOn = true);

public:
//Interface
	bool isWindowEnabled;
	//Console Display
	void displayMessage(char* message, float x = 0, float y = 0);
	void cDisplayShips(Player& player);
	void cDisplayGameView(Player& player);
};


#endif