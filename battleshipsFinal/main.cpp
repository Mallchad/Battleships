#include "GameManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "Player.h"
#include "mallib.h"

//ENTRY POINT
int main(int argc, char** argv)
{	bool isRunning = true;
	bool isWindowEnabled = false;
	if (argc)
		argv[0] == "-w" && argv[0] == "0" ?
			isWindowEnabled = true :
			isWindowEnabled = false;
	Player Player1;
	Player Player2;
	DisplayManager MainDisplay(isWindowEnabled);
	InputManager MainInput(!isWindowEnabled);
	GameManager MainGame(Player1,
						 Player2,
						 MainDisplay,
						 MainInput
						  );
	MainGame.gameSetup();

	while(isRunning)
	{//New Game
		MainGame.playerTurn();
	}
}