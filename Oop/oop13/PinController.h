#ifndef PinController_h
#define PinController_h
class PinController {
  public:
    PinController(unsigned int _n_num, bool _b_state, bool _b_mode);
    void reverseState();
    bool currentState();
  private:
    unsigned int n_num; // Pin Number
    bool b_state; // LOW or HIGH
    bool b_mode; // INPUT or OUTPUT
};
#endif
