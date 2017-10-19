#include "PinController.h"

PinController::PinController() {
}

void PinController::setNo(unsigned int _n_no) {
  n_no = _n_no;
}

unsigned int PinController::getNo() {
  return n_no;
}

void PinController::setMode(bool _b_mode) {
  b_mode = _b_mode;
}

bool PinController::getMode() {
  return b_mode;
}

void PinController::setState(bool _b_state) {
  b_state = _b_state;
}

bool PinController::getState() {
  return b_state;
}