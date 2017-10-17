#include "config.h"
#include "PinController.h"
#include "MatrixController.h"

PinController colPins = PinController(COL_PINS, &COL_NUM);
PinController rowPins = PinController(ROW_PINS, &ROW_NUM);
MatrixController matrix = MatrixController(ROW_PINS, &ROW_NUM, COL_PINS, &COL_NUM);

void setup() {
  Serial.begin(9600);
  colPins.pinModeAll(INPUT);
  colPins.digitalWriteAll(HIGH); // INPUT, HIGH
  rowPins.pinModeAll(OUTPUT);
  rowPins.digitalWriteAll(HIGH); // OUTPUT, HIGH
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
