#include "PinController.h"
#include "Arduino.h"
PinController::PinController(unsigned int _n_num, bool _b_state, bool _b_mode) {
  n_num = _n_num;
  b_mode = _b_mode;
  b_mode = _b_state;
  digitalWrite(n_num, b_state);
}

void PinController::reverseState() {
  digitalWrite(n_num, !b_state);
}

bool PinController::currentState() {
  return digitalRead(n_num);
}
