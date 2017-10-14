#include "config.h"
#include "PinController.h"

PinController colPin = PinController(COL_PINS, &COL_NUM);
int main() {
  colPin.pinMode(0, 1); // INPUT, HIGH
  return 0;
}
