#include "PinsController.h"
#include "MatrixController.h"
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
  MatrixController matrixCtr = MatrixController(&colPins, &rowPins);
}

void loop() {

//  unsigned int test = matrixCtr.Read();
}
