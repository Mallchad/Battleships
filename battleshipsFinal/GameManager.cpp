#include "GameManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "Player.h"
#include <cstdlib>
#include "mallib.h"

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
	for (int ship=1; ship<=5; ship++)
	{	do
		{
			rDisplay.cDisplayShips(rPlayer);
			mrd::print("Enter the location of your ", false);
			mrd::print(ShipID::SHIP_NAMES[ship-1], false);
			rDisplay.displayMessage(", A1 to J10");
			mrd::print("Current Ship Length is ", false);
			mrd::print(ShipID::SHIP_LENGTHS[ship-1]);
			rInput.openConsole();
			rDisplay.displayMessage("Do you want to place the ship "
									"horizontal or vertical? v/h");
			if ( !rInput.toCoord() )
			{	system("cls");
				rDisplay.displayMessage("Coordinates are invalid. Please enter "
										"coordinates with letters first. A1-J10");
				continue;
			}
			rInput.openConsole();
			system("cls");
		} while ( !rPlayer.insertShip(ship, rInput.x, rInput.y, rInput == 'h') );
	}
	rDisplay.displayMessage("Ship Setup has complete");
}
void GameManager::gameSetup()
{	
	rPlayer1.reset();
	rPlayer2.reset();
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
		if (rInput != 'h' || rInput != 't')
			mrd::print(rInput.get(), false);
			mrd::print(" is not heads or tails");
	} while (rInput != 'h' || rInput != 't' || rInput != 'H' || rInput != 'T');
	if (coinSide)
	{//Heads
		if (rInput == 'h' || rInput == 'H')
			return true;
		if (rInput == 't' || rInput == 'T')
			return true;
	}
}
void GameManager::playerTurn()
{	char foo = 0;
	if (isPlayer1Turn)
	{	rDisplay.displayMessage("It is Player 1's turn");
		rDisplay.cDisplayGameView(rPlayer1);
		rDisplay.displayMessage("Entry the grid location you want to shoot at, A1-J10");
		do
		{	rInput.openConsole();
		
			if (rInput.toCoord() == -1)
				rDisplay.displayMessage("Please enter a valid grid location "
										"Starting with a letter, A1-J10");
		} while (rInput.toCoord() == -1);
		rPlayer1.shootEnemy(rPlayer2, rInput.getCoord());
	}
	else if (!isPlayer1Turn)
	{	rDisplay.displayMessage("It is player 2's turn");
		rDisplay.cDisplayGameView(rPlayer2);
		rDisplay.displayMessage("Entry the grid location you want to shoot at, A1-J10");
		do
		{	rInput.openConsole();
			if (rInput.toCoord() == -1)
				rDisplay.displayMessage("Please enter a valid grid location "
										"Starting with a letter, A1-J10");
		} while (rInput.toCoord() == -1);
		rPlayer1.shootEnemy(rPlayer1, rInput.getCoord());
	}
	else;
	isPlayer1Turn = !isPlayer1Turn;
	do
	{	system("cls");
		rDisplay.displayMessage("Type ready when the next player is ready to go");
		rInput.openConsole();
	} while (rInput != 'r' && rInput != 'R');
}