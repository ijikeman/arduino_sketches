#include "config.h"
#include "PinController.h"

PinController colPinCont = PinController::PinController(COL_PINS, COL_NUM);
// PinController rowPinCont = PinController::PinController(ROW_PINS, ROW_NUM);

void setup() {
   Serial.begin(9600);
   colPinCont.pinMode(true, true); // INPUT, HIGH
   // rowPinCont.pinMode(false, true); // OUTPUT, HIGH
}

void loop() {
  delay(1000);
}
