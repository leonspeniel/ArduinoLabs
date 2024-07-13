#include "BasicWrite.h"
#include "BasicRead.h"


uint8_t pin13 = 13;
uint8_t pin07 = 07;
uint8_t pin06 = 06;
uint8_t example=1;



void setup() {
  switch(example){
    default:
    pinMode(pin13, OUTPUT);
    break;
    case 1:
    Serial.begin(9600);
    pinMode(pin07, INPUT);
    pinMode(pin06, OUTPUT);
    break;
  }
}

void loop() {
  switch(example){
    default:
    basicWrite(pin13);
    break;
    case 1:
    basicRead(pin07, pin06);
    break;
  }
}
