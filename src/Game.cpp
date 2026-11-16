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
        speedTimer.SaveScore();
        cardBoard.Restart();
        mainMenu.Restart();
    }
}

void Game::Run() {
    while (!WindowShouldClose()) {
        if (mainMenu.GetIsInMainMenu()) {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            mainMenu.Draw(speedTimer.GetBestScore());
            mainMenu.Update();
            EndDrawing();
        } else {
            speedTimer.Update();
            BeginDrawing();
            ClearBackground(DARKGRAY);
            cardBoard.Draw();
            cardBoard.Update();
            speedTimer.Draw();
            Restart();
            EndDrawing();
        }

    }
}
