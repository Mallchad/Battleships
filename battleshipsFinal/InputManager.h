/*
 * GPL3 License
 * Copyright (c) 2021 Mallchad
 * This source provides the right to be freely used in any form, so long as modified
 * variations remain available publically, or open request.
 * Modified versions must be marked as such.
 * The source comes with no warranty of any kind.
 */

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <string>

class InputManager
{	
    bool isConsoleOnly;
    bool isConsoleEnabled;
    std::string userInput;
public:
    InputManager();
    void grabInput();
    void openConsole();
    void moveConsole();
    void resetConsolePosition();
    std::string get();
    int getCoord();
    bool toCoord();
    bool toBool();
    void toLower() noexcept;
    bool eval(char);
    char &operator[] (char);
    bool operator== (char);
    bool operator!= (char);
    char x, y;
};


#endif
