/*
 * GPL3 License
 * Copyright (c) 2021 Mallchad
 * This source provides the right to be freely used in any form, so long as modified
 * variations remain available publically, or open request.
 * Modified versions must be marked as such.
 * The source comes with no warranty of any kind.
*/

#include "GameManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "Player.h"
#include "mallib.h"
#include <iostream>

// ENTRY POINT
int main(int argc, char** argv)
{
    bool isRunning = true;

    Player Player1;
    Player Player2;
    DisplayManager MainDisplay;
    InputManager MainInput;
    GameManager MainGame(Player1,
                         Player2,
                         MainDisplay,
                         MainInput
        );
    MainGame.gameSetup();
    while(isRunning)
    {
        //New Game
        if (MainGame.isGameOver)
        {
            isRunning = MainGame .endGame();
            if (!MainGame.isGameOver)
            {
                MainGame.gameSetup();
            }
        }
        else
            MainGame.playerTurn();
    }
}
