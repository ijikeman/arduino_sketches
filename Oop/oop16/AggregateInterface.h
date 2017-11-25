#ifndef AggregateInterface_h
#define AggregateInterface_h

class AggregateInterface {
  public:
    template<typename T> T * iterator();
};
#endif
