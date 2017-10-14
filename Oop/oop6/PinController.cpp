#include "PinController.h"
#include <stdio.h>

PinController::PinController(const int * p, const int * n) {
  pins = p;
  pin_num = n;
}
void PinController::pinMode(bool mode, bool inOrOut) {
  for (int i = 0; i < *pin_num; i++) {
    printf("%d:%d:%d\n", pins[i], mode, inOrOut);
  }
}

