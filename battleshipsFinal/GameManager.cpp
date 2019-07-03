#include "GameManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "Player.h"
#include <cstdlib>

GameManager::GameManager(Player& rFirstPlayer,
						 Player& rSecondPlayer,
					   	 DisplayManager& rDisplayManager,
					 	 InputManager& rInputManager) :
						 rPlayer1(rFirstPlayer),
						 rPlayer2(rSecondPlayer),
						 rDisplay(rDisplayManager),	 
						 rInput(rInputManager)
{

}
void GameManager::playerTurn()
{

}
void GameManager::setupShips(Player& rPlayer, bool rand)
{
	char currentShipLength;
	for (int i=1; i<5; i++)
	{
		rDisplay.cDisplayShips(rPlayer);
		rDisplay.displayMessage("Enter the location of your ");
		rDisplay.displayMessage(ShipsID::SHIP_NAMES[i+1]);
		rDisplay.displayMessage(", A1 to J10");
		rDisplay.displayMessage("Current Ship Length is " + 
									ShipsID::SHIP_LENGTHS[currentShipLength]);
		rInput.openConsole();
		rInput.toCoord();
		rDisplay.displayMessage("Do you want to place the ship "
								"horizontal or vertical? v/h");
		rInput.grabInput();
		rInput.toBool();
		while (!rPlayer.insertShip(i, rInput.x, rInput.y, rInput.get));
	}
}
bool GameManager::coinToss()
{
	bool coinSide;
	coinSide = rand() % 2;
	rDisplay.displayMessage("A coin has been flipped");
	do
	{//Until input valid
		rDisplay.displayMessage("Heads or Tails? heads/tails");
	} while (!(rInput == 'h' && rInput == 't'));
	if (coinSide)
	{//Heads
		if (rInput == 'h')
			return true;
		if (rInput == 't')
			return true;
	}
}