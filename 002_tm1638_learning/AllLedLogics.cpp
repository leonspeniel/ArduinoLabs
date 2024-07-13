#include "AllLedLogics.h"
#include "Scroll.h" // Include the Scroll header file

void allLedLogics() {
  static uint8_t mode = COUNTING_MODE;
  switch (mode) {
    case COUNTING_MODE:
      mode += counting();
      delay(500);
      break;
    case SCROLL_MODE:
      mode += scroll("   HELLO WORLD     ");
      break;
    case BUTTON_MODE:
      buttons();
      break;
  }
  delay(200);
}

bool counting() {
  // 0 to 9 digits
  const char* digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  static uint8_t digit = 0;

  // Display the current digit
  char displayBuffer[9];
  for (int i = 0; i < 8; i++) {
    displayBuffer[i] = digits[digit][0];
  }
  displayBuffer[8] = '\0';
  module.displayText(displayBuffer);

  // Update the digit for the next loop
  digit = ++digit % 10;
  return digit == 0;
}

void buttons() {
  const char* promptText = "PRESS      BUTTONS    ";
  static uint8_t block = 0;
  uint8_t textStartPos = (block / 4) * 8;

  // Display the prompt text
  char displayBuffer[9];
  strncpy(displayBuffer, promptText + textStartPos, 8);
  displayBuffer[8] = '\0';
  module.displayText(displayBuffer);

  // Read the buttons
  uint8_t buttons = module.readButtons();

  // Set LEDs based on the button states
  for (uint8_t position = 0; position < 8; position++) {
    uint8_t mask = 0x1 << position;
    module.setLED((buttons & mask) ? 1 : 0, position);
  }

  block = (block + 1) % 16;
}
