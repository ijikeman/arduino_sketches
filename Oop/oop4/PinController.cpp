#include "PinController.h"
#include <stdio.h>

PinController::PinController(int pins) {
  p = pins;
}
void PinController::pinMode() {
  printf("%d\n", p);
}

