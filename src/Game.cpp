#include "Game.h"


Game::Game(int width, int height, const char* title) {
    InitWindow(width, height, title);
    SetTargetFPS(60);
}

Game::~Game() {
    CloseWindow();
}

void Game::ResetScore() {
    if (mainMenu.ShouldRestScore()) {
        speedTimer.ResetScore();
        speedTimer.ResetBestScore();
    }
}

void Game::Restart() {
    if (cardBoard.IsAllMatched()) {
        speedTimer.SaveScore();
        speedTimer.ResetScore();
        cardBoard.Restart();
        mainMenu.Restart();
    }
}

void Game::Run() {
    while (!WindowShouldClose()) {
        if (mainMenu.GetIsInMainMenu()) {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            MainMenu::Draw(speedTimer.GetBestScore());
            mainMenu.Update();
            ResetScore();
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
