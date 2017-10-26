#include "MatrixController.h"
#include "PinsController.h"
#include "PinStateController.h"

MatrixController::MatrixController(PinsController * _outputPins, PinsController * _inputPins, unsigned int _b_initialState) {
  outputPins = _outputPins;
  inputPins = _inputPins;
  // n_maxXPos = *(*outputPins).currentTotal();
  // n_maxYPos = *(*inputPins).currentTotal();
  // n_xPos = 0;
  // n_yPos = 0;
  // PinStateController pinState = PinStateController(n_maxXPos, n_maxYPos, _b_initialState) 
}

void MatrixController::Start() {
 // bool state = 0;
//   // // unsigned int n_inputNum = (*inputPins).TotalNumber();
//   // // bool b_currentState[n_outputNum][n_inputNum];
//   // // bool b_beforeState[n_outputNum][n_inputNum];
  // for (unsigned int i = 0; i < n_maxXPos; i++) {
  //   for (unsigned int j = 0; j < n_maxYPos; j++) {
  //     (*inputPins).reverseState();
  //     pinState.updateState(i, j, (*(*inputPins[j])).currentState());
  //   }
  // }
//   return 1;
}
