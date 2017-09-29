#include <Keyboard.h>
#include "Keydefine.h"

// Let's Split
// const int inputNum = 6;
// const int outputNum = 4;
// const int inputPins[inputNum] = {19, 18, 15, 14, 16, 10};
// const int outputPins[outputNum] = {6, 7, 8, 9};
//const byte keyMap[outputNum][inputNum]  = {
//   {KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T},
//   {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
//   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
//   {KC_ESC,  NONE,    KC_LALT, KC_LGUI, NONE,   KC_SPC}
//};

// Maxipad
const int inputNum = 6;
const int outputNum = 5;
const int inputPins[inputNum] =  {21, 5, 6, 20, 8, 9};
const int outputPins[outputNum] ={10, 16, 14, 15, 18};
const byte keyMap[outputNum][inputNum]  = {
   {KC_QUOT, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T},
   {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
   {KC_ESC,  NONE,    KC_LALT,   KC_LGUI, NONE, KC_SPC}
};

bool currentState[outputNum][inputNum], beforeState[outputNum][inputNum];
int i, j;


void setup() {
  Serial.begin(9600);

  for ( i = 0; i < outputNum; i++) {
    pinMode(outputPins[i], OUTPUT); // set to OUTPUT and LOW(0v) on all OutputPin
    digitalWrite(outputPins[i], LOW); // set to HIGH(5V) on all OutputPins
    for (j = 0; j < inputNum; j++) {
      pinMode(inputPins[j], INPUT); // set to INPUT and LOW on all InputPin
      digitalWrite(inputPins[j], HIGH); // set pullup(already 5V) to all InputPin = pinMode(inputPins[j], INPUT_PULLUP)
      beforeState[i][j] = currentState[i][j] = HIGH; // initial to curentState, beforeState
    }
  }
  Keyboard.begin();
}

void loop() {
  for ( i = 0; i < outputNum; i++) {
    // 対象OUTPUTPinの列の６個に電流が流れる
    digitalWrite(outputPins[i], LOW); // set one outputPin to 0V for a temporarily priod of time
    for (j = 0; j < inputNum; j++) {
      // pushするとそのinputPinは断線状態となり電流が流れずLOWとなる
      currentState[i][j] = digitalRead(inputPins[j]); // read InputPin and judge Push(LOW=0V), or Not_Push(HIGH=5V) on Switch
      if (beforeState[i][j] != currentState[i][j]) {
          Serial.print(i);
          Serial.print(":");
          Serial.print(j);
        if (currentState[i][j] == LOW) {
          Keyboard.press(keyMap[i][j]);
          Serial.print(keyMap[i][j]);
          Serial.println(" push");
        } else {
          Keyboard.release(keyMap[i][j]);
          Serial.print(keyMap[i][j]);
          Serial.println(" release");
        }
        beforeState[i][j] = currentState[i][j];
      }
    }
    digitalWrite(outputPins[i], HIGH); // reset the outputPin to HIGH(5V)
  }
  delay(10);
}
