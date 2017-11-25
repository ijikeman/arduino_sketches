#ifndef PinController_h
#define PinController_h

class PinController {
  public:
    PinController(unsigned int num, bool state, bool mode);
    void reverseState();
    bool isHigh();
    bool isLow();
  private:
    unsigned int m_num;
    bool readState();
};

class OutputPinController : public PinController {
  public:
    OutputPinController();
};
#endif
