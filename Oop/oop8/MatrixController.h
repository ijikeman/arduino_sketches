#ifndef MatrixController_h
#define MatrixController_h
#include "config.h"

class MatrixController {
  public:
    MatrixController(const int * _rows, const int * _rowNum, const int * _cols, const int * _colNum);
    void initialState(bool state);
    void read();
    int x;
    int y;
  private:
    bool currentState[ROW_NUM][COL_NUM];
    bool beforeState[ROW_NUM][COL_NUM];
    const int * cols;
    const int * rows;
    const int * colNum;
    const int * rowNum;
};

#endif