#ifndef PinController_h
#define PinController_h

class PinController {
  public:
    PinController(int pins);
    void pinMode();

  private:
    int p;
};

#endif

