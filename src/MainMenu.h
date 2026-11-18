#pragma once
#include "raygui.h"


class MainMenu {
private:
    bool isInMainMenu = true;

    Rectangle rect1 {
        300.0f,
        250.0f,
        200.0f,
        75.0f
    };

    Rectangle rect2 = {
        300.0f,
        330.0f,
        200.0f,
        75.0f
    };
public:
    MainMenu() = default;

    [[nodiscard]] bool GetIsInMainMenu() const {return isInMainMenu;}

    void Restart() {isInMainMenu = true;}

    [[nodiscard]] bool ShouldRestScore() const;

    void Update();

    static void Draw(float bestScore);
};
