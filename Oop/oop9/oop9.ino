#include "config.h"
#include "PinController.h"
#include "MatrixController.h"
#include "SerialController.h"

PinController rowPins = PinController(ROW_PINS, &ROW_NUM);
PinController colPins = PinController(COL_PINS, &COL_NUM);
MatrixController matrix = MatrixController(ROW_PINS, &ROW_NUM, COL_PINS, &COL_NUM);
SerialController serialCont = SerialController(9600);

void setup() {
  Serial.begin(9600);
  rowPins.pinModeAll(OUTPUT);
  rowPins.digitalWriteAll(HIGH); // OUTPUT, HIGH
  colPins.pinModeAll(INPUT);
  colPins.digitalWriteAll(HIGH); // INPUT, HIGH
  matrix.initialState(HIGH);
}

void loop() {
  matrix.read();
  if (matrix.row != 255 || matrix.col != 255) {
    serialCont.makeData(KEYBOARD, matrix.pushPull, matrix.row, matrix.col);
    serialCont.sendToMaster();
  }
  delay(500);
}
