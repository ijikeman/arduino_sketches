#ifndef PinsIterator_h
#define PinsIterator_h
class PinsIteratorInterface {
  public:
    virtual bool hasNext(void)=0;
    virtual PinController Next(void)=0;
};

class PinsIterator : public PinsIteratorInterface {
  public:
    PinsIterator(PinsController pins)
    :m_index(0),PinsController m_pins(pins) {}

    bool hasNext(void);
    PinsController Next(void);

  private:
    PinsController m_pins;
    unsigned int m_index;
};
#endif
