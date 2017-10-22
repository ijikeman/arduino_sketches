//#include <stdio.h>
//#include "controllers/PinsController.h"
#include "PinsController.h"
#include "config.h"

//int main() {
void setup() {
  PinsController colPins = PinsController();
  colPins.Num(COL_PINS, sizeof(COL_PINS)/sizeof(unsigned int));
  colPins.Mode(OUTPUT);
  colPins.State(HIGH);
}

void loop() {

}
