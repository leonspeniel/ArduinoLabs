#ifndef ALLLEDLOGICS_H
#define ALLLEDLOGICS_H

#include <TM1638lite.h>

// External module declaration
extern TM1638lite module;

#define COUNTING_MODE 0
#define SCROLL_MODE 1
#define BUTTON_MODE 2

void allLedLogics();
bool counting();
void buttons();

#endif // ALLLEDLOGICS_H
