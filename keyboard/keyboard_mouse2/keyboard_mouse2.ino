#include "Keydefine.h"
#include <Keyboard.h>

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
const byte keyMap[outputNum*2][inputNum*2]  = {
   {KC_QUOT, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T},
   {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
   {KC_ESC,  NONE,    KC_LALT,   KC_LGUI, NONE, KC_SPC},

   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC},
   {KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT},
   {KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_QUOT},
   {KC_BSPC, NONE,    KC_LEFT, KC_DOWN,KC_UP,   KC_RGHT}
};

bool currentState[outputNum][inputNum], beforeState[outputNum][inputNum];
int i, j;
byte sendData, readData;
byte isPress, keyboardOrMouse, col, row;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8E1);
  Keyboard.begin();

  for ( i = 0; i < outputNum; i++) {
    pinMode(outputPins[i], OUTPUT); // set to OUTPUT and LOW(0v) on all OutputPin
    digitalWrite(outputPins[i], LOW); // set to HIGH(5V) on all OutputPins
    for (j = 0; j < inputNum; j++) {
      pinMode(inputPins[j], INPUT); // set to INPUT and LOW on all InputPin
      digitalWrite(inputPins[j], HIGH); // set pullup(already 5V) to all InputPin = pinMode(inputPins[j], INPUT_PULLUP)
      beforeState[i][j] = currentState[i][j] = HIGH; // initial to curentState, beforeState
    }
  }
}

void loop() {
  digitalWrite(17, LOW);
  for ( i = 0; i < outputNum; i++) {
    // 対象OUTPUTPinの列の６個に電流が流れる
    digitalWrite(outputPins[i], LOW); // set one outputPin to 0V for a temporarily priod of time
    for (j = 0; j < inputNum; j++) {
      // pushするとそのinputPinは断線状態となり電流が流れずLOWとなる
      currentState[i][j] = digitalRead(inputPins[j]); // read InputPin and judge Push(LOW=0V), or Not_Push(HIGH=5V) on Switch
      if (beforeState[i][j] != currentState[i][j]) {
        keyboardOrMouse = 1;
        if (currentState[i][j] == LOW) {
          Keyboard.press(keyMap[i][j]);
          Serial.print(keyMap[i][j]);
          Serial.println(" push");
          isPress = 1;
        } else {
          Keyboard.release(keyMap[i][j]);
          Serial.print(keyMap[i][j]);
          Serial.println(" release");
          isPress = 0;
        }
        beforeState[i][j] = currentState[i][j];
        // convert 8bit data
        sendData = keyboardOrMouse << 7 | isPress << 6| i << 3 | j;
        Serial1.write(sendData);
        Serial.println(sendData);
        digitalWrite(17, HIGH);
      }
    }
    digitalWrite(outputPins[i], HIGH); // reset the outputPin to HIGH(5V)
  }

  // 相手側から来たとき
  if (Serial1.available()) {
    keyboardOrMouse = isPress = col = row = 0;
    digitalWrite(17, HIGH);
    readData = Serial1.read();
    Serial.println(readData);
    keyboardOrMouse = readData >> 7;
//    if (keyboardOrMouse  == 1) {
      isPress = (readData & 0b01000000) >> 6;
      col = (readData & 0b00111000) >> 3;
      row = readData & 0b00000111;
      Serial.print(keyboardOrMouse);
      Serial.print(":");
      Serial.print(isPress);
      Serial.print(":");
      Serial.print(col);
      Serial.print(":");
      Serial.println(row);
      if (isPress == 1) {
        Keyboard.press(keyMap[outputNum+col][row]);
      }
      else {
        Keyboard.release(keyMap[outputNum+col][row]);
      }
    // Mouse Mode
//    } else {
//    }
  }
  delay(10);
}
