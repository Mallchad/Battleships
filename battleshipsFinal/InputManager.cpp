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
void InputManager::grabInput()
{
	if (isConsoleOnly)
		std::cin >> userInput;
	else;
}
std::string InputManager::get()
{
	return userInput;
}
void InputManager::openConsole()
{	
	if (isConsoleOnly)
		grabInput();
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
bool InputManager::toCoord()
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
bool InputManager::toBool()
{
	switch (userInput[0])
	{	case 't':
		case 'y':
		case 'h':
			return true;
		case 'f':
		case 'n':
		case 'v':
		case '0':
			return false;
		default:
			if (userInput[0] >= '1' && userInput[0] <= '9')
				return true;
			

	}
}
bool InputManager::eval(char equivlentTo)
{
	return (userInput[0] == equivlentTo);
}
char &InputManager::operator[] (char index)
{
	return (userInput[index]);
}
bool InputManager::operator== (char equivlentTo)
{	return (userInput[0] == equivlentTo);
}