#ifndef PinController_h
#define PinController_h

class PinController {
  public:
    PinController();
    void setPins(int p);
    void pinMode();

  private:
    int *pins;
};

#endif

