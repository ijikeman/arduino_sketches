#ifndef MatrixController_h
#define MatrixController_h
#include "config.h"

class MatrixController {
  public:
    MatrixController(const int * _inPins, const int * _inPinNum, const int * _outPins, const int * _outPinNum);
    void initialState(bool state);
    bool read();
    unsigned int in;
    unsigned int out;
    bool pushPull;
  private:
#ifdef COL_TO_ROW
    bool currentState[ROW_NUM][COL_NUM];
    bool beforeState[ROW_NUM][COL_NUM];
#else
    bool currentState[COL_NUM][ROW_NUM];
    bool beforeState[COL_NUM][ROW_NUM];
#endif
    const int * inPins;
    const int * outPins;
    const int * inPinNum;
    const int * outPinNum;
};

#endif
