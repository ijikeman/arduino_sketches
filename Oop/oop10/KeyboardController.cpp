#include "KeyboardController.h"
#include "Keydefine.h"
#include "Keymap.h"
#include <Keyboard.h>
#include "Arduino.h"
#include "config.h"
#include "MatrixController.h"

const byte keyMap[ROW_NUM*2][COL_NUM]  = {
   {KC_GRV, KC_1,    KC_2,    KC_3,   KC_4,    KC_5},
   {KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T},
   {KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G},
   {KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B},
   {KC_ESC,  KC_RBRC,    KC_LALT,   KC_LGUI, KC_EQL, KC_SPC},

   {KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS},
   {KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC},
   {KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT},
   {KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_QUOT},
   {KC_BSPC, KC_BSLS,    KC_LEFT, KC_DOWN,KC_UP,   KC_RGHT}
};

KeyboardController::KeyboardController() {
    Keyboard.begin();
}

void KeyboardController::input(MatrixController *matrix) {
  Serial.print(keyMap[(*matrix).out][(*matrix).in]);
  if ((*matrix).pushPull) {
    Serial.println(" release");
     Keyboard.press(keyMap[(*matrix).out][(*matrix).in]);
  } else {
    Serial.println(" push");
     Keyboard.release(keyMap[(*matrix).out][(*matrix).in]);
  }
}
