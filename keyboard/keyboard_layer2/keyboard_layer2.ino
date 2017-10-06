#include "Keydefine.h"
#include <Keyboard.h>
#include "Mouse.h"

// LAYERS
#define BASE 0
#define UPPER 1
#define LOWER 2

//FUNCTIONS
#define FUNC_LT 1<<12

// FUNCTIONS MACRO
#define LT(layer,key) (unsigned int)(FUNC_LT | layer << 8 | key)

int currentLayer = 0;
int beforeLayer = 0;

#define mouseButton 7    // input pin for the mouse pushButton
bool currentMouseButtonStatus = HIGH;
bool beforeMouseButtonStatus = HIGH;

// Maxipad
const int inputNum = 6;
const int outputNum = 5;
const int inputPins[inputNum] =  {21, 5, 6, 20, 8, 9};
const int outputPins[outputNum] ={10, 16, 14, 15, 18};
const unsigned int keyMap[][outputNum*2][inputNum*2]  = {
  [BASE] = {
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T},
   {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
   {KC_ESC,  NONE,    KC_LALT, KC_LGUI,LT(UPPER, NONE), KC_SPC},

   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC},
   {KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT},
   {KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_QUOT},
   {KC_BSPC, LT(LOWER, NONE),  KC_LEFT, KC_DOWN,KC_UP,   KC_RGHT}
  },

  [UPPER] = {
   {_______, _______, _______, _______, _______, _______ },
   {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC },
   {_______, _______, _______, _______, _______, _______ },
   {_______, _______, _______, _______, _______, _______ },
   {_______, _______, _______, _______, _______, _______ },

   {_______, _______, _______, _______, _______, _______ },
   {KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS },
   {_______, _______, _______, _______, _______, _______ },
   {_______, _______, _______, _______, _______, KC_PIPE },
   {KC_DEL, _______, _______, _______, _______, _______ }
  },

  [LOWER] = {
   {_______, _______, _______, _______, _______, _______ },
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {_______, _______, _______, _______, _______, _______ },
   {_______, _______, _______, _______, _______, _______ },
   {_______, _______, _______, _______, _______, _______ },

   {_______, _______, _______, _______, _______, _______ },
   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {_______, _______, _______, _______, _______, _______ },
   {_______, _______, _______, _______, _______, KC_BSLS },
   {KC_DEL, _______, _______, _______, _______, _______ }
  }
};

void setup() {
  Serial.begin(9600);
  pinMode(mouseButton, INPUT_PULLUP);
  currentLayer = BASE;
}

void loop() {
  unsigned int keyData = keyMap[currentLayer][0][0];
  unsigned int func = keyData >> 12;
  unsigned int layer = (keyData & 0b0000111100000000) >> 8;
  unsigned int keycode = keyData & 0b0000000011111111;
  Serial.println(keyData);
//  Serial.print(":");
//  Serial.print(layer);
//  Serial.print(":");
//  Serial.println(keycode);

  switch(func) {
    case 0:
      break;
    case 1: // Layer Tap
      beforeLayer = currentLayer;
      currentLayer = layer;
      break;
    default:
      break;
  }
  Serial.print(currentLayer);
  Serial.print(":");
  Serial.println(beforeLayer);

  currentMouseButtonStatus = digitalRead(mouseButton);
  Serial.println(currentMouseButtonStatus);
  if (beforeMouseButtonStatus != currentMouseButtonStatus) {
    beforeMouseButtonStatus = currentMouseButtonStatus;
    if (currentMouseButtonStatus == LOW) {
      Serial.println(".press(MOUSE_LEFT)");
      currentLayer = 4;
      beforeLayer = 0;
    } else {
      Serial.println(".release(MOUSE_LEFT)");
      switch (func) {
        case 1: // Layer Tap
          currentLayer = beforeLayer;
          break;
        default:
          break;
      }
    }
  }
  Serial.print(currentLayer);
  Serial.print(":");
  Serial.println(beforeLayer);
  delay(1000);
}
