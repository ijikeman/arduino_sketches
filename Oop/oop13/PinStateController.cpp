#include "PinStateController.h"

PinStateController::PinStateController(unsigned int _n_output, unsigned int _n_input, bool _b_initState) {
  for (int i = 0; i < _n_output; i++) {
    for (int j = 0; j < _n_input; j++) {
      beforeState[i][j] = _b_initState;
      currentState[i][j] = _b_initState;
    }
  }
}

void PinStateController::changeState(unsigned int _n_output, unsigned int _n_input, bool _b_changeState) {
  currentState[_n_output][_n_input] = _b_changeState;
}

bool same(unsigned int _n_output, unsigned int _n_input) {
  // if (beforeState[_n_output][_n_input] == currentState[_n_output][_n_input]) {
  //   return TRUE;
  // }
  // return FALSE;
}
