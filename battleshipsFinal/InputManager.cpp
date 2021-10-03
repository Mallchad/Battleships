/*
 * GPL3 License
 * Copyright (c) 2021 Mallchad
 * This source provides the right to be freely used in any form, so long as modified
 * variations remain available publically, or open request.
 * Modified versions must be marked as such.
 * The source comes with no warranty of any kind.
*/

#include <iostream>
#include <string>
#include "InputManager.h"
#include "DisplayManager.h"
#include "mallib.h"
#include <ncurses.h>

InputManager::InputManager()
{
    x = -0;
    y = -0;
}
void InputManager::grabInput()
{
    DisplayManager::flush();

    char tmp[100] = {};
    getstr(tmp);
    userInput = tmp;
}
std::string InputManager::get()
{
    return userInput;
}
void InputManager::openConsole()
{
    grabInput();
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
    {
        x = userInput[0] - 'a';
    }
    else if (userInput[0] >= 'A' && userInput[0] <= 'J')
    {
        x = userInput[0] - 'A';
    }
    else
    {	//Invalid coordinate
        x = -1;
        y = -1;
        return false;
    }
    if (userInput[1] >= '1' && userInput[1] <= '9')
    {
        if (userInput[1] == '1' && userInput[2] == '0')
        {//coordiante ends with 10
            y = 9;
        }
        else
        {
            y = userInput[1] - '1';
        }
        return true;
    }//Invalid coordinate
    else
    {
        x, y = -1;
        return false;
    }
}
bool InputManager::toBool()
{
    switch (userInput[0])
    {
        case 't':
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
{
    return (userInput[0] == value);
}
bool InputManager::operator!= (char value)
{
    return (userInput[0] != value);
}
