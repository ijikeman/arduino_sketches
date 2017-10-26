#ifndef PinStateController_h
#define PinStateController_h
#include "config.h"

class PinStateController {
  public:
    PinStateController(unsigned int _n_outputNum, unsigned int _n_inputNum, const unsigned int * _b_initState);
    void updateState(unsigned int _n_outputNum, unsigned int _n_inputNum, const unsigned int * _b_updateState);
//    bool same(unsigned int _n_outputNum, unsigned int _n_inputNum);
  private:
    unsigned int beforeState[MAX_PIN_NUM][MAX_PIN_NUM];
    unsigned int currentState[MAX_PIN_NUM][MAX_PIN_NUM];
};
#endif
