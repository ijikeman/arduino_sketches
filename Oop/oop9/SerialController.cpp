#include "SerialController.h"
#include "Arduino.h"

#define BIT(num) ((unsigned int)1 << (num))
#define BIT_MK BIT(7)
#define BIT_PUSH_RELEASE BIT(6)
#define BIT_ROW (BIT(5)|BIT(4)|BIT(3))
#define BIT_COL (BIT(2)|BIT(1)|BIT(0))

#define BIT_X_Y BIT(6)
#define BIT_MINUS_PLUS BIT(5)
#define BIT_RANGE (BIT(4)|BIT(3)|BIT(2)|BIT(1)|BIT(0))

SerialController::SerialController(unsigned int _beginRate) {
  Serial1.begin(_beginRate);
}

void SerialController::makeData(bool _mode, bool _second, unsigned int _third, unsigned int _forth) {
  // Keyboard Mode
  if ( _mode == 0 ) {
    data = _mode << 7 | _second << 6 | _third << 3 | _forth;

  // Mouse Mode
  } else {
    data = _mode << 7 | _second << 6 | _third & << 5 | _forth;
  }
  Serial.println(data);
}

void SerialController::sendToMaster() {
  Serial1.write(data);
}
