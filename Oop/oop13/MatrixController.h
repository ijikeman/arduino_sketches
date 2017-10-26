#ifndef MatrixController_h
#define MatrixController_h
#include "PinsController.h"
#include "PinStateController.h"

class MatrixController {
  public:
    MatrixController(PinsController * _outputPins, PinsController * _inputPins, unsigned int _b_initialState);
    void Start();
  private:
    PinsController * inputPins;
    PinsController * outputPins;
    // PinStateController pinState;
    unsigned int n_xPos;
    unsigned int n_yPos;
    unsigned int n_maxXPos;
    unsigned int n_maxYPos;
};
#endif
