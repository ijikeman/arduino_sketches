#include "MatrixController.h"
#include "PinsController.h"
#include "PinStateController.h"

MatrixController::MatrixController(PinsController * _outputPins, PinsController * _inputPins, bool _b_initialState) {
  outputPins = _outputPins;
  inputPins = _inputPins;

  PinStateController PinState = PinStateController(*(*outputPins).currentTotal(), *(*inputPins).currentTotal(), _b_initialState) 
}

// unsigned int MatrixController::Read() {
//   // bool state = 0;
//   // // unsigned int n_inputNum = (*inputPins).TotalNumber();
//   // // bool b_currentState[n_outputNum][n_inputNum];
//   // // bool b_beforeState[n_outputNum][n_inputNum];
//   // for (unsigned int i = 0; i < *(*outputPins).TotalNumber(); i++) {
//   //   state = (*outputPins).parray_pins[i].State;
//   //   for (unsigned int j = 0; j < *(*inputPins).TotalNumber(); j++) {
//   //   }
//   // }
//   return 1;
// }
