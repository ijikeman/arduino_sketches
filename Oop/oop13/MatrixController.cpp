#include "MatrixController.h"
#include "PinsController.h"
// #include "PinController.h"

MatrixController::MatrixController() {
}

void MatrixController::OutputPins(PinsController * _pins) {
  outputPins = _pins;
}

PinsController * MatrixController::OutputPins() {
  return outputPins;
}

void MatrixController::InputPins(PinsController * _pins) {
  inputPins = _pins;
}

PinsController * MatrixController::InputPins() {
  return inputPins;
}

void MatrixController::InitialState() {
  for (unsigned int i = 0; i < *(*outputPins).TotalNumber(); i++) {
    for (unsigned int j = 0; j < *(*inputPins).TotalNumber(); j++) {
      // b_beforeState[i][j] = *(*(*inputPins).parray_pins[j]).State();
    }
  }
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
