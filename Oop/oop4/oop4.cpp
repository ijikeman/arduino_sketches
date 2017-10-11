#include "config.h"
#include "PinController.h"

PinController colPin = PinController(COL_NUM);
int main() {
   colPin.pinMode(); // INPUT, HIGH
    return 0;
}
