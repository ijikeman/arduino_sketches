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
    unsigned int TotalNumber();
//    std::vector<PinController*> * Pins();
  private:
    std::vector<PinController*> v_pins;
    unsigned int total;
};
#endif
