#ifndef PinsAggregate_h
#define PinsAggregate_h
#include "AggregateInterface.h"
#include "PinsIterator.h"

class PinsIterator;

class PinsAggregate : public AggregateInterface {
  public:
    PinsIterator * iterator();
};
#endif
