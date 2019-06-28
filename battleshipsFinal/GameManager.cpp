#include "GameManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "Player.h"
GameManager::GameManager(Player& rFirstPlayer, Player& rSecondPlayer, DisplayManager& rDisplayManager, InputManager& rInputManager) :
	rPlayer1(rFirstPlayer), rPlayer2(rSecondPlayer), rCurrentDisplay(rDisplayManager), rCurrentInput(rInputManager)
{

}
void GameManager::playerTurn()
{

}
void GameManager::setupShips(Player& rPlayer, bool rand)
{
	char currentShipLength;
	rCurrentDisplay.cDisplayShips(rPlayer);
	rCurrentDisplay.displayMessage("Enter the location of your first ship, A1 to J10");
	rCurrentDisplay.displayMessage("Current Ship Length is " + ShipsID::SHIP_LENGTHS[currentShipLength]);
}
bool GameManager::coinToss()
{
	char userInput = 0;
	bool coinSide;
	coinSide = rand() % 2;
	rCurrentDisplay.displayMessage("A coin has been flipped");
	do
	{//Until input valid
		rCurrentDisplay.displayMessage("Heads or Tails? heads/tails");
		userInput = rCurrentInput.getUserInput()[0];
	} while (userInput != 'h' && userInput != 't');
	if (coinSide)
	{//Heads
		if (userInput == 'h')
			return true;
		if (userInput == 't')
			return true;
	}
}