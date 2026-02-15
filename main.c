#include <windows.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>

#include "./src/backend/data/constants.h"
#include "./src/backend/data/structs.h"
#include "./src/backend/game_logic/game_logic.h"
#include "./src/backend/utils/utils.h"
#include "./src/backend/game_logic/handle_sound/sound.h"
#include "./src/backend/game_logic/handle_inputs/inputs.h"


int main() {
    srand(time(NULL));

    int startIntervalMs = MAX_CCT_INTERVAL_MS;
    int minIntervalMs = MIN_CCT_INTERVAL_MS;

    initGame();
    if (isAllocFailing()) {
        printf("program failure");
        return 1;
    }

    getGame(startIntervalMs, minIntervalMs);

    int previousAnswerCorrect = 1;
    int validStreak = 0;
    int errorStreak = 0;

    while(1) 
    {
        if (previousAnswerCorrect) { printf("correct answer\n"); }
        else { printf("wrong answer\n"); }
        if (streakReachedMax(errorStreak)) 
        {
            errorStreak = 0;
            increaseInterval(reverseCCTGame);
        }

        if (streakReachedMax(validStreak)) 
        {
            validStreak = 0;
            decreaseInterval(reverseCCTGame);
        }

        getNextCCTNumber();
        addNextToPrevious();
        
        int noGoSignal = getRand(4, 0);
        //clearInputBuffer();
        
        playNumber(reverseCCTGame->newNum);
        
        reverseCCTGame->answer = -1;
        if (noGoSignal == 3) {
            
            int nogoTimeBeforeEnd = getRand(MAX_NOGO_SIGNAL, MIN_NOGO_SIGNAL);
            
            int timeBeforeSignal = reverseCCTGame->interval - nogoTimeBeforeEnd;
            
            if (timeBeforeSignal < 0) timeBeforeSignal = 0; 
            
            Sleep(timeBeforeSignal);
            captureInputDuringSleep();
            
            playNoGoSound();

            Sleep(nogoTimeBeforeEnd);            
            captureInputDuringSleep();
        } else {
            
            Sleep(reverseCCTGame->interval);
            captureInputDuringSleep();
        }
        slideNumbers();
        if ((!noGoSignalHappened(noGoSignal) && isCorrectAnswer((reverseCCTGame->addition % 10), reverseCCTGame->answer)) || 
           (noGoSignalHappened(noGoSignal) && userDidNotAnswer(reverseCCTGame->answer)))
        {
            previousAnswerCorrect = 1;
            validStreak = increaseStreak(validStreak);
            errorStreak = 0;
        } else {
            previousAnswerCorrect = 0;
            errorStreak = increaseStreak(errorStreak);
            validStreak = 0;
        }
        system("cls");
    }
    free(reverseCCTGame);
    return 0;
}
