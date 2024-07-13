#include "Game.h"
#include <Arduino.h>

#define NUM_TARGETS 8
bool targets[NUM_TARGETS];
unsigned long startTime;

void setupGame() {
  // Initialize targets (randomly light up some LEDs)
  for (int i = 0; i < NUM_TARGETS; i++) {
    targets[i] = random(0, 2); // Randomly set target to on (1) or off (0)
    module.setLED(targets[i], i);
  }

  // Reset the start time
  startTime = millis();
}

void playGame() {
  // Check button presses to "shoot" targets
  uint8_t buttons = module.readButtons();
  
  for (int i = 0; i < NUM_TARGETS; i++) {
    if ((buttons & (1 << i)) && targets[i]) {
      targets[i] = false;
      module.setLED(0, i); // Turn off LED
    }
  }

  // Check if all targets are shot
  bool allShot = true;
  for (int i = 0; i < NUM_TARGETS; i++) {
    if (targets[i]) {
      allShot = false;
      break;
    }
  }

  // If all targets are shot, display the time taken
  if (allShot) {
    unsigned long timeTaken = millis() - startTime;
    char buffer[9];
    snprintf(buffer, 9, "%8lu", timeTaken);
    module.displayText(buffer);
    delay(5000); // Display time for 5 seconds
    setupGame(); // Restart the game
  }
}
