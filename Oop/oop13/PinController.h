#ifndef PinController_h
#define PinController_h
class PinController {
  public:
    PinController(unsigned int _n_num, const unsigned int * _b_state, const unsigned int * _b_mode);
    void reverseState();
    unsigned int currentState();
  private:
    unsigned int n_num; // Pin Number
    const unsigned int * b_state; // LOW or HIGH
    const unsigned int * b_mode; // INPUT or OUTPUT
};
#endif
