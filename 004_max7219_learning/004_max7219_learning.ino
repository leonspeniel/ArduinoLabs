#include <LedControl.h>
#include "ScrollingText.h"
#include "SimpleAnimation.h"
#include "DisplayNumbers.h"

// Pin Definitions
const int DIN_PIN = 11;
const int CS_PIN = 10;
const int CLK_PIN = 13;

// Initialize the LedControl library
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

// Function to select example
void setupExample(int example);
void loopExample(int example);

void setup() {
    // Set up based on the selected example
    int selectedExample = 3;  // Change this value to 1, 2, or 3 to select different examples
    setupExample(selectedExample);
}

void loop() {
    // Run the loop function based on the selected example
    int selectedExample = 3;  // Change this value to 1, 2, or 3 to select different examples
    loopExample(selectedExample);
}

void setupExample(int example) {
    switch (example) {
        case 1:
            setupScrollingText(lc);
            break;
        case 2:
            setupSimpleAnimation(lc);
            break;
        case 3:
            setupDisplayNumbers(lc);
            break;
        default:
            // Default to example 1
            setupScrollingText(lc);
            break;
    }
}

void loopExample(int example) {
    switch (example) {
        case 1:
            loopScrollingText(lc);
            break;
        case 2:
            loopSimpleAnimation(lc);
            break;
        case 3:
            loopDisplayNumbers(lc);
            break;
        default:
            // Default to example 1
            loopScrollingText(lc);
            break;
    }
}
