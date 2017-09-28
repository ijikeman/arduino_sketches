#include "LedController.h"

const int ledPin = 17;

LedController led = LedController(ledPin);

void setup() {
}

void loop() {
  led.on();
  delay(1000);
  led.off();
  delay(1000);
}
