#pragma once
#include "CardBoard.h"
#include "MainMenu.h"


class Game {
private:
    CardBoard cardBoard;
    MainMenu mainMenu;
public:
    Game(int width, int height, const char* title);
    ~Game();

    void Restart();

    void Run();
};
