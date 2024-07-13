#include "BasicRead.h"

bool basicRead(uint8_t pin0, uint8_t pin1){
  uint8_t x = digitalRead(pin0);
  Serial.println(x);
  digitalWrite(pin1,x);
  delay(1000);

  return true;
}