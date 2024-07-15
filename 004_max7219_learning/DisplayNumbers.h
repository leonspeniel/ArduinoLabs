#ifndef DISPLAYNUMBERS_H
#define DISPLAYNUMBERS_H

#include <LedControl.h>

// Function prototypes
void setupDisplayNumbers(LedControl& lc);
void loopDisplayNumbers(LedControl& lc);

void displayNumber(LedControl& lc, int num);

#endif
