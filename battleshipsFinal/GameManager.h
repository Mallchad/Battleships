#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <string>
#include "mallib.h"
#include "Player.h"
#include "DisplayManager.h"
#include "InputManager.h"

class GameManager
{
	Player& rPlayer1;
	Player& rPlayer2;
	DisplayManager& rCurrentDisplay;
	InputManager& rCurrentInput;
	bool isGameOver;
	bool isPlayer1First;
	bool isPlayer1Turn;
	bool isInputValid;
	char mTurnCount;
	std::string mUserInput;
public:
	GameManager(Player& rFirstPlayer, Player& rSecondPlayer, DisplayManager& rDisplayManager, InputManager& rInputManager);
	void playerTurn();
	void setupShips(Player& rPlayer, bool rand = false);
	bool coinToss();
};

#endif
