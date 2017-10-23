#include "MatrixController.h"
#include "PinsController.h"
#include "PinController.h"

MatrixController::MatrixController(PinsController *_inputPins, PinsController *_outputPins) {
  inputPins = _inputPins;
  outputPins = _outputPins;
}

unsigned int MatrixController::Read() {
  // bool b_state = 0;
  // unsigned int n_outputNum = (*outputPins).TotalNumber();
  // unsigned int n_inputNum = (*inputPins).TotalNumber();
  // bool b_currentState[n_outputNum][n_inputNum];
  // bool b_beforeState[n_outputNum][n_inputNum];
  // for (int i = 0; i < n_outputNum; i++) {
  // 	PinController * outPin = outputPins.Pin(1);
  // 	for (int j = 0; j < n_inputNum; j++) {
      
  // 	}
  // }
  // return 1;
}
