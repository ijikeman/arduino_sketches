#include "PinsController.h"
//#include <vector>
#include <ArduinoSTL.h>
PinsController::PinsController() {
}

void PinsController::Num(unsigned int * p_array_nums, unsigned int size) {
  for (int i = 0; i < size; i++) {
    PinController *pin = new PinController();
    (*pin).Num(p_array_nums[i]);
    v_pins.push_back(pin);
  }
}

void PinsController::Mode(bool _b_mode) {
  for (std::vector<PinController*>::iterator itr=v_pins.begin();itr != v_pins.end(); itr++) {
    (**itr).Mode(_b_mode);
  }
}

void PinsController::State(bool _b_state) {
  for (std::vector<PinController*>::iterator itr=v_pins.begin();itr != v_pins.end(); itr++) {
    (**itr).State(_b_state);
  }
}
