#ifndef SCROLL_H
#define SCROLL_H

#include <TM1638lite.h>

// External module declaration
extern TM1638lite module;

bool scroll(const char* scrollText);

#endif // SCROLL_H
