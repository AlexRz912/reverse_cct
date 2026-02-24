#include "structs.h"

struct Game * reverseCCTGame = NULL;


void initGame() {
    reverseCCTGame = malloc(sizeof(struct Game));
}

int isAllocFailing() {
    if (reverseCCTGame == NULL) {
        return 1;
    }
    return 0;
}

void getGame(int startInterval, int lowerInterval) {
    reverseCCTGame->interval = startInterval;
    reverseCCTGame->previousNum = 0;
}

void resetData(struct Game * reverseCCT) {
    free(reverseCCT);
}