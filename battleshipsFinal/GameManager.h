#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <string>
#include "mallib.h"
#include "Player.h"
#include "DisplayManager.h"
#include "InputManager.h"

using namespace std;

class GameManager
{
	Player& mPlayer1;
	Player& mPlayer2;
	DisplayManager& mCurrentDisplay;
	InputManager& mCurrentInput;
	bool isGameOver;
	bool isPlayer1First;
	bool isPlayer1Turn;
	bool isInputValid;
	char mTurnCount;
	string mUserInput;
public:
	GameManager(Player& Player1, Player& Player2, DisplayManager& CurrentDisplay, InputManager& CurrentInput);
	void playerTurn();
	void setupShips(Player& player, bool rand = false);
	bool coinToss();
};

#endif
