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

byte currentLayer = 0;
byte beforeLayer = 0;


#define outputNum 5
#define inputNum 6


// Maxipad
const int inputNum = 6;
const int outputNum = 5;
const int inputPins[inputNum] =  {21, 5, 6, 20, 8, 9};
const int outputPins[outputNum] ={10, 16, 14, 15, 18};
const byte keyMap[][outputNum*2][inputNum*2]  = {
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
   {KC_CIRC, KC_ARMP, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL },
   {_______, _______, _______, _______, _______, _______ },
   {_______, _______, _______, _______, _______, _______ },
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
   {_______, _______, _______, _______, _______, _______ },
   {KC_DEL, _______, _______, _______, _______, _______ }
  }
};


void setup() {
  Serial.begin(9600);
}

void loop() {
    printf("%d", keyMap[0][0][0]);
}