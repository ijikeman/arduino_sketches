#ifndef MatrixController_h
#define MatrixController_h
#include "PinsController.h"
class MatrixController {
  public:
  	MatrixController(PinsController *_inputPins, PinsController *_outputPins);
    unsigned int Read();
  private:
  	PinsController *inputPins;
  	PinsController *outputPins;
};
#endif
