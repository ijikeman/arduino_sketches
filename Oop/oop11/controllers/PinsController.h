#ifndef PinsController_h
#define PinsController_h
#include "PinController.h"

class PinsController {
  public:
//    PinsController(unsigned int _n_pin_num);
  	PinsController();
//    setNo(unsigned int _n_pin_nums[]);
  private:
    PinController pins[pinNum];
};
#endif