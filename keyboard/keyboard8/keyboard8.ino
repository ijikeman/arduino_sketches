#include "Mouse.h"
#include "Keydefine.h"
#include "Keyboard.h"

const int outputNum = 6;
const int inputNum = 4;
const int outputPins[outputNum] = {19, 18, 15, 14, 16, 10};
const int inputPins[inputNum] = {6, 7, 8, 9};

const byte keymap[inputNum][outputNum] = {
  {KC_A, KC_B, KC_C, KC_D, KC_E, KC_F},
  {KC_G, KC_H, KC_I, KC_J, KC_K, KC_L},
  {KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R},
  {KC_S, KC_T, KC_U, KC_V, KC_W, KC_X}
};

bool currentState[inputNum][outputNum];
bool beforeState[inputNum][outputNum];
bool inputState;
int i, j;

void setup() {
  for (i = 0; i < outputNum; i++) {
    pinMode(outputPins[i], OUTPUT);
    digitalWrite(outputPins, HIGH);
    for (j = 0; j < inputNum; j++) {
      pinMode(inputPins, INPUT_PULLUP);
      currentState[j][i] = beforeState[j][i] = HIGH;
    }
  }
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (i = 0; i < outputNum; i++) {
    digitalWrite(outputPins[i], LOW);
    for (j = 0; j < inputNum; j++) {
      inputState = digitalRead(inputPins[j]);
      currentState[j][i] = inputState;
      if ((currentState[j][i] != beforeState[j][i]) && (inputState == LOW)) {
        beforeState[j][i] = currentState[j][i];
        Keyboard.press(keymap[j][i]);
        Serial.print(keymap[j][i]);
        Serial.println(" push");
      } else {
        Keyboard.release(keymap[j][i]);
        Serial.print(keymap[j][i]);
        Serial.println(" release");
      }
    }
  }
	delay(10);
}
