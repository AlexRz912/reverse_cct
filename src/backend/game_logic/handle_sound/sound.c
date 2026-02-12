#include "sound.h"

#define PLAY_SOUND(filename) PlaySound("./sound/" filename, NULL, SND_ASYNC | SND_FILENAME)

void playNumber(int newNumber) {
    switch(newNumber) {
            case 1:
                PLAY_SOUND("1.wav"); 
                break;
            case 2:
                PLAY_SOUND("2.wav");
                break;
            case 3:
                PLAY_SOUND("3.wav"); 
                break;
            case 4:
                PLAY_SOUND("4.wav"); 
                break;
            case 5:
                PLAY_SOUND("5.wav");
                break;
            case 6:
                PLAY_SOUND("6.wav");
                break;
            case 7:
                PLAY_SOUND("7.wav");
                break;
            case 8:
                PLAY_SOUND("8.wav");
                break;
            case 9:
                PLAY_SOUND("9.wav");
                break;
            default:
                break;
        }
}