#include "PinsController.h"
#include "MatrixController.h"
#include "config.h"
MatrixController matrixCtr = MatrixController();

void setup() {
  PinsController colPins = PinsController();
  colPins.NumAll(COL_PINS, (sizeof(COL_PINS)/sizeof(unsigned int)));
  colPins.ModeAll(OUTPUT);
  colPins.StateAll(HIGH);
  PinsController rowPins = PinsController();
  rowPins.NumAll(ROW_PINS, sizeof(ROW_PINS)/sizeof(unsigned int));
  rowPins.ModeAll(INPUT);
  rowPins.StateAll(HIGH);
  matrixCtr.OutputPins(&colPins);
  matrixCtr.InputPins(&rowPins);
  matrixCtr.InitialState();
}

void loop() {
  // matrixCtr.Read();
}
