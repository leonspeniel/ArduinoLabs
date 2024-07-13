#include "BasicWrite.h"

bool basicWrite(uint8_t pin){
  digitalWrite(pin, LOW);
  delay(250);
  digitalWrite(pin, HIGH);
  delay(250);

  return true;
}