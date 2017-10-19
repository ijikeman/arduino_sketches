#ifndef PinsController_h
#define PinsController_h
#include "PinController.h"
#include <vector>

class PinsController {
  public:
    PinsController();
    void setNo(unsigned int * p_array_nos, unsigned int size);
    void getNo();
  private:
    std::vector<PinController*> v_pins;
};
#endif
