#ifndef SerialController_h
#define SerialController_h

#define KEYBOARD 0 // keyboard mode
#define MOUSE 1 // mouse mode

#define SHIFT(val, num) ((unsigned int)val << (num))
#define UNSHIFT(val, num) ((unsigned int)val >> (num))
#define SHIFT_MK(val) SHIFT(val, 7)
#define UNSHIFT_MK(val) UNSHIFT(val, 7)
// KEYBOARD
#define SHIFT_PUSH_RELEASE(val) SHIFT(val, 6)
#define SHIFT_ROW(val) SHIFT(val, 3)
#define SHIFT_COL(val) SHIFT(val, 0)
#define UNSHIFT_PUSH_RELEASE(val) UNSHIFT(val, 6) & 0x01000000
#define UNSHIFT_ROW(val) UNSHIFT(val, 3) & 0x00111000
#define UNSHIFT_COL(val) UNSHIFT(val, 0) & 0x00000111

// MOUSE
#define SHIFT_X_Y(val) SHIFT(val, 6)
#define SHIFT_MINUS_PLUS(val) SHIFT(val, 5)
#define SHIFT_RANGE(val) SHIFT(val, 0)
#define UNSHIFT_X_Y(val) UNSHIFT(val, 6) & 0x01000000
#define UNSHIFT_MINUS_PLUS(val) UNSHIFT(val, 5) & 0x00100000
#define UNSHIFT_RANGE(val) UNSHIFT(val, 0) & 0x00011111

class SerialController {
  public:
    SerialController(unsigned int beginRate);
    void makeData(bool _mode, bool _second, unsigned int _third, unsigned int _forth);
    void sendToMaster();
    void recieveToSlave();
    bool isKeyboard();
    bool isMouse();
    int available();
    unsigned char data;
  private:
};

#endif
