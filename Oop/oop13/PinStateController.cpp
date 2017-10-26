#include "PinStateController.h"

PinStateController::PinStateController(unsigned int _n_outputNum, unsigned int _n_inputNum, const unsigned int * _b_initState) {
  for (unsigned int i = 0; i < _n_outputNum; i++) {
    for (unsigned int j = 0; j < _n_inputNum; j++) {
      beforeState[i][j] = _b_initState;
      currentState[i][j] = _b_initState;
    }
  }
}

void PinStateController::updateState(unsigned int _n_outputNum, unsigned int _n_inputNum, const unsigned int * _b_updateState) {
  currentState[_n_outputNum][_n_inputNum] = _b_updateState;
}

// bool same(unsigned int _n_outputNum, unsigned int _n_inputNum) {
//   // if (beforeState[_n_output][_n_input] == currentState[_n_output][_n_input]) {
//   //   return TRUE;
//   // }
//   // return FALSE;
// }
