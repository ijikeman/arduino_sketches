#include "PinsController.h"
//#include <vector>
#include <ArduinoSTL.h>
PinsController::PinsController(unsigned int * _p_array_nums, unsigned int _size, bool _b_state, bool _b_mode) {
  total = 0;
  for (unsigned int i = 0; i < _size; i++) {
    PinController * pin = new PinController(_p_array_nums[i], _b_state, _b_mode);
    p_array_pins[total] = pin;
    total++;
  }

}

unsigned int * PinsController::currentTotal() {
  return &total;
}
