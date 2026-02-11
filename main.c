#include <windows.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>

#include "./src/backend/data/constants.h"
#include "./src/backend/data/structs.h"
#include "./src/backend/game_logic/game_logic.h"
#include "./src/backend/utils/utils.h"

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

    int stimuliCount = 0;
    int validStreak = 0;
    int errorStreak = 0;

    while(1) 
    {
        int timeLeft = 0;
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
        
        printf("previous: %d\n", reverseCCTGame->previousNum);
        printf("next: %d\n", reverseCCTGame->newNum);
        
        // Réinitialisation de la réponse avant le début de l'intervalle
        reverseCCTGame->answer = -1;
        if (noGoSignal == 3) {
            
            int nogoTimeBeforeEnd = getRand(MAX_NOGO_SIGNAL, MIN_NOGO_SIGNAL);
            
            int timeBeforeSignal = reverseCCTGame->interval - nogoTimeBeforeEnd;
            
            if (timeBeforeSignal < 0) timeBeforeSignal = 0; 
            
            
            timeLeft = captureInputDuringWait(timeBeforeSignal);
            
            // Affiche DON'T
            printf("DON'T\n");
            
            // Partie 2 : Attente restante
            timeLeft += captureInputDuringWait(nogoTimeBeforeEnd);
        } else {
            // Pas de signal, attente complète
            timeLeft = captureInputDuringWait(reverseCCTGame->interval);
        }
    
        slideNumbers();
        
        // Gestion de l'unité uniquement si addition >= 10
        if (reverseCCTGame->addition >= 10 && reverseCCTGame->answer != -1) {
             // Si l'utilisateur a répondu X et que la somme est 1X, on considère X comme 1X
             // Par exemple somme 15, réponse 5 => 15
             if (reverseCCTGame->answer == (reverseCCTGame->addition % 10)) {
                 reverseCCTGame->answer += 10;
             }
        }
        
        if ((!noGoSignalHappened(noGoSignal) && isCorrectAnswer(reverseCCTGame->addition, reverseCCTGame->answer)) || 
           (noGoSignalHappened(noGoSignal) && userDidNotAnswer(reverseCCTGame->answer)))
        {
            printf("correct answer\n");
            validStreak = increaseStreak(validStreak);
            errorStreak = 0;
        } else {
            errorStreak = increaseStreak(errorStreak);
            validStreak = 0;
        }
        Sleep(timeLeft);
        system("cls");
        
    }
    free(reverseCCTGame);
    return 0;
}
