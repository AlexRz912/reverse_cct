#include "game_logic.h"
#include "../utils/utils.h"

void increaseInterval(struct Game * reverseCCT) {
    if (reverseCCT->interval >= MAX_CCT_INTERVAL_MS) {
        return;
    }
    reverseCCT->interval += 100;
}

void decreaseInterval(struct Game * reverseCCT) {
    if (reverseCCT->interval <= MIN_CCT_INTERVAL_MS) {
        return;
    }
    reverseCCT->interval -= 100;
}

int streakReachedMax(int streak) {
    return (streak == MAX_STREAK_COUNT);
}

void getNextCCTNumber() {
    reverseCCTGame->newNum = getRand(9, 1);
}

void addNextToPrevious() {
    reverseCCTGame->addition = reverseCCTGame->previousNum + reverseCCTGame->newNum;
}

void slideNumbers() {
    reverseCCTGame->previousNum = reverseCCTGame->newNum;
}

int isCorrectAnswer(int addition, int answer) {
    return (addition == answer);
}

int userDidNotAnswer(int answer) {
    return answer == -1;
}

int increaseStreak(int streak) {
    return ++streak;
}

int noGoSignalHappened(int randNum) {
    return randNum == 3;
}