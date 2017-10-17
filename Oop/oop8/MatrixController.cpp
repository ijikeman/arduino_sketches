#include "MatrixController.h"
#include "config.h"
#include "Arduino.h"

MatrixController::MatrixController (const int * _cols, const int * _colNum, const int * _rows, const int * _rowNum) {
  cols = _cols;
  rows = _rows;
  colNum = _colNum;
  rowNum = _rowNum;
  x = 255;
  y = 255;
}

void MatrixController::initialState(bool state) {
  for (int i = 0; i < *colNum; i++) {
    for (int j = 0; j < *rowNum; j++) {
      currentState[i][j] = state;
      beforeState[i][j] = state;
    }
  }
}

void MatrixController::read() {
  bool state = 0;
  for (int i = 0; i < *colNum; i++) {
    state = digitalRead(cols[i]);
    digitalWrite(cols[i], !state);
    for (int j = 0; j < *rowNum; j++) {
      currentState[i][j] = digitalRead(rows[j]);
      Serial.print(currentState[i][j]);
      Serial.print(":");
      if (beforeState[i][j] != currentState[i][j]) {
        beforeState[i][j] = currentState[i][j];
        digitalWrite(cols[i], state);
        x = i;
        y = j;
        return;
      }
    }
    digitalWrite(cols[i], state);
  }
  Serial.println("");
  x = 255;
  y = 255;
  return;
}
