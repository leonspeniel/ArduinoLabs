#ifndef SCROLLINGTEXT_H
#define SCROLLINGTEXT_H

#include <LedControl.h>

// Function prototypes
void setupScrollingText(LedControl& lc);
void loopScrollingText(LedControl& lc);

void scrollText(LedControl& lc, String text);
void drawChar(LedControl& lc, int x, char c);

#endif
