#ifndef PinsController_h
#define PinsController_h
#include "PinsAggregate.h"
#include "PinsIterator.h"
#include "PinController.h"
#include "Arduino.h"

#define MAX_NUM 8

class PinsIterator;

class PinsController : public PinsAggregate {
  public:
    PinsController();
    void set(PinController * pin);
    PinController * get(unsigned int index);
    unsigned int getNum();
    PinsIterator * iterator();
  private:
    unsigned int m_index;
    PinController * m_pins[MAX_NUM];
};
#endif
