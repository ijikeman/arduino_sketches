#include "config.h"
#include "PinController.h"
#include "MatrixController.h"

void loop();

PinController colPins = PinController(COL_PINS, &COL_NUM);
PinController rowPins = PinController(ROW_PINS, &ROW_NUM);
MatrixController matrix = MatrixController(COL_PINS, &COL_NUM, ROW_PINS, &ROW_NUM);

int main() {
  colPins.pinModeAll(OUTPUT); // OUTPUT
  colPins.digitalWriteAll(HIGH); // OUTPUT, HIGH
  rowPins.pinModeAll(INPUT); // INPUT
  rowPins.digitalWriteAll(HIGH); // INPUT, HIGH
  matrix.initialState(HIGH);
  loop();
  return 0;
}

void loop() {
//  matrix.read();
}
