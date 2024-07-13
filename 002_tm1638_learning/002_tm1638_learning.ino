#include <TM1638lite.h>
#include "Scroll.h"
#include "AllLedLogics.h"
#include "Game.h"

// Define pins
#define DIO_PIN 8
#define CLK_PIN 9
#define STB_PIN 10

// Create an instance of TM1638lite
TM1638lite module(DIO_PIN, CLK_PIN, STB_PIN);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  // Clear display at startup
  module.displayText("        ");
  setupGame();
}

void loop() {
  // Select the example
  // for game (3) uncomment setupgame
  int example = 3; 

  switch (example) {
    case 1:
      allLedLogics();
      break;
    case 2:
      scroll("          LEMUEL FAVIAN LEONS        ");
      delay(150);
      break;
    case 3:
    playGame();
    break;
  }
}
