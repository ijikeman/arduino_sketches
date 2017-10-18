#include "SerialController.h"
#include "Arduino.h"
#include "config.h"

SerialController::SerialController(unsigned int _beginRate) {
  Serial1.begin(_beginRate);
}

void SerialController::makeData(bool _mode, bool _second, unsigned int _third, unsigned int _forth) {
  // Keyboard Mode
  if ( _mode == 0 ) {
    data = SHIFT_MK(_mode) | SHIFT_PUSH_RELEASE(_second) | SHIFT_ROW(_third) | SHIFT_COL(_forth);

  // Mouse Mode
  } else {
    data = SHIFT_MK(_mode) | SHIFT_X_Y(_second) | SHIFT_MINUS_PLUS(_third) | SHIFT_RANGE(_forth);
  }
  Serial.println(data);
}

void SerialController::sendToMaster() {
  Serial1.write(data);
}

void SerialController::recieveToSlave() {
  data = Serial1.read();
  Serial.println(data);
}

bool SerialController::isKeyboard() {
  if (UNSHIFT_MK(data) == KEYBOARD) {
    return TRUE;
  }
  return FALSE;
}

bool SerialController::isMouse() {
  if (UNSHIFT_MK(data) == MOUSE) {
    return TRUE;
  }
  return FALSE;
}

int SerialController::available() {
  return Serial1.available();
}
