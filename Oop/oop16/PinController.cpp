#include "PinController.h"
#include "Arduino.h"

PinController::PinController(unsigned int num, bool state, bool mode) {
  m_num = num;
  pinMode(m_num, mode);
  digitalWrite(m_num, state);
}

void PinController::reverseState() {
  digitalWrite(m_num, !readState());
}

bool PinController::isHigh() {
  if (readState() == HIGH) {
    return true;
  }
  return false;
}

bool PinController::isLow() {
  if (readState() == LOW) {
    return true;
  }
  return false;
}

// private:
bool PinController::readState() {
  return digitalRead(m_num);
}

unsigned int PinController::getNum() {
  return m_num;
}
