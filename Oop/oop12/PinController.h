#ifndef PinController_h
#define PinController_h
class PinController {
  public:
    PinController();
    void Num(unsigned int _n_num);
    unsigned int Num();
    void State(bool _b_state);
    bool State();
    void Mode(bool _b_mode);
    bool Mode();
  private:
    unsigned int n_num; // Pin Number
    bool b_state; // LOW or HIGH
    bool b_mode; // INPUT or OUTPUT
};
#endif