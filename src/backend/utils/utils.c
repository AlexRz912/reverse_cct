#include "utils.h"

int getRand(int exclusiveMax, int offset) {
    return rand() % exclusiveMax + offset;
}

void clearInputBuffer() {
    while (_kbhit()) {
        _getch();
    }
}