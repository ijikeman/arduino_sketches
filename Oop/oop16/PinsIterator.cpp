#include "PinsIterator.h"

PinsIterator::PinsIterator(PinsController * pins) {
  m_pins = pins;
  m_index = 0;
}

bool PinsIterator::hasNext() {
  if (m_index < m_pins->getNum()) {
    return 1;
  }
  m_index = 0;
  return 0;
}

PinController * PinsIterator::next() {
  PinController * pin = m_pins->get(m_index);
  m_index++;
  return pin;
}
