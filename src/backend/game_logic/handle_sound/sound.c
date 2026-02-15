#include "sound.h"

#define PLAY_DIGIT_SOUND(filename) PlaySound("./sounds/digits/" filename, NULL, SND_ASYNC | SND_FILENAME)
#define PLAY_NOGO_SOUND(filename) PlaySound("./sounds/" filename, NULL, SND_ASYNC | SND_FILENAME)

void playNumber(int newNumber) {
    switch(newNumber) {
            case 1:
                PLAY_DIGIT_SOUND("1.wav"); 
                break;
            case 2:
                PLAY_DIGIT_SOUND("2.wav");
                break;
            case 3:
                PLAY_DIGIT_SOUND("3.wav"); 
                break;
            case 4:
                PLAY_DIGIT_SOUND("4.wav"); 
                break;
            case 5:
                PLAY_DIGIT_SOUND("5.wav");
                break;
            case 6:
                PLAY_DIGIT_SOUND("6.wav");
                break;
            case 7:
                PLAY_DIGIT_SOUND("7.wav");
                break;
            case 8:
                PLAY_DIGIT_SOUND("8.wav");
                break;
            case 9:
                PLAY_DIGIT_SOUND("9.wav");
                break;
            default:
                break;
        }
}

void playNoGoSound() {
    PLAY_NOGO_SOUND("nogosignal"); 
}