#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <string>
#include "mallib.h"
#include "Player.h"

using namespace std;

class GameManager
{	GameManager();
	Player& Player1;
	Player& Player2;
	bool isGameOver;
	bool isPlayer1First;
	bool isPlayer1Turn;
	bool isInputValid;
	char mTurnCount;
	string mUserInput;
public:
	void playerTurn();
	void setupShips(Player& player, bool rand = false);
	bool coinToss();
};

#endif
