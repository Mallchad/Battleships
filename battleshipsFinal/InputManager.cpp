#include <iostream>
#include <string>
#include "InputManager.h"

InputManager::InputManager(bool consoleOnly)
{
	isConsoleOnly = consoleOnly;
	isConsoleEnabled = consoleOnly;
	x = -0;
	y = -0;
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
int InputManager::getCoord()
{
	return mrd::arric(x, y, 10);
}
bool InputManager::toCoord()
{
	if (userInput[0] >= 'a' && userInput[0] <= 'j')
		x = userInput[0] - 'a';
	else if (userInput[0] >= 'A' && userInput[0] <= 'J')
		x = userInput[0] - 'A';
	else
	{	//Invalid coordinate
		x = -1;
		y = -1;
		return false;
	}
	if (userInput[1] >= '1' && userInput[1] <= '9')
	{
		if (userInput[1] == '1' && userInput[2] == '0')
		{	//coordiante ends with 10
			y = 9;
		}
		//else
			y = userInput[1] - '1';
		return true;
	}//Invalid coordinate
	else
	{	x, y = -1;
		return false;
	}
}
bool InputManager::toBool()
{
	switch (userInput[0])
	{	case 't':
		case 'T':
		case 'y':
		case 'Y':
			return true;
		case 'f':
		case 'F':
		case 'n':
		case 'N':
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
bool InputManager::operator== (char value)
{	return (userInput[0] == value);
}
bool InputManager::operator!= (char value)
{	return (userInput[0] != value);
}