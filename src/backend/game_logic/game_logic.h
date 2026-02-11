#pragma once

#include "../data/constants.h"
#include "../data/structs.h"

void increaseInterval(struct Game * reverseCCT);
void decreaseInterval(struct Game * reverseCCT);

void getNextCCTNumber();
void addNextToPrevious();
void slideNumbers();

int streakReachedMax(int streak);
int isCorrectAnswer(int addition, int answer);
int userDidNotAnswer(int answer);
int increaseStreak(int streak);
int noGoSignalHappened(int randNum);