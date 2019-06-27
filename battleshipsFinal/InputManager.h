#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "mallib.h"
#include <string>

class InputManager
{	
	bool isConsoleOnly;
	bool isConsoleEnabled;
	std::string userInput;
public:
	InputManager(bool consoleOnly = false);
	void grabConsoleInput();
	void openConsole();
	void moveConsole();
	void resetConsolePosition();
	std::string getUserInput();
	char x, y;
};


#endif