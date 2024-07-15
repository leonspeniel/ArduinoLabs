#include "ScrollingText.h"

void setupScrollingText(LedControl& lc) {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

void loopScrollingText(LedControl& lc) {
    scrollText(lc, "HELLO ");
}

void scrollText(LedControl& lc, String text) {
    int len = text.length();
    for (int i = 0; i < len * 8; i++) {
        lc.clearDisplay(0);
        for (int j = 0; j < len; j++) {
            drawChar(lc, 8 * j - i, text.charAt(j));
        }
        delay(100);
    }
}

void drawChar(LedControl& lc, int x, char c) {
    byte data[8] = {0};
    byte character[8] = {
        0x7E, 0x81, 0x95, 0x81, 0x95, 0x81, 0x7E, 0x00  // 'A' as an example
    };
    for (int i = 0; i < 8; i++) {
        data[i] = character[i];
    }
    for (int i = 0; i < 8; i++) {
        if (x + i >= 0 && x + i < 8) {
            lc.setRow(0, x + i, data[i]);
        }
    }
}
