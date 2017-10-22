#include "PinsController.h"
#include "config.h"

void setup() {
  PinsController colPins = PinsController();
  colPins.Num(COL_PINS, sizeof(COL_PINS)/sizeof(unsigned int));
  colPins.Mode(OUTPUT);
  colPins.State(HIGH);
  PinsController rowPins = PinsController();
  rowPins.Num(ROW_PINS, sizeof(ROW_PINS)/sizeof(unsigned int));
  rowPins.Mode(INPUT);
  rowPins.State(HIGH);
}

void loop() {

}
