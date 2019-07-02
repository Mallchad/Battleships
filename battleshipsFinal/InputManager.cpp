#include <iostream>
#include <string>
#include "InputManager.h"

InputManager::InputManager(bool consoleOnly)
{
	isConsoleOnly = consoleOnly;
	isConsoleEnabled = consoleOnly;
	x = 0;
	y = 0;
}
void InputManager::grabConsoleInput()
{	if (isConsoleOnly)
		std::cin >> userInput;
	else;
}
std::string InputManager::getUserInput()
{
	return userInput;
}
void InputManager::openConsole()
{	
	if (isConsoleOnly)
		grabConsoleInput();
	else;

}
void InputManager::moveConsole()
{

}
void InputManager::resetConsolePosition()
{
	x = 0;
	y = 0;
}
bool InputManager::inputToCoord()
{
	if (userInput[0] >= 'a' && userInput[0] <= 'j')
		x = userInput[0] - 'a';
	else if (userInput[0] >= 'A' && userInput[0] <= 'J')
		x = userInput[0] - 'A';
	else
		//Invalid coordinate
		return false;
	if (userInput[1] >= '1' && userInput[1] <= '9')
	{
		if (userInput[1] == '1' && userInput[2] == '0')
			//coords ends with 10
			y = 9;
		else
			y = userInput[1] - '1';
		return true;
	}//Invalid coordinate
	else
		return false;
}
char &InputManager::operator[] (char index)
{
	return (userInput[index]);
}