#include "PinController.h"
#include "Arduino.h"
PinController::PinController(unsigned int _n_num, const unsigned int * _b_state, const unsigned int * _b_mode) {
  n_num = _n_num;
  b_mode = _b_mode;
  b_state = _b_state;
  digitalWrite(n_num, b_state);
}

void PinController::reverseState() {
  digitalWrite(n_num, !b_state);
}

unsigned int PinController::currentState() {
  return digitalRead(n_num);
}
