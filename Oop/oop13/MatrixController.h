#ifndef MatrixController_h
#define MatrixController_h
#include "PinsController.h"
#include "PinStateController.h"

class MatrixController {
  public:
    MatrixController(PinsController * _outputPins, PinsController * _inputPins, bool _b_initialState);
    // unsigned int Read();
  private:
    PinsController * inputPins;
    PinsController * outputPins;
    PinStateController pinState;
};
#endif
