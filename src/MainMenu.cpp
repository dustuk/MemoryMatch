#include "MainMenu.h"

bool MainMenu::ShouldRestScore() const {
    if (GuiButton(rect2, "RestScore")) {
        return true;
    }
    return false;
}

void MainMenu::Update() {
    if (GuiButton(rect1, "Start")) {
        isInMainMenu = false;
    }
}

void MainMenu::Draw(float bestScore) {
    GuiSetStyle(BUTTON, BORDER_WIDTH, 2);
    GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(WHITE));
    GuiSetStyle(DEFAULT, TEXT_SIZE, 32);


    DrawText(TextFormat("best time: %.2f", bestScore), 250.0f, 180.0f, 40, YELLOW);
}
