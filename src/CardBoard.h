#pragma once
#include <vector>
#include <random>
#include "raylib.h"

class CardBoard {
private:
    int firstSelectedCard = -1;
    int secondSelectedCard = -1;

    float timer = 0.0f;
    const float waitDuration = 1.0f;

    std::random_device rd;
    std::mt19937 rng;

    struct Card {
        int number{};
        mutable bool isMatched = false;
        mutable bool isFlipped = false;
    };

    std::vector<Card> cards = {
        {1}, {2}, {3},
        {4}, {5}, {6},
        {1}, {2}, {3},
        {4}, {5}, {6}
    };



    [[nodiscard]] static Rectangle GetCardRect(int index) {
        const int col = index % 4;
        const int row = index / 4;

        return {
            .x = 285.0f + static_cast<float>(col) * 55.0f,
            .y = 125.0f + static_cast<float>(row) * 105.0f,
            .width = 50.0f,
            .height = 100.0f
        };
    }



public:
    CardBoard();

    void DrawCardFace(Rectangle rect, int index) const;
    void CardStatus(Rectangle rect, int index);

    [[nodiscard]] bool IsAllMatched() const;

    void Restart();

    void Draw();
    void Update();
};
