#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "inputs.h"

void captureInputDuringWait(int durationMs) {
    int elapsed = 0;
    int step = 10;
    
    if (reverseCCTGame->answer != -1) return;

    while (elapsed < durationMs) {
        if (_kbhit()) {
            int key = _getch();
            
            if (key == 0 || key == 224) {
               if (_kbhit()) _getch(); 
               continue;
            }

            if (key >= '0' && key <= '9') {
                reverseCCTGame->answer = key - '0';
                break; 
            }
        }
        Sleep(step);
        elapsed += step;
    }
}
