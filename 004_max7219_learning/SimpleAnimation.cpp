#include "SimpleAnimation.h"

byte frames[4][8] = {
    {0x3C, 0x42, 0xA9, 0x85, 0x85, 0xA9, 0x42, 0x3C},
    {0x3C, 0x42, 0x91, 0xA5, 0xA5, 0x91, 0x42, 0x3C},
    {0x3C, 0x42, 0xA1, 0x95, 0x95, 0xA1, 0x42, 0x3C},
    {0x3C, 0x42, 0x89, 0xB5, 0xB5, 0x89, 0x42, 0x3C}
};

void setupSimpleAnimation(LedControl& lc) {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

void loopSimpleAnimation(LedControl& lc) {
    // Display each frame in sequence
    for (int i = 0; i < 4; i++) {
        displayFrame(lc, frames[i]);
        delay(200);
    }
}

void displayFrame(LedControl& lc, byte frame[8]) {
    for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, frame[i]);
    }
}
