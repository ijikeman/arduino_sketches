#ifndef MatrixController_h
#define MatrixController_h
#include "config.h"

class MatrixController {
  public:
    MatrixController(const int * _cols, const int * _colNum, const int * _rows, const int * _rowNum);
    void initialState(bool state);
    void read();
    int x;
    int y;
  private:
    bool currentState[COL_NUM][ROW_NUM];
    bool beforeState[COL_NUM][ROW_NUM];
    const int * cols;
    const int * rows;
    const int * colNum;
    const int * rowNum;
};

#endif
