#include "stdio.h"

class PinController {
  public:
    PinController() {
      m_index = 0;
    }
    void set(unsigned int num) {
      m_num[m_index] = num;
      m_index++;
    }
    unsigned int get(unsigned int num) {
      return m_num[num];
    }
  private:
    unsigned int m_num[10];
    unsigned int m_index;
};

int main() {
  PinController pin = PinController();
  for (unsigned int i=0; i < 5; i++) {
    pin.set(i);
    printf("%d\n", pin.get(i));
  }

  for (unsigned int j = 0; j < 5; j++) {
    printf("%d\n", pin.get(j));
  }
}

