#ifndef PinsController_h
#define PinsController_h
#include "PinController.h"
//#include <vector>
#include <ArduinoSTL.h>

class PinsController {
  public:
    PinsController();
    void Num(unsigned int * p_array_nums, unsigned int size);
    void Mode(bool _b_mode);
    void State(bool _b_state);
    unsigned int TotalNumber();
    PinController * Pin(unsigned int n_number);
  private:
    std::vector<PinController*> v_pins;
    unsigned int total;
};
#endif
