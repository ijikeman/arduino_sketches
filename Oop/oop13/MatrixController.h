#ifndef MatrixController_h
#define MatrixController_h
#include "PinsController.h"
const static unsigned int MAX_INPUT_PIN = 20;
const static unsigned int MAX_OUTPUT_PIN = 20;

class MatrixController {
  public:
    MatrixController();
    void OutputPins(PinsController * _pins);
    void InputPins(PinsController * _pins);
    PinsController * OutputPins();
    PinsController * InputPins();
    void InitialState();
    // unsigned int Read();
  private:
    PinsController * inputPins;
    PinsController * outputPins;
    bool b_beforeState[MAX_OUTPUT_PIN][MAX_INPUT_PIN];
    bool b_currentState[MAX_OUTPUT_PIN][MAX_INPUT_PIN];
};
#endif
