#ifndef PinController_h
#define PinController_h

class PinController {
  public:
    PinController(int *pins, int pinNum);
    void pinMode(bool input, bool value);
};

#endif

