/*
 * GPL3 License
 * Copyright (c) 2021 Mallchad
 * This source provides the right to be freely used in any form, so long as modified
 * variations remain available publically, or open request.
 * Modified versions must be marked as such.
 * The source comes with no warranty of any kind.
*/

#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#include "Player.h"
#include <string>
//Handles Monitor Output
class DisplayManager
{

public:
    DisplayManager(bool windowOn = true);
    bool isWindowEnabled;
    //Console Display
    void displayMessage(const char* message, float x = 0.f, float y = 0.f);
    void cDisplayShips(Player&);
    void cDisplayTargeting(Player&);
    void cDisplayGameView(Player& rPlayer);
};


#endif
