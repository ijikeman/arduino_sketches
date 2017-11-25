#ifndef MatrixController_h
#define MatrixController_h
#include "PinController.h"

class MatrixController {
  public:
    MatrixController(unsigned int * p_auiOutpuPinNumbers, unsigned int uiOutputPinNumbersOf, unsigned int * p_auiInputPinNumbers, unsigned int uiInputPinNumbersOf);
    bool scan();
  private:
    // unsigned int m_uiOutputPinNumbersOf;
    // unsigned int m_uiInputPinNumbersOf;
    // unsigned int m_uiOutputCurrentNumber = 0;
    // unsigned int m_uiInputCurrentNumber = 0;
    // PinController * p_acOutputPins[10];
    // PinController * p_acInputPins[10];
};
#endif
