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
	std::cout << "Your ships:  \n"
			  << "  A B C D E F G H I J \n";
	for (int i=0; i<10; i++)
	{	if (i != 9)
			std::cout << ' ';
		std::cout << i+1;
		for (int j=0; j<10; j++)
		{	foo = mrd::arric(j, i, 10);
			foo = rPlayer.getShips(foo);
			switch (foo)
			{	case  ShipID::Sea:
					std::cout << " ";	
					break;
				case  ShipID::Destroyer:
					std::cout << 'D';	
					break;
				case  ShipID::Submarine:
					std::cout << 'S';	
					break;
				case  ShipID::Cruiser:
					std::cout << 'C';	
					break;
				case  ShipID::Battleship:
					std::cout << 'B';	
					break;
				case  ShipID::Carrier:
					std::cout << 'A';
					break;
				case  ShipID::Error:
					std::cout << '~';
					break;
				default:
					std::cout << '?';
					break;
			}
			std::cout << ' ';
		}
		std::cout << " \n";
	}
}
//Show Game Display
void DisplayManager::cDisplayGameView(Player& rPlayer)
{
	char foo;
	cDisplayShips(rPlayer);
	std::cout << "Your Targeting Panel: \n"
			  << "  A B C D E F G H I J \n";
	for (char i = 0; i<10; i++)
	{//Targeting Output
		if (i != 10)
			std::cout << ' ';
		std::cout << i+1;
		for (char j = 0; j<10; j++)
		{
			foo = mrd::arric(j, i, 10);
			foo = foo = rPlayer.getTargeting(foo);
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
			std::cout << ' ';
		}
		std::cout << " \n";
	}
}
void DisplayManager::displayMessage(const char* message, float x, float y)
{	
	if (isWindowEnabled);
	else
	{
		std::cout << message << " \n";
	}
}