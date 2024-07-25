#include <iostream>
#include "BowlingScores.h"

void setArrays(int rolls[], int frameScores[]) {
    for (int i = 0; i < MAXROLLS; i++) {
        rolls[i] = 0;
    }
    for (int i = 0; i < MAXFRAMES; i++) {
        frameScores[i] = 0;
    }
}

int calculateFrameScore(int rolls[], int frame) {
    if (rolls[frame * 2] == 10) {
        return 10 + rolls[frame * 2 + 2] + rolls[frame * 2 + 3];
    }
    else if (rolls[frame * 2] + rolls[frame * 2 + 1] == 10) {
        return 10 + rolls[frame * 2 + 2];
    }
    else {
        return rolls[frame * 2] + rolls[frame * 2 + 1];
    }
}

void calculateScores(int rolls[], int frameScores[], int currentFrame) {
    int totalScore = 0;
    for (int i = 0; i < currentFrame; i++) {
        if (i < 9) {
            totalScore += calculateFrameScore(rolls, i);
        }
        else {
            totalScore += rolls[i * 2] + rolls[i * 2 + 1] + rolls[i * 2 + 2];
        }
        frameScores[i] = totalScore;
    }
}

void printScores(int rolls[], int frameScores[], int currentFrame) {
    std::cout << "Frame#:    ";
    for (int i = 1; i <= 10; i++) {
        std::cout << i << "     ";
    }
    std::cout << std::endl;

    std::cout << "Throws:   ";
    for (int i = 0; i < currentFrame; i++) {
        if (i < 9) {
            if (rolls[i * 2] == 10) {
                std::cout << "X   ";
            }
            else if (rolls[i * 2] + rolls[i * 2 + 1] == 10) {
                std::cout << rolls[i * 2] << "/" << "   ";
            }
            else {
                std::cout << rolls[i * 2] << " " << rolls[i * 2 + 1] << "   ";
            }
        }
        else {
            if (rolls[i * 2] == 10) {
                std::cout << "X ";
            }
            else {
                std::cout << rolls[i * 2] << " ";
            }
            if (rolls[i * 2 + 1] == 10) {
                std::cout << "X ";
            }
            else {
                std::cout << rolls[i * 2 + 1] << " ";
            }
            if (rolls[i * 2 + 2] == 10) {
                std::cout << "X ";
            }
            else {
                std::cout << rolls[i * 2 + 2] << " ";
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Scores:    ";
    for (int i = 0; i < currentFrame; i++) {
        std::cout << frameScores[i] << "    ";
    }
    std::cout << std::endl;
}

int main() {
    int rolls[MAXROLLS];
    int frameScores[MAXFRAMES];

    setArrays(rolls, frameScores);

    for (int i = 0; i < 10; i++) {
        std::cout << "Turn Frame " << i + 1 << std::endl;
        std::cout << "1st Throw: ";
        std::cin >> rolls[i * 2];
        if (rolls[i * 2] != 10) {
            std::cout << "2nd Throw: ";
            std::cin >> rolls[i * 2 + 1];
        }
        else {
            rolls[i * 2 + 1] = 0;
        }
        if (i == 9) {
            std::cout << "3rd Throw: ";
            std::cin >> rolls[i * 2 + 2];
        }

        calculateScores(rolls, frameScores, i + 1);
        printScores(rolls, frameScores, i + 1);
    }

    return 0;
}