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
	void grabInput();
	void openConsole();
	void moveConsole();
	void resetConsolePosition();
	std::string get();
	bool toCoord();
	bool toBool();
	bool eval(char);
	char &operator[] (char);
	bool operator== (char);
	char x, y;
};


#endif