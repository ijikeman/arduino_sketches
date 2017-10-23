#ifndef PinsController_h
#define PinsController_h
#include "PinController.h"
//#include <vector>
#include <ArduinoSTL.h>

class PinsController {
  public:
    PinsController();
    void NumAll(unsigned int * p_array_nums, unsigned int size);
    void ModeAll(bool _b_mode);
    void StateAll(bool _b_state);
    unsigned int * TotalNumber();
  private:
    PinController * parray_pins[20];
    unsigned int total;
};
#endif
