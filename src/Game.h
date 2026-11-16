#pragma once
#include "CardBoard.h"
#include "MainMenu.h"
#include "SpeedTimer.h"

class Game {
private:
    CardBoard cardBoard;
    MainMenu mainMenu;
    SpeedTimer speedTimer;
public:
    Game(int width, int height, const char* title);
    ~Game();

    void Restart();

    void Run();
};
