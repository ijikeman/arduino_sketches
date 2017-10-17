#include "MatrixController.h"
#include "config.h"
#include "Arduino.h"

MatrixController::MatrixController (const int * _rows, const int * _rowNum, const int * _cols, const int * _colNum) {
  cols = _cols;
  rows = _rows;
  colNum = _colNum;
  rowNum = _rowNum;
  x = 255;
  y = 255;
}

void MatrixController::initialState(bool state) {
  for (int i = 0; i < *rowNum; i++) {
    for (int j = 0; j < *colNum; j++) {
      currentState[i][j] = state;
      beforeState[i][j] = state;
    }
  }
}

void MatrixController::read() {
  bool state = 0;
  for (int i = 0; i < *rowNum; i++) {
    state = digitalRead(rows[i]);
    digitalWrite(rows[i], !state);
    for (int j = 0; j < *colNum; j++) {
      currentState[i][j] = digitalRead(cols[j]);
      Serial.print(currentState[i][j]);
      Serial.print(":");
      if (beforeState[i][j] != currentState[i][j]) {
        beforeState[i][j] = currentState[i][j];
        digitalWrite(rows[i], state);
        x = i;
        y = j;
        return;
      }
    }
    digitalWrite(rows[i], state);
  }
  Serial.println("");
  x = 255;
  y = 255;
  return;
}
