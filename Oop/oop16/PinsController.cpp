#include "PinsController.h"
#include "PinController.h"
#include "PinsIterator.h"
#include "Arduino.h"

PinsController::PinsController() {
  m_index = 0;
}

void PinsController::set(PinController * pin) {
   m_pins[m_index] = pin;
   m_index++;
}

PinController * PinsController::get(unsigned int index) {
  return m_pins[index];
}

unsigned int PinsController::getNum() {
  return m_index;
}

PinsIterator * PinsController::iterator() {
   return new PinsIterator(this);
}
