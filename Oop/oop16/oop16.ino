#include "PinController.h"
#include "PinsController.h"
#include "MatrixController.h"
#include "config.h"
#include "Arduino.h"

unsigned int colpins[COL_NUM] = {9, 8, 7, 6};
unsigned int rowpins[ROW_NUM] = {A3, A2, A1, A0, 15, 14};

PinsController cols = PinsController();
PinsController rows = PinsController();
MatrixController matrix = MatrixController(&cols, &rows);

void setup() {
  for (int i = 0; i < COL_NUM; i++) {
    cols.set(new PinController(colpins[i], HIGH, OUTPUT));
  }

  for (int i = 0; i < ROW_NUM; i++) {
     rows.set(new PinController(rowpins[i], HIGH, INPUT));
  }
  Serial.begin(9600);
}

void loop() {
  matrix.matrix();
  delay(1000);
}
