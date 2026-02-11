#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "inputs.h"

int captureInputDuringWait(int durationMs) {
    int elapsed = 0;
    int step = 10;
    
    // Si une réponse est déjà là, retourne le temps qu'on aurait dû attendre
    if (reverseCCTGame->answer != -1) return durationMs;

    while (elapsed < durationMs) {
        if (_kbhit()) {
            int key = _getch();
            
            if (key == 0 || key == 224) {
               if (_kbhit()) _getch(); 
               continue;
            }

            if (key >= '0' && key <= '9') {
                reverseCCTGame->answer = key - '0';
                // Retourne le temps restant dans cette période
                return durationMs - elapsed;
            }
        }
        Sleep(step);
        elapsed += step;
    }
    // Temps complètement écoulé, rien à attendre
    return 0;
}
