#include "DisplayManager.h"
#include "mallib.h"
#include <iostream>


//Constructor
DisplayManager::DisplayManager(bool windowOn)
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
		{	foo = mrd::arric(i, j, 10);
			foo = rPlayer.getShips(foo);
			switch (foo)
			{	case  ShipsID::Sea:
					std::cout << ' ';	
					break;
				case  ShipsID::Destroyer:
					std::cout << 'D';	
					break;
				case  ShipsID::Submarine:
					std::cout << 'S';	
					break;
				case  ShipsID::Cruiser:
					std::cout << 'C';	
					break;
				case  ShipsID::Battleship:
					std::cout << 'B';	
					break;
				case  ShipsID::Carrier:
					std::cout << 'A';
					break;
				case  ShipsID::Error:
					std::cout << '~';
					break;
				default:
					break;
					
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
	for (char i = 0; i<10; i++)
	{//Targeting Output
		if (i != 10)
			std::cout << ' ';
		std::cout << i+1;
		for (char j = 0; i<10; i++)
		{
			if (j<10)
			{//First Grid
				foo = mrd::arric(i, j, 10);
				foo = rPlayer.getShips(foo);
			}
			switch (foo)
			{
				case  TargetingID::Sea:
					std::cout << ' ';
					break;
				case  TargetingID::Hit:
					std::cout << 'X';
					break;
				case  TargetingID::Miss:
					std::cout << 'S';
					break;
				case  TargetingID::Error:
					std::cout << '~';
					break;
				default:
					break;
			}
		}
		std::cout << "\n";
	}
}
void DisplayManager::displayMessage(const char* message, float x, float y)
{	
	if (isWindowEnabled);
	else
	{
		std::cout << message << "/n";
	}
}