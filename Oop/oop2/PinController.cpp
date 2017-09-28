#include "Arduino.h"
#include "PinController.h"

PinController::PinController(int *p, int n) {
  int pins = p;
  int pinNum = n;
}
void pinMode(bool input, bool value) {
  // for (int i = 0; i < pinNum; i++) {
  //   Serial.print(Pins[i]);
  //   Serial.print(':');
  // }
  // Serial.println("");
  // for (int i = 0; i < pinNum; i++) {
  //   switch (input) {
  //   case 0:
  //     pinMode(Pins[i], OUTUT);
  //     break;
  //   case 1:
  //     pinMode(Pins[i], INPUT);
  //     break;
  //   }
  //   digitalWrite(Pins[i], value);
  // }
}


