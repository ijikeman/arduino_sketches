#include "SerialController.h"
#include "Arduino.h"

#define BIT(num) ((unsigned int)1 << (num))
#define BIT_MK BIT(7)
#define BIT_PUSH_RELEASE BIT(6)
#define BIT_ROW BIT(3)
#define BIT_COL BIT(0)

#define BIT_X_Y BIT(6)
#define BIT_MINUS_PLUS BIT(5)
#define BIT_RANGE BIT(0)

SerialController::SerialController(unsigned int _beginRate) {
  Serial1.begin(_beginRate);
}

void SerialController::makeData(bool _mode, bool _second, unsigned int _third, unsigned int _forth) {
  // Keyboard Mode
  if ( _mode == 0 ) {
//    data = (_mode & BIT_MK) | (_second & BIT_PUSH_RELEASE) | (_third & BIT_ROW) | (_forth & BIT_COL);
    data = ((unsigned char)_mode & BIT_MK) | ((unsigned char)_second << 6) | _third << 3 | _forth;

  // Mouse Mode
  } else {
    data = (_mode & BIT_MK) | (_second & BIT_X_Y) | (_third & BIT_MINUS_PLUS) | (_forth & BIT_RANGE);
  }
  Serial.println(data);
}

void SerialController::sendToMaster() {
  Serial1.write(data);
}
