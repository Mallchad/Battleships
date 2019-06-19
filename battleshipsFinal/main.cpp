#include "GameManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "Player.h"
#include "mallib.h"

//ENTRY POINT
int main(int argc, char** argv)
{	bool isRunning = true;
	bool foo;
	if (argc)
		argv[0] == "-w" && argv[0] == "0" ?
			foo = true :
			foo = false;
	GameManager MainGame();
	DisplayManager MainDisplay();
	InputManager MainInput();

	while(isRunning)
	{//New Game
		
	}
}