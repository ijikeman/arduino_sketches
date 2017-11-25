#include "stdio.h"

class PinController {
  public:
    PinController(int num) {
      m_num = num;
    }
    int get() {
      return m_num;
    }
  private:
    int m_num;
};

class PinsController {
  public:
    PinsController() {
      m_index = 0;
    }
    void set(PinController * pin) {
      m_num[m_index] = pin;
      m_index++;
    }
    PinController * get(int num) {
      return m_num[num];
    }
  private:
    PinController * m_num[5];
    int m_index;
};

int main() {
  PinsController * pins = new PinsController();
  for (int i=0; i < 5; i++) {
    PinController * pin = new PinController(i);
    pins->set(pin);
    printf("set=%d\n", pin->get());
    printf("set=%x\n", pin);
  }

  for (int j = 0; j < 5; j++) {
    PinController * getpin = pins->get(j);
    printf("get=%d\n", getpin->get());
    printf("get=%x\n", getpin);
  }
}
