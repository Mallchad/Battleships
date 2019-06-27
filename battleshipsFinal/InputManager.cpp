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