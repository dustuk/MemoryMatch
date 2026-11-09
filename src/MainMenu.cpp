#include "MainMenu.h"

void MainMenu::Update() {
    if (GuiButton(rect, "Start")) {
        isInMainMenu = false;
    }
}

void MainMenu::Draw() {
    GuiSetStyle(BUTTON, BORDER_WIDTH, 2);
    GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(WHITE));
    GuiSetStyle(DEFAULT, TEXT_SIZE, 40);
}
