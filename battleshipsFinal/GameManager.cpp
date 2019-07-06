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
			mrd::print(rPlayer.shipLengths[ship-1]);
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
bool GameManager::coinToss()
{
	bool coinSide;
	coinSide = rand() % 2;
	rDisplay.displayMessage("A coin has been flipped, played 1 gets to choose");
	do
	{//Until input valid
		rDisplay.displayMessage("Heads or Tails? heads/tails");
		rInput.openConsole();
		rInput.toLower();
		if (rInput != 'h' && rInput != 't')
		{	mrd::print(rInput.get(), false);
			mrd::print(" is not heads or tails");
		}
	} while (rInput != 'h' && rInput != 't');
	if (coinSide)
	{//Heads
		if (rInput == 'h')
			return true;
		if (rInput == 't')
			return false;
	}
	else
	{//Tails
		if (rInput == 't')
			return true;
		if (rInput == 'h')
			return false;
	}
}
void GameManager::gameSetup()
{	
	rPlayer1.reset();
	rPlayer2.reset();
	isGameOver = false;
	isPlayer1Turn = isPlayer1First;
	if (isPlayer1First)
		rDisplay.displayMessage("You won the toss");
	else
		rDisplay.displayMessage("You lost the toss");
	turnCount = 0;
	victor = 0;
	rDisplay.displayMessage("Player 1 please setup your ships");
	setupShips(rPlayer1);
	rDisplay.displayMessage("Player 2 please setup your ships");
	setupShips(rPlayer2);
	isPlayer1First = coinToss();
}
void GameManager::playerTurn()
{	mrd::print(turnCount);
	if (isPlayer1Turn)
	{	rDisplay.displayMessage("It is Player 1's turn");
		rDisplay.cDisplayGameView(rPlayer1);
		rDisplay.displayMessage("Entry the grid location you want to shoot at, A1-J10");
		do
		{//Player 1 Input
			rInput.openConsole();
		
			if (!rInput.toCoord())
				rDisplay.displayMessage("Please enter a valid grid location "
										"Starting with a letter, A1-J10");
		} while (!rInput.toCoord());
		rPlayer1.shootEnemy(rPlayer2, rInput.getCoord());
		system("cls");
		//Game feedback
		switch (rPlayer2.playerState)
		{	case PlayerState::None:
				rDisplay.displayMessage("You missed the enemy...");
				break;
			case PlayerState::ShipHit:
				rDisplay.displayMessage("You hit the enemy!");
				break;
			case PlayerState::ShipDestroyed:
				rDisplay.displayMessage("You destroyed the enemy's ship!!!");
				break;
			case PlayerState::Defeated:
				rDisplay.displayMessage("You have defeated the enemy!!!");
				rDisplay.displayMessage("You have won!!!");
				victor = 1;
				isGameOver = true;
				return;
				break;
		}
	}
	else if (!isPlayer1Turn)
	{	rDisplay.displayMessage("It is player 2's turn");
		rDisplay.cDisplayGameView(rPlayer2);
		rDisplay.displayMessage("Entry the grid location you want to shoot at, A1-J10");
		do
		{	rInput.openConsole();
			if (!rInput.toCoord())
				rDisplay.displayMessage("Please enter a valid grid location "
										"Starting with a letter, A1-J10");
		} while (!rInput.toCoord());
		rPlayer2.shootEnemy(rPlayer1, rInput.getCoord());
		system("cls");
		//Game feedback
		switch (rPlayer1.playerState)
		{
		case PlayerState::None:
			rDisplay.displayMessage("You missed the enemy...");
			break;
		case PlayerState::ShipHit:
			rDisplay.displayMessage("You hit the enemy!");
			break;
		case PlayerState::ShipDestroyed:
			rDisplay.displayMessage("You destroyed the enemy's ship!!!");
			break;
		case PlayerState::Defeated:
			rDisplay.displayMessage("You have defeated the enemy!!!");
			rDisplay.displayMessage("You have won!!!");
			victor = 2;
			return;
			isGameOver = true;
			break;
		}
	}
	else;
	//Change player turn
	isPlayer1Turn = !isPlayer1Turn;
	do
	{	rDisplay.displayMessage("Type ready when the next ready to move on to "
								"their turn");
		rInput.openConsole();
	} while (rInput != 'r' && rInput != 'R');
	system("cls");
	if(++turnCount >= 50)
	{	isGameOver = true;
		victor = 0;
	}
}
bool GameManager::endGame()
{
	switch (victor)
	{	case 0:
			rDisplay.displayMessage("A statement is called. This game has gone on long enough");
			break;
		case 1:
			rDisplay.displayMessage("Player 1 is victorious!");
			break;
		case 2:
			rDisplay.displayMessage("Player 2 is victorious!");
			break;
	}
	rDisplay.displayMessage("Would you like to play again? yes/no");
	rInput.openConsole();
	if (rInput.toBool())
	{	isGameOver = false;
		return true;
	}
	else
		return false;
}