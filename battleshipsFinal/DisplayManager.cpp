/*
 * GPL3 License
 * Copyright (c) 2021 Mallchad
 * This source provides the right to be freely used in any form, so long as modified
 * variations remain available publically, or open request.
 * Modified versions must be marked as such.
 * The source comes with no warranty of any kind.
*/

#include "DisplayManager.h"
#include "mallib.h"
#include <sstream>
#include <platform.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std::string_literals;

#ifdef BATTLESHIPS_CURSES_COMPATIBLE
namespace curses
{
#include <ncurses.h>
}
#endif

DisplayManager DisplayManager::self = {};
std::stringbuf DisplayManager::coutRedirect = {};

// Constructor
DisplayManager::DisplayManager() noexcept
{
    std::cout.rdbuf(&coutRedirect);
#if BATTLESHIPS_CURSES_COMPATIBLE
    // Initialize Curses
    curses::initscr();
    curses::refresh();
#else
    // Fallback to normal system commands
    system("clear");
#endif
}
// Show player ships
void DisplayManager::cDisplayShips(Player& rPlayer)
{
    char foo;
    std::cout << "Your ships:  \n"
              << "  A B C D E F G H I J \n";
    for (int i = 0; i < 10; i++)
    {
        if (i != 9)
            std::cout << ' ';
        std::cout << i + 1;
        for (int j = 0; j < 10; j++)
        {
            foo = mrd::arric(j, i, 10);
            foo = rPlayer.getShips(foo);
            switch (foo)
            {
            case ShipID::Sea:
                std::cout << " ";
                break;
            case ShipID::Destroyer:
                std::cout << 'D';
                break;
            case ShipID::Submarine:
                std::cout << 'S';
                break;
            case ShipID::Cruiser:
                std::cout << 'C';
                break;
            case ShipID::Battleship:
                std::cout << 'B';
                break;
            case ShipID::Carrier:
                std::cout << 'A';
                break;
            case ShipID::Wreck:
                std::cout << '~';
                break;
            case ShipID::Error:
                std::cout << '?';
                break;
            }
            std::cout << ' ';
        }
        std::cout << " \n";
    }
}
void DisplayManager::cDisplayTargeting(Player& rPlayer)
{
    char foo;
    std::cout << "Your Targeting Panel: \n"
              << "  A B C D E F G H I J \n";
    for (char i = 0; i < 10; i++)
    { // Targeting Output
        if (i != 10)
            std::cout << ' ';
        std::cout << i + 1;
        for (char j = 0; j < 10; j++)
        {
            foo = mrd::arric(j, i, 10);
            foo = rPlayer.getTargeting(foo);
            switch (foo) {
            case TargetingID::Sea:
                std::cout << ' ';
                break;
            case TargetingID::Hit:
                std::cout << 'X';
                break;
            case TargetingID::Miss:
                std::cout << 'S';
                break;
            case TargetingID::Error:
                std::cout << '?';
                break;
            }
            std::cout << ' ';
        }
        std::cout << " \n";
    }
}
// Show Game Display
void DisplayManager::cDisplayGameView(Player& rPlayer)
{
    cDisplayShips(rPlayer);
    cDisplayTargeting(rPlayer);
}
void DisplayManager::displayMessage(const char* message, float x, float y)
{
    std::cout << message << " \n";
}
void DisplayManager::clearScreen() noexcept
{
    clearRedirectStream();
#if BATTLESHIPS_CURSES_COMPATIBLE
    // Important, keep contents fresh and consistent for repaint
    curses::erase();
#else
    system("clear");
#endif
}
void DisplayManager::flush() noexcept
{
    // Very important, null terminate the buffer each time
    std::cout.put('\0');
    std::string tmp = self.coutRedirect.str();

#if BATTLESHIPS_CURSES_COMPATIBLE
    curses::printw("%s", tmp.c_str());
    curses::refresh();
#else
    printf("%s", tmp.c_str());
#endif
    clearRedirectStream();
}
void DisplayManager::clearRedirectStream() noexcept
{
    // Clear the stream buffer
    self.coutRedirect.pubseekpos(0);
}
DisplayManager::~DisplayManager() noexcept
{
#ifdef BATTLESHIPS_CURSES_COMPATIBLE
    // Curses Cleanup
    curses::endwin();
#endif
}
