#include "PinsController.h"
//PinsController::PinsController(unsigined int _n_pin_num) {
#include <vector>
#include <iostream>
PinsController::PinsController() {
}

void PinsController::setNo(unsigned int * p_array_nos, unsigned int size) {
  for (int i = 0; i < size; i++) {
    PinController pin = PinController();
    pin.setNo(p_array_nos[i]);
    v_pins.push_back(&pin);
  //   printf("%d : ", p_array_nos[i]);
  //   printf("%d\n", i);
  //   printf("Size: %lu\n", v_pins.size());
  //   printf("%d\n",(*v_pins[i]).getNo());
  }
}

void PinsController::getNo() {
  // int sum = 0;
  // printf("%d\n", (*v_pins[sum]).getNo());
  // printf("%d\n", (*v_pins[1]).getNo());
  // printf("%d\n", (*v_pins[2]).getNo());

  for (std::vector<PinController*>::iterator itr=v_pins.begin();itr != v_pins.end(); itr++) {
    printf("%d\n", (**itr).getNo());
//    printf("%d\n", sum);
  	// sum++;
  }
//  printf("Size:: %lu\n", v_pins.size());


}
