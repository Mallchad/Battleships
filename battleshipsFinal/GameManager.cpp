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
void GameManager::setupShips(Player& rPlayer)
{
	char currentShipLength;
	for (int i=1; i<5; i++)
	{
		rDisplay.cDisplayShips(rPlayer);
		rDisplay.displayMessage("Enter the location of your ");
		rDisplay.displayMessage(ShipID::SHIP_NAMES[i+1]);
		rDisplay.displayMessage(", A1 to J10");
		rDisplay.displayMessage("Current Ship Length is " + 
								 ShipID::SHIP_LENGTHS[currentShipLength]);
		rInput.openConsole();
		rInput.toCoord();
		rDisplay.displayMessage("Do you want to place the ship "
								"horizontal or vertical? v/h");
		rInput.openConsole();
		rInput.toBool();
		while (!rPlayer.insertShip(i, rInput.x, rInput.y, rInput.get));
	}
	rDisplay.displayMessage("Ship Setup has complete");
}
void GameManager::gameSetup()
{
	bool isGameOver;
	bool isPlayer1First = rand() % 2;
	bool isPlayer1Turn = isPlayer1First;
	char mTurnCount = 0;
	rDisplay.displayMessage("Player 1 please setup your ships");
	setupShips(rPlayer1);
	rDisplay.displayMessage("Player 2 please setup your ships");
	setupShips(rPlayer2);
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
void GameManager::playerTurn()
{	char foo = 0;
	if (isPlayer1Turn)
	{	rDisplay.displayMessage("It is Player 1's turn");
	rDisplay.cDisplayGameView(rPlayer1);
		rDisplay.displayMessage("Entry the grid location you want to shoot at, A1-J10");
		rInput.openConsole();
		foo = rPlayer1.shootEnemy(rPlayer2, rInput[0]);
	}
	else if (!isPlayer1Turn)
	{	rDisplay.displayMessage("It is player 2's turn");
		rDisplay.cDisplayGameView(rPlayer2);
		rDisplay.displayMessage("Entry the grid location you want to shoot at, A1-J10");
		rInput.openConsole();
		foo = rPlayer1.shootEnemy(rPlayer1, rInput[0]);
	}
	else;
}