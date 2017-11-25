#include "PinController.h"

PinController pin17 = PinController(17, LOW, INPUT);

void setup() {
}

void loop() {
  pin17.reverseState();
  delay(1000);
}
