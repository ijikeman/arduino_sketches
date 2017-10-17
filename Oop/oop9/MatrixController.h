#ifndef MatrixController_h
#define MatrixController_h
#include "config.h"

class MatrixController {
  public:
    MatrixController(const int * _rows, const int * _rowNum, const int * _cols, const int * _colNum);
    void initialState(bool state);
    void read();
    unsigned int row;
    unsigned int col;
    bool pushPull;
  private:
    bool currentState[ROW_NUM][COL_NUM];
    bool beforeState[ROW_NUM][COL_NUM];
    const int * rows;
    const int * cols;
    const int * rowNum;
    const int * colNum;
};

#endif
