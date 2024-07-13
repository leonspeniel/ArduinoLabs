#include "Scroll.h"

bool scroll(const char* scrollText) {
  static uint8_t index = 0;
  uint8_t scrollLength = strlen(scrollText);

  // Display the scrolling text
  char displayBuffer[9];
  strncpy(displayBuffer, scrollText + index, 8);
  displayBuffer[8] = '\0';
  module.displayText(displayBuffer);

  // Update the index for the next loop
  index = ++index % (scrollLength - 7);
  return index == 0;
}
