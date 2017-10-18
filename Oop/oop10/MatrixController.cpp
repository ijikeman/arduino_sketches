#include "MatrixController.h"
#include "config.h"
#include "Arduino.h"
MatrixController::MatrixController (const int * _outPins, const int * _outPinNum, const int * _inPins, const int * _inPinNum) {
  outPins = _outPins;
  outPinNum = _outPinNum;
  inPins = _inPins;
  inPinNum = _inPinNum;
  out = 255;
  in = 255;
  pushPull = 0;
}

void MatrixController::initialState(bool state) {
  for (int i = 0; i < *outPinNum; i++) {
    for (int j = 0; j < *inPinNum; j++) {
      currentState[i][j] = state;
      beforeState[i][j] = state;
    }
  }
}

bool MatrixController::read() {
  bool state = 0;
  for (int i = 0; i < *outPinNum; i++) {
    // Chanage reverse on OutputPin's state
    state = digitalRead(outPins[i]);
    digitalWrite(outPins[i], !state);
    for (int j = 0; j < *inPinNum; j++) {
      // Read InputPin's state
      currentState[i][j] = digitalRead(inPins[j]);
#ifdef DEBUG
      Serial.print(currentState[i][j]);
      Serial.print(":");
#endif
      // if Input Pin's State is change
      if (beforeState[i][j] != currentState[i][j]) {
        beforeState[i][j] = currentState[i][j];
        // Set pin numbers
        pushPull = currentState[i][j];
        out = i;
        in = j;
        // Reset Output Pin's state
        digitalWrite(outPins[i], state);
#ifdef DEBUG
        Serial.println("");
        Serial.print(out);
        Serial.print(":");
        Serial.print(in);
        Serial.print(":");
        Serial.println(pushPull);
#endif
        return 1;
      }
    }
    // Reset Output Pin's state
    digitalWrite(outPins[i], state);
  }
  Serial.println("");
  return 0;
}
