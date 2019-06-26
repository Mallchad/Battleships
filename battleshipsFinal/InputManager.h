#pragma once
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "mallib.h"
#include <string>

class InputManager
{	
	bool isConsoleEnabled;
	std::string mUserInput;
public:
	void grabConsoleInput();
	std::string getUserInput();
	char x, y;
};


#endif