#include "config.h"
#include "PinController.h"
#include "MatrixController.h"
#include "SerialController.h"
#include "KeyboardController.h"

PinController rowPins = PinController(ROW_PINS, &ROW_NUM);
PinController colPins = PinController(COL_PINS, &COL_NUM);
#ifdef COL_TO_ROW
MatrixController matrix = MatrixController(ROW_PINS, &ROW_NUM, COL_PINS, &COL_NUM);
#else
MatrixController matrix = MatrixController(COL_PINS, &COL_NUM, ROW_PINS, &ROW_NUM);
#endif
SerialController serialCont = SerialController(9600);
KeyboardController keyboardCont = KeyboardController();

void setup() {
  Serial.begin(9600);
  rowPins.pinModeAll(OUTPUT);
  rowPins.digitalWriteAll(HIGH); // OUTPUT, HIGH
  colPins.pinModeAll(INPUT);
  colPins.digitalWriteAll(HIGH); // INPUT, HIGH
  matrix.initialState(HIGH);
}

void loop() {
  if (serialCont.available()) {
//    serialCont.recieveToSlave();
  } else if (matrix.read()) {
    serialCont.makeData(KEYBOARD, matrix.pushPull, matrix.out, matrix.in);
    serialCont.sendToMaster();
    keyboardCont.input(&matrix);
  }
  // switch (serialCont.data >> 7) {
  // case KEYBOARD:
  //   keyboardCont.setData(serialCont.data);
  // case MOUSE:
  //   mouseCont.setData(serialCont.data);
  // }
  delay(10);
}
