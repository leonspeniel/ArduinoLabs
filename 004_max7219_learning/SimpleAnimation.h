#ifndef SIMPLEANIMATION_H
#define SIMPLEANIMATION_H

#include <LedControl.h>

// Function prototypes
void setupSimpleAnimation(LedControl& lc);
void loopSimpleAnimation(LedControl& lc);

void displayFrame(LedControl& lc, byte frame[8]);

#endif
