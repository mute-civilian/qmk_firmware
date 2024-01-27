#pragma once
#include "mutecivilian.h"

enum userspace_custom_keycodes {
  SARCASM = SAFE_RANGE,
  KC_SECRET_1,
  KC_SECRET_2,
  KC_SECRET_3,
  KC_SECRET_4,
  KC_SECRET_5,
  KC_SECRET_6,
  KC_SECRET_7,
  KC_SECRET_8,
  KC_SECRET_9,
  KC_SECRET_10,
  KC_SECRET_END
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);
