#ifndef PinsIterator_h
#define PinsIterator_h
#include "PinsController.h"
#include "IteratorInterface.h"

class PinsController;
class PinController;

class PinsIterator : public IteratorInterface {
  public:
    PinsIterator(PinsController * pins);
    bool hasNext();
    PinController * next();
  private:
    PinsController * m_pins;
    unsigned int m_index;
};
#endif
