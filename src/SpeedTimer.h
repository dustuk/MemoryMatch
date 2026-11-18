#pragma once

class SpeedTimer {
private:
    float score = 0.0f;
    float bestScore{};

    const char* path = "score.txt";
public:
    SpeedTimer() = default;

    void OpenScoreFile();

    void SaveScore();

    void ResetScore() {score = 0;}
    void ResetBestScore() const;
    float GetBestScore();

    void Update();
    void Draw() const;
};
