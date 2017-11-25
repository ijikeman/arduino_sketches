#include "PinsIterator.h"

bool PinsIterator::hasNext() {
  return 1;
}

PinController * PinsIterator::Next() {
  PinController pin = m_pins.getPin(m_index);
  m_index++;
  return pin;
}
