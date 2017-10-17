#include "PinController.h"
#include <stdio.h>
#include "Arduino.h"

PinController::PinController(const int * _pins, const int * _pinNum) {
  pins = _pins;
  pinNum = _pinNum;
}
void PinController::pinModeAll(bool mode) {
  for (int i = 0; i < *pinNum; i++) {
    pinMode(pins[i], mode);
    Serial.print("PIN_MODE:");
    Serial.print(pins[i]);
    Serial.print(" is ");
    Serial.println(mode);
  }
}

void PinController::digitalWriteAll(bool writeParam) {
  for (int i = 0; i < *pinNum; i++) {
    digitalWrite(pins[i], writeParam);
    Serial.print("PIN_WRITE:");
    Serial.print(pins[i]);
    Serial.print(" ");
    Serial.println(writeParam);
  }
}
