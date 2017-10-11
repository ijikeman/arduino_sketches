#include "config.h"
#include "PinController.h"

PinController colPin = PinController();
int main() {
   colPin.setPins(COL_NUM);
   colPin.pinMode(); // INPUT, HIGH
    return 0;
}
