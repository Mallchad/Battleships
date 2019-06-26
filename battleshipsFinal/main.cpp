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
	Player Player1();
	Player Player2();
	DisplayManager MainDisplay();
	InputManager MainInput();
	GameManager MainGame(Player1,
						 Player2,
						 MainDisplay,
						 MainInput
						  );

	while(isRunning)
	{//New Game
		
	}
}