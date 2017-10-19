#include <stdio.h>
#include "controllers/PinsController.h"

int main() {
//void setup() {
  PinsController colPins = PinsController();
  unsigned int a[] = {4, 5, 9};
  colPins.setNo(a, sizeof(a)/sizeof(unsigned int));
  colPins.getNo();
//  pin.setNo(8);
//  pin.setMode(1);
//  pin.setState(0);
//  printf("%d\n", pin.getNo());
}

void loop() {

}
