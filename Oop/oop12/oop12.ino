#include "PinsController.h"
//#include "MatrixController.h"
#include "config.h"

void setup() {
  PinsController colPins = PinsController();
  colPins.NumAll(COL_PINS, (sizeof(COL_PINS)/sizeof(unsigned int)));
  colPins.ModeAll(OUTPUT);
  colPins.StateAll(HIGH);
  PinsController rowPins = PinsController();
  rowPins.NumAll(ROW_PINS, sizeof(ROW_PINS)/sizeof(unsigned int));
  rowPins.ModeAll(INPUT);
  rowPins.StateAll(HIGH);
//  MatrixController matrixCtr = MatrixController(&colPins, &rowPins);
}

void loop() {
// colPins.Pins();
//  unsigned int test = matrixCtr.Read();
}
