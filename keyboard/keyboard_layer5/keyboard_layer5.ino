#include "Keydefine.h"
#include <Keyboard.h>
#include "Mouse.h"

// LAYERS
#define BASE 0
#define UPPER 1
#define LOWER 2

// DATA FORMAT F=FUNCTION, L=LAYER, K=KEYCODE
// FFFFLLLLKKKKKKKK
#define FUNCTION 0b1111000000000000
#define LAYER 0b0000111100000000
#define KEYCODE 0b0000000011111111

//FUNCTIONS
#define FUNC_NONE 0b000000000000
#define FUNC_LT 0b000100000000

// LT MACRO
#define LT(layer,key) (unsigned int)(1 << 12| layer << 8 | key)

#define TRUE 1
#define FALSE 0

#define MAX_STOCK_KEYCODE_NUM 8
byte pressKeycodes[MAX_STOCK_KEYCODE_NUM];
unsigned int pressKeycodeNum = 0;
byte baseLayer = BASE;
byte currentLayer = BASE;
byte beforeLayer = BASE;

// Maxipad
const int inputNum = 6;
const int outputNum = 5;
const int inputPins[inputNum] =  {21, 5, 6, 20, 8, 9};
const int outputPins[outputNum] ={10, 16, 14, 15, 18};
const int keyMap[][outputNum*2][inputNum*2]  = {
  [BASE] = {
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T},
   {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
   {KC_ESC,  NONE,    KC_LALT, KC_LGUI,LT(UPPER, _______), KC_SPC},

   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC},
   {KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT},
   {KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_QUOT},
   {KC_BSPC, LT(LOWER, _______),  KC_LEFT, KC_DOWN,KC_UP, KC_RGHT}
  },

  [UPPER] = {
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_CHIL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC},
   {KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
   {KC_ESC,  NONE,    KC_LALT, KC_LGUI,LT(UPPER, _______), KC_SPC},

   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_USCR},
   {KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT},
   {KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_BSLS},
   {KC_DEL,  KC_EQL,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
  },

  [LOWER] = {
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
   {KC_ESC,  NONE,    KC_LALT, KC_LGUI,KC_RBRC, KC_SPC},

   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT},
   {KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_QUOT},
   {KC_DEL, LT(LOWER, _______), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
  }

  // [UPPER] = {
  //  {_______, _______, _______, _______, _______, _______ },
  //  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC },
  //  {_______, _______, _______, _______, _______, _______ },
  //  {_______, _______, _______, _______, _______, _______ },
  //  {_______, _______, _______, _______, LT(UPPER, _______), _______ },

  //  {_______, _______, _______, _______, _______, _______ },
  //  {KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL },
  //  {_______, _______, _______, _______, _______, _______ },
  //  {_______, _______, _______, _______, _______, _______ },
  //  {KC_DEL, LT(LOWER, _______), _______, _______, _______, _______ }
  // },



  // [LOWER] = {
  //  {_______, _______, _______, _______, _______, _______ },
  //  {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
  //  {_______, _______, _______, _______, _______, _______ },
  //  {_______, _______, _______, _______, _______, _______ },
  //  {_______, _______, _______, _______, LT(UPPER, _______), _______ },

  //  {_______, _______, _______, _______, _______, _______ },
  //  {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
  //  {_______, _______, _______, _______, _______, _______ },
  //  {_______, _______, _______, _______, _______, _______ },
  //  {KC_DEL, LT(LOWER, _______), _______, _______, _______, _______ }
  // }
};


const int mouseButton = 7;    // input pin for the mouse pushButton
const int xAxis = A1;         // joystick X axis
const int yAxis = A6;         // joystick Y axis
const bool xReverse = 0;
const bool yReverse = 0;

// parameters for reading the joystick:
int range = 20;               // output range of X or Y movement
//int threshold = range / 4;    // resting threshold
int center = range/2;       // resting position value
bool currentMouseButtonStatus = HIGH;
bool beforeMouseButtonStatus = HIGH;

// Serial Data
bool currentState[outputNum][inputNum], beforeState[outputNum][inputNum];
int i, j;
byte sendData, readData;
byte isPress, keyboardOrMouse, col, row;
byte mouseXOrY, mouseMinusX, mouseDistanceX, mouseMinusY, mouseDistanceY;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8E1);
  Keyboard.begin();
  // take control of the mouse:
  Mouse.begin();
  pinMode(mouseButton, INPUT_PULLUP);

  // initial keyboardState And Pin Mode
  for ( i = 0; i < outputNum; i++) {
    pinMode(outputPins[i], OUTPUT); // set to OUTPUT and LOW(0v) on all OutputPin
    digitalWrite(outputPins[i], LOW); // set to HIGH(5V) on all OutputPins
    for (j = 0; j < inputNum; j++) {
      pinMode(inputPins[j], INPUT); // set to INPUT and LOW on all InputPin
      digitalWrite(inputPins[j], HIGH); // set pullup(already 5V) to all InputPin = pinMode(inputPins[j], INPUT_PULLUP)
      beforeState[i][j] = currentState[i][j] = HIGH; // initial to curentState, beforeState
    }
  }

  // initial pressKeycodes
  for (int k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {
    pressKeycodes[k] = 0xFF;
  }
}


void loop() {
  int k;
  // LEF Off
  digitalWrite(17, LOW);
  for ( i = 0; i < outputNum; i++) {
    // 対象OUTPUTPinの列の６個に電流が流れる
    digitalWrite(outputPins[i], LOW); // set one outputPin to 0V for a temporarily priod of time
    for (j = 0; j < inputNum; j++) {
      // pushするとそのinputPinは断線状態となり電流が流れずLOWとなる
      currentState[i][j] = digitalRead(inputPins[j]); // read InputPin and judge Push(LOW=0V), or Not_Push(HIGH=5V) on Switch

      currentState[i][j] = digitalRead(inputPins[j]);
      if (beforeState[i][j] != currentState[i][j]) {
        keyboardOrMouse = 1;

        int keyData = keyMap[currentLayer][i][j];
        // get function
        int func = (keyData & FUNCTION) >> 12;
        // get layer
        int switchLayer = (keyData & LAYER) >> 8;
        // get keycode
        int keycode = keyData & KEYCODE;
        // press
        if (currentState[i][j] == LOW) {
          // switch layer
          switch(func) {
            case 0:
                Keyboard.press(keycode);
                // LT, MO実装の為 pressしたkeycodeをストック
                for (k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {
                  if (pressKeycodes[k] == 0xFF) {
                    pressKeycodes[k] = keycode;
                    pressKeycodeNum++;
                    break;
                  }
                }
              break;
            case 1: // Layer Tap(LT) MO
                currentLayer = switchLayer;
              break;
            default:
              break;
          }
          isPress = 1;
        // release
        } else {
          // switch layer
          switch(func) {
            case 0:
              // pressKeycodesからreleaseされたものは省く
              for (k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {
                if (pressKeycodes[k] == keycode) {
                  // layerが切り替わりで無意味なreleaseは避ける
                  Keyboard.release(keycode);
                  pressKeycodes[k] = 0xFF;
                  pressKeycodeNum--;
                  break;
                }
              }
              break;
            // LayerをbaseLayerに戻す
            case 1: // layer Tap(LT), MO
                // layerが元に戻った場合はreleaseが行われていないキーはreleaseする(本当はLayer戻しの予約だけして処理を終了し、StockKeycodeがなくなったタイミングで発動させるほうがいい)
                for (k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {
                  if (pressKeycodes[k] != 0xFF) {
                    Keyboard.release(pressKeycodes[k]);
                    pressKeycodes[k] = 0xFF;
                    pressKeycodeNum--;
                  }
                }
                currentLayer = baseLayer;
              break;
            default:
              break;
          }
          isPress = 0;
        }
        beforeState[i][j] = currentState[i][j];
        // convert 8bit data
        sendData = keyboardOrMouse << 7 | isPress << 6| i << 3 | j;
        Serial1.write(sendData);
        // digitalWrite(17, HIGH);
        // Serial.print("keyData=");
        // Serial.println(keyData);
        // Serial.print("func=");
        // Serial.println(func);
        // Serial.print("cLayer=");
        // Serial.println(switchLayer);
        // Serial.print("sLayer=");
        // Serial.println(currentLayer);
        // Serial.print("bLayer=");
        // Serial.println(beforeLayer);
        // Serial.print("keycode=");
        // Serial.println(keycode);
        // Serial.print("pressKeycodeNum=");
        // Serial.println(pressKeycodeNum);
        // Serial.print("pressKeycode=");
        // for (k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {a
        //      Serial.print(pressKeycodes[k]);
        // }
        // Serial.println("");
      }
    }
    digitalWrite(outputPins[i], HIGH); // reset the outputPin to HIGH(5V)
  }

  // Mouse
  // read and scale the two axes:
  int xReading = readAxis(xAxis, xReverse);
  int yReading = readAxis(yAxis, yReverse);

  // if the mouse control state is active, move the mouse:
  if ((xReading != 0) || (yReading != 0)) {
    Serial1.write(makeMouseData(xReading, 0));
    Serial1.write(makeMouseData(yReading, 1));
  }
  Mouse.move(xReading, yReading, 0);

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  currentMouseButtonStatus = digitalRead(mouseButton);
  if (beforeMouseButtonStatus != currentMouseButtonStatus) {
    beforeMouseButtonStatus = currentMouseButtonStatus;
    if (currentMouseButtonStatus == LOW) {
      Mouse.press(MOUSE_LEFT);
    } else {
      Mouse.release(MOUSE_LEFT);
    }
  }

  // 相手側から来たとき
  if (Serial1.available()) {
    keyboardOrMouse = isPress = col = row = mouseXOrY = mouseMinusX = mouseDistanceX = mouseMinusY = mouseDistanceY =0;
    digitalWrite(17, HIGH);
    readData = Serial1.read();
    keyboardOrMouse = readData >> 7;
    if (keyboardOrMouse  == 1) {
      isPress = (readData & 0b01000000) >> 6;
      col = (readData & 0b00111000) >> 3;
      row = readData & 0b00000111;

      int keyData = keyMap[currentLayer][outputNum+col][row];
      // get function
      int func = (keyData & FUNCTION) >> 12;
      // get layer
      int switchLayer = (keyData & LAYER) >> 8;
      // get keycode
      int keycode = keyData & KEYCODE;

      // press
      if (isPress == 1) {
        // switch layer
        switch(func) {
          case 0:
            Keyboard.press(keycode);
            // LT, MO実装の為 pressしたkeycodeをストック
            for (k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {
              if (pressKeycodes[k] == 0xFF) {
                pressKeycodes[k] = keycode;
                pressKeycodeNum++;
                break;
              }
            }
            break;
          case 1: // Layer Tap(LT) MO
              currentLayer = switchLayer;
            break;
          default:
            break;
        }
      // release
      } else {
        // switch layer
        switch(func) {
          case 0:
            // pressKeycodesからreleaseされたものは省く
            for (k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {
              if (pressKeycodes[k] == keycode) {
                // layerが切り替わりで無意味なreleaseは避ける
                Keyboard.release(keycode);
                pressKeycodes[k] = 0xFF;
                pressKeycodeNum--;
                break;
              }
            }
            break;
          case 1: // layer Tap(LT), MO
            // layerが元に戻った場合はreleaseが行われていないキーはreleaseする
            for (k = 0; k < MAX_STOCK_KEYCODE_NUM; k++) {
              if (pressKeycodes[k] != 0xFF) {
                Keyboard.release(pressKeycodes[k]);
                pressKeycodes[k] = 0xFF;
                pressKeycodeNum--;
              }
            }
            currentLayer = baseLayer;
            break;
          default:
            break;
        }
      }
      beforeState[i][j] = currentState[i][j];
        // Serial.print("keyData=");
        // Serial.println(keyData);
        // Serial.print("func=");
        // Serial.println(func);
        // Serial.print("cLayer=");
        // Serial.println(switchLayer);
        // Serial.print("sLayer=");
        // Serial.println(currentLayer);
        // Serial.print("bLayer=");
        // Serial.println(beforeLayer);
        // Serial.print("keycode=");
        // Serial.println(keycode);
     //Mouse Mode
    } else {
      mouseXOrY = (readData & 0b01000000) >> 6;
      // X
      if (mouseXOrY == 0) {
        mouseMinusX = (readData & 0b00100000) >> 5;
        mouseDistanceX = readData & 0b00011111;
        readData = Serial1.read();
        mouseXOrY = (readData & 0b01000000) >> 6;
        if (mouseXOrY == 1) {
          mouseMinusY = (readData & 0b00100000) >> 5;
          mouseDistanceY = readData & 0b00011111;
          if (mouseMinusX == 0) {
            if (mouseMinusY == 0 ) {
              Mouse.move(mouseDistanceX, mouseDistanceY, 0);
            } else {
              Mouse.move(mouseDistanceX, (0 - mouseDistanceY), 0);
            }
          } else {
            if (mouseMinusY == 0 ) {
              Mouse.move((0 - mouseDistanceX), mouseDistanceY, 0);
            } else {
              Mouse.move((0 - mouseDistanceX), (0 - mouseDistanceY), 0);
            }
          }
        }
      }
    }
  }
  delay(10);
}

int readAxis(int thisAxis, bool thisReverse) {
  int reading = analogRead(thisAxis);
  int distance;

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);
  if (thisReverse == 0) {
    distance = reading - center;
  } else {
    distance = center - reading;
  }
  if ((distance <= 1) && (-1 <= distance)) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}

int makeMouseData(int currentDistance, byte xOrY) {
  byte mouseData;
  byte keyboardOrMouse = 0;
  byte minus = 0;
  byte distance;
  if (currentDistance < 0 ) {
    minus = 1;
    distance = 0 - currentDistance;
  } else {
    distance = currentDistance;
  }
  mouseData = keyboardOrMouse << 7 | xOrY << 6| minus << 5 | distance;
  return mouseData;
}
