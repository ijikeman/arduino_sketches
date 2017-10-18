#include "SerialController.h"
#include "Arduino.h"

#define SHIFT(val, num) ((unsigned int)val << (num))
#define SHIFT_MK(val) SHIFT(val, 7)
#define SHIFT_PUSH_RELEASE(val) SHIFT(val, 6)
#define SHIFT_ROW(val) SHIFT(val, 3)
#define SHIFT_COL(val) SHIFT(val, 0)

#define SHIFT_X_Y(val) SHIFT(val, 6)
#define SHIFT_MINUS_PLUS(val) SHIFT(val, 5)
#define SHIFT_RANGE(val) SHIFT(val, 0)

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

int SerialController::available() {
  return Serial1.available();
}
