#ifndef PinController_h
#define PinController_h

class PinController {
  public:
    PinController(const int * _pins, const int * _pinNum);
    void pinModeAll(bool mode);
    void digitalWriteAll(bool writeParam);
  private:
    const int * pins;
    const int * pinNum;
};

#endif
