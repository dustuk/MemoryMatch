#include "CardBoard.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <algorithm>

CardBoard::CardBoard() : rng(rd()) {
    std::shuffle(cards.begin(), cards.end(), rng);
}

void CardBoard::DrawCardFace(Rectangle rect, int index) const {
    int originalColor = GuiGetStyle(BUTTON, BASE_COLOR_NORMAL);
    int originalFocusedColor = GuiGetStyle(BUTTON, BASE_COLOR_FOCUSED);

    Color color = cards[index].isMatched ? GREEN : YELLOW;
    Color focusedColor = cards[index].isMatched ? LIME : GOLD;

    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(color));
    GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, ColorToInt(focusedColor));

    GuiButton(rect, TextFormat("%i", cards[index].number));

    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, originalColor);
    GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, originalFocusedColor);
}


void CardBoard::CardStatus(Rectangle rect, int index) {
    if (!cards[index].isFlipped) {
        if (GuiButton(rect, "?") && secondSelectedCard == -1) {
            if (firstSelectedCard == -1) {
                firstSelectedCard = index;
            } else if (secondSelectedCard == -1) {
                secondSelectedCard = index;
            }
            cards[index].isFlipped = true;
        }
    } else {
        DrawCardFace(rect, index);
    }
}

bool CardBoard::IsAllMatched() const {
    int sumOfMatchedCards = 0;
    for (const auto& card : cards) {
        if (card.isMatched) {
            sumOfMatchedCards++;
        }
    }

    if (sumOfMatchedCards >= cards.size()) {
        return true;
    }
    return false;
}

void CardBoard::Restart() {
    for (const auto& card : cards) {
        card.isFlipped = false;
        card.isMatched = false;
    }

    std::shuffle(cards.begin(), cards.end(), rng);
    firstSelectedCard = -1;
    secondSelectedCard = -1;
    timer = 0.0f;
}

void CardBoard::Draw() {
    GuiSetStyle(BUTTON, BORDER_WIDTH, 2);
    GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(WHITE));
    GuiSetStyle(DEFAULT, TEXT_SIZE, 40);

    for (int i = 0; i < cards.size(); i++) {
        Rectangle rect = GetCardRect(i);

        CardStatus(rect, i);
    }
}

void CardBoard::Update() {
    if (firstSelectedCard != -1 && secondSelectedCard != -1) {
        Card& firstCard = cards[firstSelectedCard];
        Card& secondCard = cards[secondSelectedCard];
        float deltaTime = GetFrameTime();
        timer += deltaTime;

        if (timer >= waitDuration) {
            if (firstCard.number == secondCard.number) {
                firstCard.isMatched = true;
                secondCard.isMatched = true;
            } else {
                firstCard.isFlipped = false;
                secondCard.isFlipped = false;

            }

            firstSelectedCard = -1;
            secondSelectedCard = -1;

            timer = 0;
        }
    }
}