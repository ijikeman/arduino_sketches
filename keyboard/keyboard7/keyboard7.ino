#include "Keydefine.h"
#include "Keyboard.h"

const int outputNum = 5;
const int inputNum = 6;
const int inputPins[inputNum] = {21, 5, 6, 20, 8, 9 };
const int outputPins[outputNum] = {10, 16, 14, 15, 18};

const byte keymap[inputNum][outputNum] = {
  {KC_A, KC_B, KC_C, KC_D, KC_E},
  {KC_G, KC_H, KC_I, KC_J, KC_K},
  {KC_M, KC_N, KC_O, KC_P, KC_Q},
  {KC_S, KC_T, KC_U, KC_V, KC_W},
  {KC_1, KC_2, KC_5, KC_8, KC_X},
  {KC_3, KC_4, KC_6, KC_7, KC_Z}

};

bool currentState[inputNum][outputNum];
bool beforeState[inputNum][outputNum];
bool inputState;
int i, j;

void setup() {
  for (i = 0; i < outputNum; i++) {
    pinMode(outputPins[i], OUTPUT);
    digitalWrite(outputPins[i], HIGH);
    for (j = 0; j < inputNum; j++) {
      pinMode(inputPins[j], INPUT_PULLUP);
      currentState[j][i] = beforeState[j][i] = HIGH;
    }
  }
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (i = 0; i < outputNum; i++) {
    digitalWrite(outputPins[i], HIGH);
    for (j = 0; j < inputNum; j++) {
      inputState = digitalRead(inputPins[j]);
      currentState[j][i] = inputState;
      if (currentState[j][i] != beforeState[j][i]) {
        beforeState[j][i] = currentState[j][i];
        if (inputState == LOW) {
//          Keyboard.press(keymap[j][i]);
          Serial.print(keymap[j][i]);
          Serial.println(" push");
        } else {
//          Keyboard.release(keymap[j][i]);
          Serial.print(keymap[j][i]);
          Serial.println(" release");
        }
      }
    }
    digitalWrite(outputPins[i], LOW);
  }
	delay(10);
}
