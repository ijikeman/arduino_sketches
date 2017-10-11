#include "PinController.h"
#include <stdio.h>

PinController::PinController() {
}
void PinController::setPins(int p) {
  pins=&p;
}
void PinController::pinMode() {
  printf("%d\n", *pins);
}

