#include "Keydefine.h"
#include <Keyboard.h>
#include "Mouse.h"

// Maxipad
const int inputNum = 6;
const int outputNum = 5;
const int inputPins[inputNum] =  {21, 5, 6, 20, 8, 9};
const int outputPins[outputNum] ={10, 16, 14, 15, 18};
const byte keyMap[outputNum*2][inputNum*2]  = {
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
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
byte mouseXOrY, mouseMinus, mouseDistance;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8E1);
  Keyboard.begin();
  // take control of the mouse:
  Mouse.begin();
  pinMode(mouseButton, INPUT_PULLUP);

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
          isPress = 1;
        } else {
          Keyboard.release(keyMap[i][j]);
          isPress = 0;
        }
        beforeState[i][j] = currentState[i][j];
        // convert 8bit data
        sendData = keyboardOrMouse << 7 | isPress << 6| i << 3 | j;
        Serial1.write(sendData);
        digitalWrite(17, HIGH);
      }
    }
    digitalWrite(outputPins[i], HIGH); // reset the outputPin to HIGH(5V)
  }

  // Mouse
  // read and scale the two axes:
  int xReading = readAxis(xAxis, xReverse);
  int yReading = readAxis(yAxis, yReverse);

  // if the mouse control state is active, move the mouse:
  Serial1.write(makeMouseData(xReading, 0));
  Serial1.write(makeMouseData(yReading, 1));
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
    keyboardOrMouse = isPress = col = row = mouseXOrY = mouseMinus = mouseDistance = 0;
    digitalWrite(17, HIGH);
    readData = Serial1.read();
    keyboardOrMouse = readData >> 7;
    if (keyboardOrMouse  == 1) {
      isPress = (readData & 0b01000000) >> 6;
      col = (readData & 0b00111000) >> 3;
      row = readData & 0b00000111;
      if (isPress == 1) {
        Keyboard.press(keyMap[outputNum+col][row]);
      }
      else {
        Keyboard.release(keyMap[outputNum+col][row]);
      }
     //Mouse Mode
    } else {
      mouseXOrY = (readData & 0b01000000) >> 6;
      mouseMinus = (readData & 0b00100000) >> 5;
      mouseDistance = readData & 0b00011111;
      if (mouseXOrY == 0) {
        if (mouseMinus == 0) {
          Mouse.move(mouseDistance, 0, 0);
        } else {
          Mouse.move((0 - mouseDistance), 0, 0);
        }
      } else {
        if (mouseMinus == 0) {
          Mouse.move(0, mouseDistance, 0);
        } else {
          Mouse.move(0, (0 - mouseDistance), 0);
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

int makeMouseData(int currentDistance, int xOrY) {
  byte mouseData;
  byte keyboardOrMouse = 0;
  byte minus = 0;
  unsigned int distance = currentDistance;
  if (currentDistance < 0 ) {
    minus = 1;
  }
  mouseData = keyboardOrMouse << 7 | xOrY << 6| minus << 5 | distance;
  return mouseData;
}
