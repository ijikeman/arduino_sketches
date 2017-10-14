#ifndef PinController_h
#define PinController_h

class PinController {
  public:
    PinController(const int * p, const int * n);
    void pinMode(bool mode, bool inOrOut);
  private:
    const int * pins;
    const int * pin_num;
};

#endif

