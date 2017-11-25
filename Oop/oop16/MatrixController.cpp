#include "MatrixController.h"
#include "PinsController.h"
#include "PinController.h"

MatrixController::MatrixController(PinsController * cols, PinsController * rows) {
  m_cols = cols;
  m_rows = rows;
  m_col_it = cols->iterator();
  m_row_it = rows->iterator();
  i = 0;
  j = 0;
}

bool MatrixController::matrix() {
  while (m_col_it->hasNext()) {
    PinController * col = m_col_it->next();
    col->reverseState();
    while (m_row_it->hasNext()) {
      PinController * row = m_row_it->next();
      Serial.print(col->isLow());
      Serial.print(":");
      if (row->isLow()) {
        return 1;
      }
      j++;
    }
    col->reverseState();
    Serial.println("");
    j = 0;
    i++;
  }
  Serial.println("--------");
  i = 0;
  j = 0;
  return 0;
}
