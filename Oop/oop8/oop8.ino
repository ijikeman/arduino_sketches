#include "config.h"
#include "PinController.h"
#include "MatrixController.h"

PinController colPins = PinController(COL_PINS, &COL_NUM);
PinController rowPins = PinController(ROW_PINS, &ROW_NUM);
MatrixController matrix = MatrixController(COL_PINS, &COL_NUM, ROW_PINS, &ROW_NUM);

void setup() {
  Serial.begin(9600);
  colPins.pinModeAll(OUTPUT); // OUTPUT
  colPins.digitalWriteAll(HIGH); // OUTPUT, HIGH
  rowPins.pinModeAll(INPUT); // INPUT
  rowPins.digitalWriteAll(HIGH); // INPUT, HIGH
  matrix.initialState(HIGH);
}

void loop() {
  matrix.read();
  if (matrix.x != 255 || matrix.y != 255) {
    Serial.println("");
    Serial.print(matrix.x);
    Serial.print(":");
    Serial.println(matrix.y);
  }
  delay(500);
}
