#include "SpeedTimer.h"
#include "raygui.h"
#include <fstream>


void SpeedTimer::OpenScoreFile() {
    std::ifstream iFile(path);
    if (!iFile.is_open()) {
        std::ofstream oFile(path);
        oFile << score;
        oFile.close();
        bestScore = score;
    } else {
        iFile >> bestScore;
        iFile.close();
    }
}

void SpeedTimer::SaveScore() {
    OpenScoreFile();
    if (bestScore > score || bestScore == 0) {
        std::ofstream oFile(path);
        if (oFile.is_open()) {
            oFile << score;
            oFile.close();
        }
    }

}

void SpeedTimer::ResetBestScore() const {
    std::ofstream oFile(path);
    oFile << score;
    oFile.close();
}

float SpeedTimer::GetBestScore() {
    OpenScoreFile();
    return bestScore;
}

void SpeedTimer::Update() {
    float deltaTime = GetFrameTime();
    score += deltaTime;
}

void SpeedTimer::Draw() const {
    DrawText(TextFormat("Timer: %.2f", score), 0, 0, 40, YELLOW);
}
