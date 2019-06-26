#include "GameManager.h"
#include "Player.h"
GameManager(Player& Player1, Player& Player2, DisplayManager& CurrentDisplay, InputManager& CurrentInput)
{

}
void GameManager::playerTurn()
{

}
void GameManager::setupShips(Player& Player1, bool rand = false)
{
	
}
bool GameManager::coinToss()
{
	char userInput = 0;
	bool coinSide;
	coinSide = rand() % 2;
	("A coin has been flipped");
	do
	{//Until input valid
		print("Heads or Tails? heads/tails");
		cin >> userInput;
	} while (userInput != 'h' && userInput != 't');
	if (coinSide)
	{//Heads
		if (userInput == 'h')
			return true;
		if (userInput == 't')
			return true;
	}
}