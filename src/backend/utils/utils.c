#include "utils.h"

int getRand(int exclusiveMax, int offset) {
    return rand() % exclusiveMax + offset;
}