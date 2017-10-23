#include "PinController.h"
#include "Arduino.h"
PinController::PinController() {
}

void PinController::Num(unsigned int _n_num) {
  n_num = _n_num;
}

unsigned int PinController::Num() {
  return n_num;
}

void PinController::Mode(bool _b_mode) {
  b_mode = _b_mode;
  pinMode(n_num, b_mode);
}

bool PinController::Mode() {
  return b_mode;
}

void PinController::State(bool _b_state) {
  digitalWrite(n_num, _b_state);
}

bool PinController::State() {
  return digitalRead(n_num);
}
