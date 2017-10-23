#include "PinsController.h"
//#include <vector>
#include <ArduinoSTL.h>
PinsController::PinsController() {
  total = 0;
}

void PinsController::NumAll(unsigned int * p_array_nums, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    PinController *pin = new PinController();
    (*pin).Num(p_array_nums[i]);
    v_pins.push_back(pin);
    total++;
  }
}

void PinsController::ModeAll(bool _b_mode) {
  for (std::vector<PinController*>::iterator itr=v_pins.begin();itr != v_pins.end(); itr++) {
    (**itr).Mode(_b_mode);
  }
}

void PinsController::StateAll(bool _b_state) {
  for (std::vector<PinController*>::iterator itr=v_pins.begin();itr != v_pins.end(); itr++) {
    (**itr).State(_b_state);
  }
}

unsigned int PinsController::TotalNumber() {
  return total;
}

// std::vector<PinController*> Pins() {
//   return v_pins;
// }
