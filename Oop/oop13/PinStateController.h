#ifndef PinStateController_h
#define PinStateController_h
#include "config.h"

class PinStateController {
  public:
    PinStateController(unsigned int outputSize, unsigned int inputSize, bool _b_initState);
    void changeState(unsigned int _n_output, unsigned int _n_input, bool _b_changeState);
    bool same(unsigned int _n_output, unsigned int _n_input);
  private:
    bool beforeState[MAX_PIN_NUM][MAX_PIN_NUM];
    bool currentState[MAX_PIN_NUM][MAX_PIN_NUM];
};
#endif