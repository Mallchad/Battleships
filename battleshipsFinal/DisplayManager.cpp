#include "DisplayManager.h"
#include "mallib.h"
#include <iostream>


//Constructor
DisplayManager::DisplayManager(bool windowOn = false)
{
	isWindowEnabled = windowOn;
}
//Console Display
//Show player ships
void DisplayManager::cDisplayShips(Player& rPlayer)
{
	char foo;
	std::cout << "Your ships:"
			  << "  A B C D E F G H I"
			  << "\n";
	for (int i=0; i<10; i++)
	{	if (i != 10)
			std::cout << ' ';
		std::cout << i+1;
		for (int j=0; i<10; i++)
		{	foo = arric(i, j, 10);
			foo = rPlayer.getShips(foo);
			switch (foo)
			{	case Player::ShipsID::Sea:
					std::cout << ' ';	
					break;
				case Player::ShipsID::Destroyer:
					std::cout << 'D';	
					break;
				case Player::ShipsID::Submarine:
					std::cout << 'S';	
					break;
				case Player::ShipsID::Cruiser:
					std::cout << 'C';	
					break;
				case Player::ShipsID::Battleship:
					std::cout << 'B';	
					break;
				case Player::ShipsID::Carrier:
					std::cout << 'A';
					break;
				case Player::ShipsID::Error:
					std::cout << '~';
					break;
				default:
			}
		}
		std::cout << "\n";
	}
}
//Show Game Display
void DisplayManager::cDisplayGameView(Player& rPlayer)
{
	char foo;
	cDisplayShips(rPlayer);
	std::cout << "Your Targeting Panel:"
		<< "  A B C D E F G H I"
		<< "\n";
	for (int i = 0; i<10; i++)
	{//Targeting Output
		if (i != 10)
			std::cout << ' ';
		std::cout << i + 1;
		for (int j = 0; i<10; i++)
		{
			if (j<10)
			{//First Grid
				foo = arric(i, j, 10);
				foo = rPlayer.getShips(foo);
			}
			switch (foo)
			{
				case Player::TargetingID::Sea:
					std::cout << ' ';
					break;
				case Player::TargetingID::Hit:
					std::cout << 'X';
					break;
				case Player::TargetingID::Miss:
					std::cout << 'S';
					break;
				case Player::TargetingID::Error:
					std::cout << '~';
					break;
				default:
			}
		}
		std::cout << "\n";
	}
}
void DisplayManager::displayMessage(char* message, float x = 0, float y = 0)
{	
	if (isWindowEnabled);
	else
	{
		print(message);
	}
}

