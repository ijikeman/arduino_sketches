#ifndef SerialController_h
#define SerialController_h

#define KEYBOARD 0 // keyboard mode
#define MOUSE 1 // mouse mode

class SerialController {
  public:
    SerialController(unsigned int beginRate);
    void makeData(bool _mode, bool _second, unsigned int _third, unsigned int _forth);
    void sendToMaster();
    int available();
    unsigned char data;
  private:
};

#endif
