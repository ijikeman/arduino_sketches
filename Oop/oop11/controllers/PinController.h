#ifndef PinController_h
#define PinController_h
class PinController {
  public:
    PinController();
    void setNo(unsigned int _n_no);
    unsigned int getNo();
    void setState(bool _b_state);
    bool getState();
    void setMode(bool _b_mode);
    bool getMode();
  private:
    unsigned int n_no; // Pin Number
    bool b_state; // LOW or HIGH
    bool b_mode; // INPUT or OUTPUT
};
#endif