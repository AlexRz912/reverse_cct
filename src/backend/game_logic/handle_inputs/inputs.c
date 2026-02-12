#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "inputs.h"

void captureInputDuringSleep() {

    if (_kbhit()) {
        int key = _getch();
        if (key >= '0' && key <= '9') {
            reverseCCTGame->answer = key - '0';
        }
    }
    // Temps complètement écoulé, rien à attendre
}