/*
 * GPL3 License
 * Copyright (c) 2021 Mallchad
 * This source provides the right to be freely used in any form, so long as modified
 * variations remain available publically, or open request.
 * Modified versions must be marked as such.
 * The source comes with no warranty of any kind.
 */

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <string>
#include "mallib.h"
#include "Player.h"
#include "DisplayManager.h"
#include "InputManager.h"

class GameManager
{
    Player& rPlayer1;
    Player& rPlayer2;
    DisplayManager& rDisplay;
    InputManager& rInput;
    bool isPlayer1First;
    bool isPlayer1Turn;
    bool isInputValid;
    char turnCount;
    char victor = 0;
public:
    bool isGameOver;
    GameManager(Player& rPlayer1, Player& rPlayer2, DisplayManager&, InputManager&);
    void setupShips(Player&);
    void gameSetup();
    bool coinToss();
    void playerTurn();
    bool endGame();
};

#endif
