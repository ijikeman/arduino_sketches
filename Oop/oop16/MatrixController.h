#ifndef MatrixController_h
#define MatrixController_h
#include "PinsController.h"
#include "PinsIterator.h"
class MatrixController {
  public:
    MatrixController(PinsController * cols, PinsController * rows);
    bool matrix();
    unsigned int col();
    unsigned int row();
  private:
    PinsController * m_cols;
    PinsController * m_rows;
    PinsIterator * m_col_it;
    PinsIterator * m_row_it;
    unsigned int i;
    unsigned int j;
};
#endif
