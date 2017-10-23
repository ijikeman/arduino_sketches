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
    parray_pins[total] = pin;
    total++;
  }
}

void PinsController::ModeAll(bool _b_mode) {
  for (unsigned int i = 0; i < total; i++) {
    (*parray_pins[i]).Mode(_b_mode);
  }
}

void PinsController::StateAll(bool _b_state) {
  for (unsigned int i = 0; i < total; i++) {
    (*parray_pins[i]).State(_b_state);
  }
}

unsigned int * PinsController::TotalNumber() {
  return &total;
}
