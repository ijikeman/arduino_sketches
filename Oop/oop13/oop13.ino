#include "PinsController.h"
#include "MatrixController.h"
#include "config.h"

PinsController colPins = PinsController(COL_PINS, sizeof(COL_PINS)/sizeof(unsigned int), HIGH, OUTPUT);
PinsController rowPins = PinsController(ROW_PINS, sizeof(ROW_PINS)/sizeof(unsigned int), HIGH, INPUT);
MatrixController matrixCtr = MatrixController(&colPins, &rowPins, HIGH);

void setup() {
}

void loop() {
//  matrixCtr.Read();
}
