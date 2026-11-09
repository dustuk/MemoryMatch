#include "Game.h"


Game::Game(int width, int height, const char* title) {
    InitWindow(width, height, title);
    SetTargetFPS(60);
}

Game::~Game() {
    CloseWindow();
}

void Game::Restart() {
    if (cardBoard.IsAllMatched()) {
        cardBoard.Restart();
        mainMenu.Restart();
    }
}

void Game::Run() {
    while (!WindowShouldClose()) {
        if (mainMenu.GetIsInMainMenu()) {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            mainMenu.Draw();
            mainMenu.Update();
            EndDrawing();
        } else {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            cardBoard.Draw();
            cardBoard.Update();
            Restart();
            EndDrawing();
        }

    }
}
