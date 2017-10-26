#ifndef PinsController_h
#define PinsController_h
#include "PinController.h"
//#include <vector>
#include <ArduinoSTL.h>
#include "config.h"

class PinsController {
  public:
    PinsController(unsigned int * _p_array_nums, unsigned int _p_array_size, const unsigned int * _b_state, const unsigned int * _b_mode);
    unsigned int * currentTotal();
  private:
    PinController * p_array_pins[MAX_PIN_NUM];
    unsigned int total;
};
#endif
