#pragma once

#include <stdlib.h>
#include <stddef.h>

struct NoGoSignal {
    int chance;
    int rangeInterval;
};

struct Game {
    struct NoGoSignal noGo; 
    int previousNum; 
    int newNum; 
    int addition; 
    int answer; 
    int interval; 
    
}; 

extern struct Game * reverseCCTGame;

extern struct Game * reverseCCTGame;

void initGame();
int isAllocFailing();
void getGame(int startInterval, int lowerInterval);