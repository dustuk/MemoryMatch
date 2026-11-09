#pragma once
#include "raygui.h"


class MainMenu {
private:
    bool isInMainMenu = true;

    Rectangle rect = {
        300.0f,
        250.0f,
        200.0f,
        75.0f
    };
public:
    MainMenu() = default;

    [[nodiscard]] bool GetIsInMainMenu() const {return isInMainMenu;}

    void Restart() {isInMainMenu = true;}

    void Update();
    void Draw();
};
