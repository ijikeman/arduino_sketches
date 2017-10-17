#include "MatrixController.h"
#include "config.h"
#include "Arduino.h"

MatrixController::MatrixController (const int * _rows, const int * _rowNum, const int * _cols, const int * _colNum) {
  rows = _rows;
  rowNum = _rowNum;
  cols = _cols;
  colNum = _colNum;
  row = 255;
  col = 255;
  pushPull = 0;
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
      Serial.println("Matrix.read()");
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
        pushPull = currentState[i][j];
        row = i;
        col = j;
        Serial.println("");
        Serial.print(row);
        Serial.print(":");
        Serial.print(col);
        Serial.print(":");
        Serial.println(pushPull);
        return;
      }
    }
    digitalWrite(rows[i], state);
  }
  Serial.println("");
  row = 255;
  col = 255;
  pushPull = 0;
  return;
}
